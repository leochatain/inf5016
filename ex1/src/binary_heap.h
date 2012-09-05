#ifndef BINARY_HEAP_H_
#define BINARY_HEAP_H_

#include <algorithm>
#include <vector>

namespace inf5016 {

template <typename T, typename K>
class BinaryHeap {
 public:
  // Insert an element on the heap.
  void push(T element, K weight) {
    base_.push_back(std::make_pair(element, weight));
  }

  // Queries the value of the top element of the heap.
  std::pair<T, K> top() {
    return base_.front();
  }

  // Removes the first element of the heap.
  void pop();

  // Updates the instance T with a new weight.
  void update(T element, K weight) {
    typename std::vector<std::pair<T, K> >::iterator it =
        std::find(base_.begin(), base_.end(), std::make_pair(element, weight));
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
  std::vector<std::pair<T, K> > base_;
};

}
#endif
