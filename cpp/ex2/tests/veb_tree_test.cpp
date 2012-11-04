#include "veb_tree_test.h"
#include "../src/veb_tree.h"
#include "../../ex1/src/graph.h"

#include <ctime>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <cmath>

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(VebTreeTest);

using namespace std;
using namespace inf5016;

void shuffle(vector<int>& v) {
  srand(0);

  for (int i = 0; i < v.size(); i++) {
    int rand_pos = rand() % v.size();
    swap(v[i], v[rand_pos]);
  }
}

Edge edge(int num) {
  return Edge(num, num);
}

void VebTreeTest::test_create() {
  const int size = 1 << 4; // 16

  VebTree tree(size);
  CPPUNIT_ASSERT(tree.empty());
  CPPUNIT_ASSERT_EQUAL((int) sqrt(size), (int) tree.head_->bottom.size());
}

void VebTreeTest::test_push() {
  /*VebTree heap(U);
  CPPUNIT_ASSERT(heap.empty());

  heap.push(edge(50));
  CPPUNIT_ASSERT(!heap.empty());
  CPPUNIT_ASSERT_EQUAL(1, heap.size());
  CPPUNIT_ASSERT_EQUAL(50, heap.top().cost);

  heap.push(edge(49));
  CPPUNIT_ASSERT_EQUAL(2, heap.size());
  CPPUNIT_ASSERT_EQUAL(49, heap.top().cost);

  for (int i = 0; i < 1000; i++) {
    heap.push(edge(100 + i));
  }
  CPPUNIT_ASSERT_EQUAL(1002, heap.size());
  CPPUNIT_ASSERT_EQUAL(49, heap.top().cost);

  for (int i = 10; i >= 0; i--) {
    heap.push(edge(i));
    CPPUNIT_ASSERT_EQUAL(i, heap.top().cost);
  }*/
}

void VebTreeTest::test_pop() {
 /* VebTree heap(U);
  const int sx = 100;

  vector<int> rvec(sx);
  for (int i = 0; i < sx; i++) {
    rvec[i] = i;
  }
  shuffle(rvec);

  for (int i = 0; i < sx; i++) {
    heap.push(edge(rvec[i]));
  }
  CPPUNIT_ASSERT_EQUAL(sx, heap.size());

  for (int i = 0; i < sx; i++) {
    CPPUNIT_ASSERT_EQUAL(sx - i, heap.size());
    CPPUNIT_ASSERT_EQUAL(i, heap.top().cost);
    heap.pop();
  }*/
}

void VebTreeTest::test_update() {
  /*VebTree heap(U);

  const int sx = 10;
  const int delta = 100;
  vector<int> rvec(sx);
  for (int i = 0; i < sx; i++) {
    rvec[i] = i + delta;
  }
  shuffle(rvec);

  for (int i = 0; i < sx; i++) {
    heap.push(edge(rvec[i]));
  }
  CPPUNIT_ASSERT_EQUAL(sx, heap.size());
  CPPUNIT_ASSERT_EQUAL(delta, heap.top().cost);

  for (int i = sx - 1; i >= 0; i--) {
    // Remove delta from each element, in order.
    heap.update(delta + i, i);
    CPPUNIT_ASSERT_EQUAL(i, heap.top().cost);
  }

  for (int i = 0; i < sx-1; i++) {
    heap.update(delta + i, delta + i);
    CPPUNIT_ASSERT_EQUAL(i + 1, heap.top().cost);
  }*/
}

