#include <iostream>
#include <vector>

#include "binary_heap.h"

using std::cout;
using std::endl;

using namespace inf5016;

int main() {
  cout << "Hello World" << endl;

  inf5016::BinaryHeap<int, int> heap;

  heap.push(1, 2);
  heap.update(1, 2);
}
