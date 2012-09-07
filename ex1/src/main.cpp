#include <iostream>
#include <vector>

#include "binary_heap.h"

using std::cout;
using std::endl;

using namespace inf5016;

bool comp(int a, int b) {
  return a < b;
}

int main() {
  cout << "Hello World" << endl;

  inf5016::BinaryHeap<int> heap(comp);

  heap.push(12);
  heap.push(5);
  heap.push(3);
  heap.push(31);
  heap.push(13);

  heap.update(5, 153);
  heap.update(153, 0);
  while (!heap.empty()) {
    cout << heap.top() << endl;
    heap.pop();
  }
}
