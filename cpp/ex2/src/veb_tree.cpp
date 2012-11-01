#include "veb_tree.h"
#include <cmath>

namespace inf5016 {

VebTree::VebTree(const int u) {
  this->head_ = create(u);
}

// Check whether a vertex is member of the tree.
bool VebTree::member(const int vert) {
  int e = vert
  VebNode* node = head_;

  while (node->h > 2) {
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

int VebTree::size() {
  return (1 << head_.h);
}

bool VebTree::empty() {}

void VebTree::clean() {
  clean_rec(head_);
}

// u is a power of 2
// we'll have u leaves on the tree
VebNode* VebTree::create(const int u) {
  int h = log2(u) + 1;
  return create_rec(h);
}

// h is always a power of two
VebNode* VebTree::create_rec(const int h) {
  assert(h >= 2);

  // Upper node
  VebNode* node = new VebNode(h);

  if (h > 2) {
    // Create children
    for (int i = 0; i < node->bottom.size(); i++) {
      node->bottom[i] = create_rec(h/2);
    }
    // Create top
    node->top = create_rec(h/2);
  } else {
    node->top = NULL;
    node->bottom[0] = node->bottom[1] = NULL;
  }

  return node;
}

// Recursive version of the clean.
void clean_rec(VebNode* node) {
  if (node->h == 2) {
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

