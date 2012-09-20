#ifndef BINARY_HEAP_H_
#define BINARY_HEAP_H_

#include "graph.h"

#include <algorithm>
#include <functional>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <cassert>

namespace inf5016 {

// This is a Binary Heap of Edges.
class BinaryHeap {
  typedef std::vector<Edge>::iterator Iterator;

 public:
  BinaryHeap() { }

  // Inserts an element on the heap.
  void push(const Edge& val) {
    base_.push_back(val);

    // Update the index.
    index_[val.dest] = base_.size() - 1;

    bubble_up(base_.end() - 1);
  }

  // Queries the value of the top element of the heap.
  inline Edge& top() {
    return base_.front();
  }

  // Queries the value of the top element of the heap.
  inline Edge top() const {
    return (const Edge) base_.front();
  }

  // Removes the first element of the heap.
  void pop() {
    // Update indices
    index_[base_.back().dest] = 0;
    // Update heap
    base_.front() = base_.back();
    base_.pop_back();

    // Re-balance
    bubble_down(base_.begin());
  }

  // Updates the element vert with a new cost.
  void update(const int vert, const int new_cost) {
    if (index_.find(vert) == index_.end()) {
      return;
    }

    Iterator it = base_.begin() + index_[vert];

    assert(it->dest == vert);

    bool lesser = (new_cost < it->cost);
    it->cost = new_cost;

    if (lesser) {
      bubble_up(it);
    } else {
      bubble_down(it);
    }
  }

  // Returns whether the heap is empty or not.
  inline bool empty() const {
    return base_.empty();
  }

  // Returns the size of the heap.
  inline int size() const {
    return base_.size();
  }

  inline void clear() {
    base_.clear();
  }

  void dump() const {
    for (int i = 0; i < base_.size(); i++) {
      std::cout << "(" << base_[i].dest << ", " << base_[i].cost << ") ";
    }
    std::cout << std::endl;
  }

  void dump_index() const {
    std::unordered_map<int, int>::const_iterator it;
    for (it = index_.begin(); it != index_.end(); ++it) {
      std::cout << "(" << it->first << ", " << it->second << ")";
    } 
    std::cout << std::endl;
  }

 private:
  std::vector<Edge> base_;
  std::unordered_map<int, int> index_;

  // Heap navigation methods:

  Iterator parent(const Iterator& element) {
    if (element == base_.begin()) {
      return element;
    }

    return base_.begin() + ((pos(element) - 1) / 2);
  }

  Iterator left_child(const Iterator& element) {
    return min(base_.end(), base_.begin() + (pos(element) * 2 + 1));
  }

  Iterator right_child(const Iterator& element) {
    return min(base_.end(), base_.begin()
        + ((element - base_.begin()) * 2) + 2);
  }

  Iterator min_child(const Iterator& element) {
    Iterator left = left_child(element);
    Iterator right = right_child(element);

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

  void bubble_up(Iterator element) {
    Iterator dad = parent(element);
    while (element != base_.begin() && (*element < *dad)) {
      std::swap(*element, *dad);
      std::swap(index_[element->dest], index_[dad->dest]);
      element = dad;
      dad = parent(element);
    }
  }

  void bubble_down(Iterator element) {
    Iterator child = min_child(element);
    while (child != base_.end() && (*child < *element)) {
      std::swap(*element, *child);
      std::swap(index_[element->dest], index_[child->dest]);
      element = child;
      child = min_child(element);
    }
  }

  // Iterator translation helper methods.

  int pos(Iterator it) {
    return it - base_.begin();
  }
};

}
#endif
