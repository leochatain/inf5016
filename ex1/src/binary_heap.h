#ifndef BINARY_HEAP_H_
#define BINARY_HEAP_H_

#include <algorithm>
#include <functional>
#include <vector>

namespace inf5016 {

template <typename T>
class BinaryHeap {
  typedef typename std::vector<T>::iterator iterator;

 public:

  // Constructs a binary heap using the default '<' operator as the default
  // comparer.
  BinaryHeap();

  // Constructs a binary heap using less as the function to compare elements.
  // Less should return true if the first element is strictly smaller than
  // the second.
  BinaryHeap(bool (&less)(const T, const T)) : less_(less) { }

  // Inserts an element on the heap.
  void push(const T& val) {
    base_.push_back(val);
    bubble_up(base_.end() - 1);
  }

  // Queries the value of the top element of the heap.
  inline T& top() {
    return base_.front();
  }

  // Queries the value of the top element of the heap.
  inline T& top() const {
    return base_.front();
  }

  // Removes the first element of the heap.
  void pop() {
    base_.front() = base_.back();
    base_.pop_back();
    bubble_down(base_.begin());
  }

  // Updates the element val with a new value.
  void update(const T& val, const T& new_val) {
    iterator it = std::find(base_.begin(), base_.end(), val);
    if (it == base_.end()) {
      return;
    }

    *it = new_val;

    if (less_(new_val, val)) {
      bubble_up(it);
    } else {
      bubble_down(it);
    }
  }

  // Returns whether the heap is empty or not.
  inline bool empty() {
    return base_.empty();
  }

  // Returns the size of the heap.
  inline int size() {
    return base_.size();
  }

 private:
  std::vector<T> base_;
  bool (&less_)(const T, const T);

  // Heap navigation methods:

  iterator parent(iterator element) {
    if (element == base_.begin()) {
      return element;
    }

    return base_.begin() + ((pos(element) - 1) / 2);
  }

  iterator left_child(iterator element) {
    return min(base_.end(), base_.begin() + (pos(element) * 2 + 1));
  }

  iterator right_child(iterator element) {
    return min(base_.end(), base_.begin()
        + ((element - base_.begin()) * 2) + 2);
  }

  iterator min_child(iterator element) {
    iterator left = left_child(element);
    iterator right = right_child(element);

    if (left == base_.end() && right == base_.end()) {
      return base_.end();
    }
    if (right == base_.end()) {
      return left;
    } else {
      return less_(*left, *right) ? left : right;
    }
  }

  // Bubble up and down methods.

  void bubble_up(iterator element) {
    iterator dad = parent(element);
    while (element != base_.begin() && less_(*element, *dad)) {
      std::swap(*element, *dad);
      element = dad;
      dad = parent(element);
    }
  }

  void bubble_down(iterator element) {
    iterator child = min_child(element);
    while (child != base_.end() && less_(*child, *element)) {
      std::swap(*element, *child);
      element = child;
      child = min_child(element);
    }
  }

  // Iterator translation helper methods.

  int pos(iterator it) {
    return it - base_.begin();
  }
};

}
#endif
