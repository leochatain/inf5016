#include "veb_tree.h"
#include <cmath>

#include <iostream>

using std::unordered_map;
using std::unordered_set;

using namespace std;

namespace inf5016 {

VebTree::VebTree(const int u) {
  // u must be a power of 2.
  assert((u & (u-1)) == 0);

  this->head_ = create(u);
}

// Check whether a vertex is member of the tree.
bool VebTree::member(int val) {
  assert(head_ != NULL);
  assert(val >= 0);

  VebNode* node = head_;
  while (node->u >= 2) {
    if (val == node->min || val == node->max) {
      return true;
    }
    if (node->u == 2) {
      return false;
    }
    node = node->bottom[node->high(val)];
    val = node->low(val);
  }
}

void VebTree::push(const Edge& edge) {
  const int vert = edge.dest;
  const int cost = edge.cost;

  // Update maps with edge information.
  vert2dist_[vert] = cost;
  dist2verts_[cost].insert(vert);

  push_rec(head_, cost);
}

void VebTree::pop() {
  assert(!this->empty());

  const Edge& min_edge = this->top();
  const int vert = min_edge.dest;
  const int dist = min_edge.cost;

  // Remove this edge from the vert2dist_ map.
  // There is only one pair vert-dist.
  unordered_map<int, int>::iterator v2d_it = vert2dist_.find(vert);
  vert2dist_.erase(v2d_it);
  // Remove it from the dist2verts_ map.
  unordered_map<int, unordered_set<int> >::iterator d2v_it =
      dist2verts_.find(dist);
  unordered_set<int>::iterator it = d2v_it->second.find(vert);
  d2v_it->second.erase(it);
  if (d2v_it->second.empty()) {
    dist2verts_.erase(d2v_it);
  }

  del_rec(head_, min_edge.cost);
}

Edge VebTree::top() {
  assert(!empty());

  const int dist = head_->min;
  const int dest = *dist2verts_[dist].begin();
  return Edge(dest, dist);
}

void VebTree::update(const int vert, const int new_cost) {}

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

  if (u > 2) {
    // Create children
    for (int i = 0; i < node->bottom.size(); i++) {
      node->bottom[i] = create((int)sqrt(u));
    }
    // Create top
    node->top = create((int)sqrt(u));
  } else {
    node->top = NULL;
    node->bottom[0] = node->bottom[1] = NULL;
  }
  // Make subtree empty
  node->max = 0;
  node->min = 1;

  return node;
}

void VebTree::push_rec(VebNode* node, int val) {
  // Insert cost on the tree.
  if (this->empty()) {
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
  assert(val <= node->max && val >= node->min);

  if (node->min == node->max) { // only one element
    node->min = 1; node->max = 0;
  } else if (node->u == 2) { // base case
    if (val == 0) {
      node->min = 1;
    } else {
      node->min = 0;
    }
    node->max = node->min;
  } else {
    if (node->min == val) {
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

// Cleans a leaf. If node isn't a leaf, bad things will happen.
void VebTree::clean_leaf(VebNode* node) {
  // These pointers do not point to any structure, they represent the tree.
  node->top = NULL;
  node->bottom[0] = node->bottom[1] = NULL;
  // Make max < min.
  node->max = 0;
  node->min = 1;
}

}

