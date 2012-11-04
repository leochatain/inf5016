#include "veb_tree.h"
#include <cmath>

namespace inf5016 {

VebTree::VebTree(const int u) {
  this->head_ = create(u);
}

// Check whether a vertex is member of the tree.
bool VebTree::member(const int vert) {
  int e = vert;
  int st, si;
  VebNode* node = head_;

  while (node->u > 2) {
    st = node->subtree(e);
    si = node->subindex(e);
    // member(T.bottom[subtree(e)], subindex(e))
    node = node->bottom[st];
    e = si;
  }
  return node->bottom[e];
}

void VebTree::push(const Edge& edge) {}

void VebTree::pop() {}

Edge& VebTree::top() {}
const Edge& VebTree::top() const {}

void VebTree::update(const int vert, const int new_cost) {}

int VebTree::size() {}

bool VebTree::empty() {
  return head_->min > head_->max;
}

void VebTree::clean() {
  clean_rec(head_);
}

// u is a power of 2
// we'll have u leaves on the tree
VebNode* VebTree::create(const int u) {
  assert(u >= 2);

  // Upper node
  VebNode* node = new VebNode(u);

  if (u > 2) {
    // Create children
    for (int i = 0; i < node->bottom.size(); i++) {
      node->bottom[i] = create(u/2);
    }
    // Create top
    node->top = create(u/2);
  } else {
    node->top = NULL;
    node->bottom[0] = node->bottom[1] = NULL;
  }

  return node;
}

// Recursive version of the clean.
void VebTree::clean_rec(VebNode* node) {
  if (node->u == 2) {
    node->top = NULL;
    node->bottom[0] = node->bottom[1] = NULL;
  } else {
    clean_rec(node->top);
    for (int i = 0; i < node->bottom.size(); i++) {
      clean_rec(node->bottom[i]);
    }
  }
}

}

