#include "binary_heap_test.h"
#include "../src/binary_heap.h"

#include <ctime>
#include <cstdlib>
#include <vector>
#include <iostream>

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(BinaryHeapTest);

using namespace std;
using namespace inf5016;

bool comp(int a, int b) {
  return a < b;
}

void shuffle(vector<int>& v) {
  srand((unsigned)time(0));

  for (int i = 0; i < v.size(); i++) {
    int rand_pos = rand() % v.size();
    swap(v[i], v[rand_pos]);
  }
}

void BinaryHeapTest::test_push() {
  BinaryHeap<int> heap(comp);
  CPPUNIT_ASSERT(heap.empty());

  heap.push(50);
  CPPUNIT_ASSERT(!heap.empty());
  CPPUNIT_ASSERT_EQUAL(1, heap.size());
  CPPUNIT_ASSERT_EQUAL(50, heap.top());

  heap.push(49);
  CPPUNIT_ASSERT_EQUAL(2, heap.size());
  CPPUNIT_ASSERT_EQUAL(49, heap.top());

  for (int i = 0; i < 1000; i++) {
    heap.push(100 + i);
  }
  CPPUNIT_ASSERT_EQUAL(1002, heap.size());
  CPPUNIT_ASSERT_EQUAL(49, heap.top());

  for (int i = 10; i >= 0; i--) {
    heap.push(i);
    CPPUNIT_ASSERT_EQUAL(i, heap.top());
  }
}

void BinaryHeapTest::test_pop() {
  BinaryHeap<int> heap(comp);
  const int sx = 100;

  vector<int> rvec(sx);
  for (int i = 0; i < sx; i++) {
    rvec[i] = i;
  }
  shuffle(rvec);

  for (int i = 0; i < sx; i++) {
    heap.push(rvec[i]);
  }
  CPPUNIT_ASSERT_EQUAL(sx, heap.size());

  for (int i = 0; i < sx; i++) {
    CPPUNIT_ASSERT_EQUAL(sx - i, heap.size());
    CPPUNIT_ASSERT_EQUAL(i, heap.top());
    heap.pop();
  }
}

void BinaryHeapTest::test_update() {
  BinaryHeap<int> heap(comp);

  const int sx = 100;
  const int delta = 1000;
  vector<int> rvec(sx);
  for (int i = 0; i < sx; i++) {
    rvec[i] = i + delta;
  }
  shuffle(rvec);

  for (int i = 0; i < sx; i++) {
    heap.push(rvec[i]);
  }
  CPPUNIT_ASSERT_EQUAL(sx, heap.size());
  CPPUNIT_ASSERT_EQUAL(delta, heap.top());

  for (int i = sx - 1; i >= 0; i--) {
    // Remove delta from each element, in order.
    heap.update(delta + i, i);
    CPPUNIT_ASSERT_EQUAL(i, heap.top());
  }

  for (int i = 0; i < sx-1; i++) {
    heap.update(i, delta + i);
    CPPUNIT_ASSERT_EQUAL(i + 1, heap.top());
  }
}

