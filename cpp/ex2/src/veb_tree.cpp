#include "veb_tree.h"
#include <cmath>

#include <iostream>

using std::unordered_map;
using std::unordered_set;

using namespace std;

namespace inf5016 {

int upper_sqrt(const int u) {
  const int lg = (int) log2(u);
  const int exp = (int) ceil(lg / 2.);
  return 1 << exp;
}

int lower_sqrt(const int u) {
  const int lg = (int) log2(u);
  const int exp = lg / 2;
  return 1 << exp;
}


VebTree::VebTree(const int u) {
  // u must be a power of 2.
  assert((u & (u-1)) == 0);

  this->head_ = create(u);
}

// Check whether a vertex is member of the tree.
bool VebTree::member(int val) {
  assert(head_ != NULL);
  assert(val >= 0 && val < head_->u);

  return member_rec(head_, val);
}

void VebTree::push(const Edge& edge) {
  const int vert = edge.dest;
  const int cost = edge.cost;

  // Update maps with edge information.
  vert2dist_[vert] = cost;
  // Check whether or not we must insert this element on the tree.
  bool must_insert = dist2verts_.find(cost) == dist2verts_.end();
  dist2verts_[cost].insert(vert);

  if (must_insert) {
    push_rec(head_, cost);
  }
}

void VebTree::pop() {
  assert(!this->empty());

  const Edge& min_edge = this->top();
  const int vert = min_edge.dest;
  const int dist = min_edge.cost;

  // Delete from maps
  del_from_maps(vert, dist);

  // Check whether to delete the dist from the tree.
  if (dist2verts_.find(dist) == dist2verts_.end()) {
    del_rec(head_, dist);
  }
}

Edge VebTree::top() {
  assert(!empty());

  const int dist = head_->min;
  const int dest = *dist2verts_[dist].begin();
  return Edge(dest, dist);
}

void VebTree::update(const int vert, const int new_cost) {
  // Remove old entry from map.
  const int old_cost = vert2dist_[vert];
  del_from_maps(vert, old_cost);
  del_rec(head_, old_cost);

  // Add new entry to map.
  push(Edge(vert, new_cost));
}

int VebTree::size() {
  return vert2dist_.size();
}

bool VebTree::empty() {
  return head_->empty();
}

void VebTree::clean() {
  clean_rec(head_);
}

// TODO(leochatain) do not always create everything
// u is a power of 2
// we'll have u leaves on the tree
VebNode* VebTree::create(const int u) {
  assert(u >= 2);

  // Upper node
  VebNode* node = new VebNode(u);

  const int top_size = upper_sqrt(u);
  const int children_size = lower_sqrt(u);

  if (u > 2) {
    // Create children
    for (int i = 0; i < node->bottom.size(); i++) {
      node->bottom[i] = create(children_size);
    }
    // Create top
    node->top = create(top_size);
  } else {
    node->top = NULL;
  }
  // Make subtree empty
  node->max = 0;
  node->min = 1;

  return node;
}

void VebTree::push_rec(VebNode* node, int val) {
  assert(!member_rec(node, val));

  // Insert cost on the tree.
  if (node->empty()) {
    node->max = node->min = val;
    return;
  }

  if (val < node->min) {
    std::swap(node->min, val);
  }

  if (node->u > 2) {
    VebNode* cluster = node->bottom[node->high(val)];
    if (cluster->empty()) {
      push_rec(node->top, node->high(val));
      cluster->max = cluster->min = node->low(val);
    } else {
      push_rec(cluster, node->low(val));
    }
  }
  if (val > node->max) {
    node->max = val;
  }
}

// Assumes val is contained in node.
void VebTree::del_rec(VebNode* node, int val) {
  assert(!node->empty());
  assert(member_rec(node, val));
  assert(val <= node->max && val >= node->min);

  if (node->min == node->max) { // only one element
    node->min = 1; node->max = 0;
  } else if (node->u == 2) { // base case
    if (val == 0)
      node->min = 1;
    else
      node->min = 0;
    node->max = node->min;
  } else {
    // Promote someone else to min.
    if (node->min == val) {
      // First cluster is the cluster with the lowest element that is not val
      int first_cluster = node->top->min;
      val = node->index(first_cluster, node->bottom[first_cluster]->min);
      node->min = val;

    }
    VebNode* cluster = node->bottom[node->high(val)];
    del_rec(cluster, node->low(val));
    if (cluster->empty()) {
      del_rec(node->top, node->high(val));
      if (val == node->max) {
        int top_max = node->top->max;
        if (node->top->empty()) {
          node->max = node->min;
        } else {
          node->max = node->index(top_max, node->bottom[top_max]->max);
        }
      }
    } else if (val == node->max) {
      node->max = node->index(node->high(val),
          node->bottom[node->high(val)]->max);
    }
  }
}

// Recursive version of the clean.
void VebTree::clean_rec(VebNode* node) {
  // Node is a leaf.
  if (node->u == 2) {
    clean_leaf(node);
  } else {
    clean_rec(node->top);
    for (int i = 0; i < node->bottom.size(); i++) {
      clean_rec(node->bottom[i]);
    }
  }
}

// Recursive member function
bool VebTree::member_rec(VebNode* node, int val) {
  if (node->empty()) {
    return false;
  }
  if (val == node->min || val == node->max) {
    return true;
  }
  if (node->u == 2) {
    return false;
  }
  return member_rec(node->bottom[node->high(val)], node->low(val));
}

// Cleans a leaf. If node isn't a leaf, bad things will happen.
void VebTree::clean_leaf(VebNode* node) {
  assert(node->u == 2);

  // These pointers do not point to any structure, they represent the tree.
  node->top = NULL;
  node->bottom[0] = node->bottom[1] = NULL;
  // Make max < min.
  node->max = 0;
  node->min = 1;
}

void VebTree::print_rec(VebNode* node, int ind) {
  node->print(ind);
  if (node->u > 2) {
    for (int i = 0; i < ind; i++) cout << " ";
    cout << "TOP" << endl;
    print_rec(node->top,ind+4);
    for (int i = 0; i < ind; i++) cout << " ";
    cout << "BOTTOM" << endl;
    for (int i = 0; i < node->bottom.size(); i++) {
      print_rec(node->bottom[i], ind+4);
    }
  }
}

void VebTree::print_tree() {
  print_rec(head_, 0);
}

void VebTree::del_from_maps(const int vert, const int dist) {
  // Remove this edge from the vert2dist_ map.
  // There is only one pair vert-dist.
  unordered_map<int, int>::iterator v2d_it = vert2dist_.find(vert);
  assert(v2d_it != vert2dist_.end());
  vert2dist_.erase(v2d_it);

  // Remove it from the dist2verts_ map.
  unordered_map<int, unordered_set<int> >::iterator d2v_it;
  d2v_it = dist2verts_.find(dist);

  unordered_set<int>::iterator it = d2v_it->second.find(vert);
  assert(it != d2v_it->second.end());

  d2v_it->second.erase(it);

  if (d2v_it->second.empty()) {
    dist2verts_.erase(d2v_it);
  }
}

}

