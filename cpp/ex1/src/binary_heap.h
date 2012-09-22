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
  typedef std::vector<Edge>::iterator It;

 public:
  BinaryHeap() { }

  // Inserts an element on the heap.
  void push(const Edge& val);

  // Queries the value of the top element of the heap.
  inline Edge& top() {
    return base_.front();
  }

  // Queries the value of the top element of the heap.
  inline Edge top() const {
    return (const Edge) base_.front();
  }

  // Removes the first element of the heap.
  void pop();

  // Updates the element vert with a new cost.
  void update(const int vert, const int new_cost);

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

  void dump() const;

  void dump_index() const;

 private:
  std::vector<Edge> base_;
  std::unordered_map<int, int> index_;

  // Heap navigation methods:

  It parent(const It& element);

  It left_child(const It& element);

  It right_child(const It& element);

  It min_child(const It& element);

  // Bubble up and down methods.

  void bubble_up(It element);

  void bubble_down(It element);

  // Iterator translation helper methods.

  inline int pos(It it) {
    return it - base_.begin();
  }
};

}
#endif
