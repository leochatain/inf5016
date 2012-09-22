#include "binary_heap.h"

namespace inf5016 {

void BinaryHeap::push(const Edge& val) {
  base_.push_back(val);

  // Update the index.
  index_[val.dest] = base_.size() - 1;

  bubble_up(base_.end() - 1);
}

// Removes the first element of the heap.
void BinaryHeap::pop() {
  // Update indices
  index_[base_.back().dest] = 0;
  // Update heap
  base_.front() = base_.back();
  base_.pop_back();

  // Re-balance
  bubble_down(base_.begin());
}

// Updates the element vert with a new cost.
void BinaryHeap::update(const int vert, const int new_cost) {
  if (index_.find(vert) == index_.end()) {
    return;
  }

  BinaryHeap::It it = base_.begin() + index_[vert];

  assert(it->dest == vert);

  bool lesser = (new_cost < it->cost);
  it->cost = new_cost;

  if (lesser) {
    bubble_up(it);
  } else {
    bubble_down(it);
  }
}

void BinaryHeap::dump() const {
  for (int i = 0; i < base_.size(); i++) {
    std::cout << "(" << base_[i].dest << ", " << base_[i].cost << ") ";
  }
  std::cout << std::endl;
}

void BinaryHeap::dump_index() const {
  std::unordered_map<int, int>::const_iterator it;
  for (it = index_.begin(); it != index_.end(); ++it) {
    std::cout << "(" << it->first << ", " << it->second << ")";
  } 
  std::cout << std::endl;
}


BinaryHeap::It BinaryHeap::parent(const BinaryHeap::It& element) {
  if (element == base_.begin()) {
    return element;
  }

  return base_.begin() + ((pos(element) - 1) / 2);
}

BinaryHeap::It BinaryHeap::left_child(const BinaryHeap::It& element) {
  return min(base_.end(), base_.begin() + (pos(element) * 2 + 1));
}

BinaryHeap::It BinaryHeap::right_child(const BinaryHeap::It& element) {
  return min(base_.end(), base_.begin()
      + ((element - base_.begin()) * 2) + 2);
}

BinaryHeap::It BinaryHeap::min_child(const BinaryHeap::It& element) {
  BinaryHeap::It left = left_child(element);
  BinaryHeap::It right = right_child(element);

  if (left == base_.end() && right == base_.end()) {
    return base_.end();
  }
  if (right == base_.end()) {
    return left;
  } else {
    return (*left < *right) ? left : right;
  }
}

// Bubble up and down methods.

void BinaryHeap::bubble_up(BinaryHeap::It element) {
  BinaryHeap::It dad = parent(element);
  while (element != base_.begin() && (*element < *dad)) {
    std::swap(*element, *dad);
    std::swap(index_[element->dest], index_[dad->dest]);
    element = dad;
    dad = parent(element);
  }
}

void BinaryHeap::bubble_down(BinaryHeap::It element) {
  BinaryHeap::It child = min_child(element);
  while (child != base_.end() && (*child < *element)) {
    std::swap(*element, *child);
    std::swap(index_[element->dest], index_[child->dest]);
    element = child;
    child = min_child(element);
  }
}

}
