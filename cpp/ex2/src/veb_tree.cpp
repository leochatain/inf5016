#include "veb_tree.h"

namespace inf5016 {

VebTree::VebTree() {}

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

void VebTree::clean() {}

}

