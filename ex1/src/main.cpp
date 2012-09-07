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
}
