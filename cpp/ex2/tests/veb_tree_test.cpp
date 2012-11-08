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
  const int size = 16;

  VebTree tree(size);
  CPPUNIT_ASSERT(tree.empty());
  CPPUNIT_ASSERT_EQUAL((int) sqrt(size), (int) tree.head_->bottom.size());
}

void VebTreeTest::test_push_order() {
  const int size = 16;
  VebTree heap(size);
  CPPUNIT_ASSERT(heap.empty());

  heap.push(edge(2));
  CPPUNIT_ASSERT_EQUAL(heap.size(), 1);
  CPPUNIT_ASSERT_EQUAL(2, heap.top().cost);
  heap.push(edge(3));
  CPPUNIT_ASSERT_EQUAL(heap.size(), 2);
  CPPUNIT_ASSERT_EQUAL(2, heap.top().cost);
  heap.push(edge(4));
  CPPUNIT_ASSERT_EQUAL(heap.size(), 3);
  CPPUNIT_ASSERT_EQUAL(2, heap.top().cost);
  heap.push(edge(5));
  CPPUNIT_ASSERT_EQUAL(heap.size(), 4);
  CPPUNIT_ASSERT_EQUAL(2, heap.top().cost);
  heap.push(edge(7));
  CPPUNIT_ASSERT_EQUAL(heap.size(), 5);
  CPPUNIT_ASSERT_EQUAL(2, heap.top().cost);
  heap.push(edge(14));
  CPPUNIT_ASSERT_EQUAL(heap.size(), 6);
  CPPUNIT_ASSERT_EQUAL(2, heap.top().cost);
  heap.push(edge(15));
  CPPUNIT_ASSERT_EQUAL(heap.size(), 7);
  CPPUNIT_ASSERT_EQUAL(2, heap.top().cost);
}

void VebTreeTest::test_push_out_of_order() {
  const int size = 16;
  VebTree heap(size);
  CPPUNIT_ASSERT(heap.empty());

  heap.push(edge(15));
  CPPUNIT_ASSERT_EQUAL(heap.size(), 1);
  CPPUNIT_ASSERT_EQUAL(15, heap.top().cost);
  heap.push(edge(14));
  CPPUNIT_ASSERT_EQUAL(heap.size(), 2);
  CPPUNIT_ASSERT_EQUAL(14, heap.top().cost);
  heap.push(edge(7));
  CPPUNIT_ASSERT_EQUAL(heap.size(), 3);
  CPPUNIT_ASSERT_EQUAL(7, heap.top().cost);
  heap.push(edge(5));
  CPPUNIT_ASSERT_EQUAL(heap.size(), 4);
  CPPUNIT_ASSERT_EQUAL(5, heap.top().cost);
  heap.push(edge(4));
  CPPUNIT_ASSERT_EQUAL(heap.size(), 5);
  CPPUNIT_ASSERT_EQUAL(4, heap.top().cost);
  heap.push(edge(3));
  CPPUNIT_ASSERT_EQUAL(heap.size(), 6);
  CPPUNIT_ASSERT_EQUAL(3, heap.top().cost);
  heap.push(edge(2));
  CPPUNIT_ASSERT_EQUAL(heap.size(), 7);
  CPPUNIT_ASSERT_EQUAL(2, heap.top().cost);
}

void VebTreeTest::test_member() {
  const int size = 16;
  VebTree heap(size);


  heap.push(edge(7));
  heap.push(edge(5));
  heap.push(edge(4));
  heap.push(edge(14));
  heap.push(edge(3));
  heap.push(edge(15));
  heap.push(edge(2));

  CPPUNIT_ASSERT(heap.member(4));
  CPPUNIT_ASSERT(heap.member(14));
  CPPUNIT_ASSERT(heap.member(3));
  CPPUNIT_ASSERT(heap.member(15));
  CPPUNIT_ASSERT(heap.member(2));
  CPPUNIT_ASSERT(heap.member(7));
  CPPUNIT_ASSERT(heap.member(5));
}

void VebTreeTest::test_pop() {
  /*const int size = 16;
  VebTree heap(size);
  CPPUNIT_ASSERT(heap.empty());

  heap.push(edge(2));
  heap.push(edge(3));
  heap.push(edge(4));
  heap.push(edge(5));
  heap.push(edge(7));
  heap.push(edge(14));
  heap.push(edge(15));

  CPPUNIT_ASSERT_EQUAL(2, heap.top().cost);
  heap.pop();
  CPPUNIT_ASSERT_EQUAL(3, heap.top().cost);
  cout << "ONE" << endl;
  heap.pop();
  CPPUNIT_ASSERT_EQUAL(4, heap.top().cost);
  cout << "TWO" << endl;
  heap.pop();
  CPPUNIT_ASSERT_EQUAL(5, heap.top().cost);
  cout << "THREE" << endl;
  heap.pop();
  CPPUNIT_ASSERT_EQUAL(7, heap.top().cost);
  heap.pop();
  CPPUNIT_ASSERT_EQUAL(14, heap.top().cost);
  heap.pop();
  CPPUNIT_ASSERT_EQUAL(15, heap.top().cost);
  heap.pop();
  CPPUNIT_ASSERT(heap.empty());*/
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

