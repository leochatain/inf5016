#include "binary_heap_test.h"
#include "../src/binary_heap.h"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(BinaryHeapTest);

using namespace std;
using namespace inf5016;

bool comp(int a, int b) {
  return a < b;
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

  for (int i = 0; i < 100; i++) {
    // Push all numbers from 0 to 100 starting on 50.
    heap.push((i + 50) % 100);
  }
  CPPUNIT_ASSERT_EQUAL(100, heap.size());

  for (int i = 0; i < 100; i++) {
    CPPUNIT_ASSERT_EQUAL(100 - i, heap.size());
    CPPUNIT_ASSERT_EQUAL(i, heap.top());
    heap.pop();
  }
}

void BinaryHeapTest::test_update() {

}

