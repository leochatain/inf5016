#include "veb_tree.h"
#include <cmath>

namespace inf5016 {

VebTree::VebTree(const int u) {
  this->head_ = create(u);
}

// Check whether a vertex is member of the tree.
bool VebTree::member(const int vert) {
  VebNode* node = head_;
  while (node->h != 2) {
  }
}
const bool VebTree::member(const int vert) const {}

void VebTree::push(const Edge& edge) {}

void VebTree::pop() {}

Edge& VebTree::top() {}
const Edge& VebTree::top() const {}

void VebTree::update(const int vert, const int new_cost) {}

int VebTree::size() {}

bool VebTree::empty() {}

void VebTree::clean() {
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

}

