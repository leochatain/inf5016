#include "veb_tree_test.h"
#include "../src/veb_tree.h"
#include "../../ex1/src/graph.h"

#include <ctime>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <cmath>
#include <unordered_map>
#include <unordered_set>

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

void VebTreeTest::test_push_not_power() {
  // 8 is not a power of a power.
  VebTree heap(8);

  heap.push(edge(3));
  heap.push(edge(0));
  heap.push(edge(4));
  heap.push(edge(7));

  CPPUNIT_ASSERT_EQUAL(4, heap.size());

  CPPUNIT_ASSERT_EQUAL(0, heap.top().cost);
  heap.pop();
  CPPUNIT_ASSERT_EQUAL(3, heap.top().cost);
  heap.pop();
  CPPUNIT_ASSERT_EQUAL(4, heap.top().cost);
  heap.pop();
  CPPUNIT_ASSERT_EQUAL(7, heap.top().cost);
  heap.pop();
  CPPUNIT_ASSERT(heap.empty());
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

  CPPUNIT_ASSERT(!heap.member(0));
  CPPUNIT_ASSERT(!heap.member(1));
  CPPUNIT_ASSERT(!heap.member(6));
  CPPUNIT_ASSERT(!heap.member(8));
  CPPUNIT_ASSERT(!heap.member(9));
  CPPUNIT_ASSERT(!heap.member(10));
  CPPUNIT_ASSERT(!heap.member(11));
  CPPUNIT_ASSERT(!heap.member(12));
  CPPUNIT_ASSERT(!heap.member(13));
}

void VebTreeTest::test_pop() {
  const int size = 16;
  VebTree heap(size);
  CPPUNIT_ASSERT(heap.empty());

  heap.push(edge(2));
  heap.push(edge(3));
  heap.push(edge(4));
  heap.push(edge(5));
  heap.push(edge(7));
  heap.push(edge(14));
  heap.push(edge(15));

  CPPUNIT_ASSERT(heap.member(4));
  CPPUNIT_ASSERT(heap.member(14));
  CPPUNIT_ASSERT(heap.member(3));
  CPPUNIT_ASSERT(heap.member(15));
  CPPUNIT_ASSERT(heap.member(2));
  CPPUNIT_ASSERT(heap.member(7));
  CPPUNIT_ASSERT(heap.member(5));
  CPPUNIT_ASSERT_EQUAL(2, heap.top().cost);
  heap.pop();
  CPPUNIT_ASSERT(!heap.member(2));

  CPPUNIT_ASSERT(heap.member(4));
  CPPUNIT_ASSERT(heap.member(14));
  CPPUNIT_ASSERT(heap.member(3));
  CPPUNIT_ASSERT(heap.member(15));
  CPPUNIT_ASSERT(heap.member(7));
  CPPUNIT_ASSERT(heap.member(5));
  CPPUNIT_ASSERT_EQUAL(3, heap.top().cost);
  heap.pop();
  CPPUNIT_ASSERT(!heap.member(3));

  CPPUNIT_ASSERT(heap.member(4));
  CPPUNIT_ASSERT(heap.member(14));
  CPPUNIT_ASSERT(heap.member(15));
  CPPUNIT_ASSERT(heap.member(7));
  CPPUNIT_ASSERT(heap.member(5));
  CPPUNIT_ASSERT_EQUAL(4, heap.top().cost);
  heap.pop();
  CPPUNIT_ASSERT(!heap.member(4));

  CPPUNIT_ASSERT(heap.member(14));
  CPPUNIT_ASSERT(heap.member(15));
  CPPUNIT_ASSERT(heap.member(7));
  CPPUNIT_ASSERT(heap.member(5));
  CPPUNIT_ASSERT_EQUAL(5, heap.top().cost);
  heap.pop();
  CPPUNIT_ASSERT(!heap.member(5));

  CPPUNIT_ASSERT(heap.member(14));
  CPPUNIT_ASSERT(heap.member(15));
  CPPUNIT_ASSERT(heap.member(7));
  CPPUNIT_ASSERT_EQUAL(7, heap.top().cost);
  heap.pop();
  CPPUNIT_ASSERT(!heap.member(7));

  CPPUNIT_ASSERT_EQUAL(14, heap.top().cost);
  heap.pop();
  CPPUNIT_ASSERT(!heap.member(14));

  CPPUNIT_ASSERT_EQUAL(15, heap.top().cost);
  heap.pop();

  CPPUNIT_ASSERT(heap.empty());
}

void VebTreeTest::test_pop2() {
  VebTree heap(16);

  // Base case
  heap.push(edge(0));
  CPPUNIT_ASSERT_EQUAL(1, heap.size());

  CPPUNIT_ASSERT_EQUAL(0, heap.top().cost);
  heap.pop();
  CPPUNIT_ASSERT_EQUAL(0, heap.size());
  CPPUNIT_ASSERT(heap.empty());

  // Fill one cluster
  heap.push(edge(0));
  heap.push(edge(1));
  CPPUNIT_ASSERT_EQUAL(2, heap.size());
  CPPUNIT_ASSERT_EQUAL(0, heap.top().cost);
  heap.pop();
  CPPUNIT_ASSERT_EQUAL(1, heap.top().cost);

  // Fill two clusters
  heap.push(edge(0));
  heap.push(edge(2));
  heap.push(edge(3));

  CPPUNIT_ASSERT_EQUAL(4, heap.size());
  CPPUNIT_ASSERT_EQUAL(0, heap.top().cost);
  heap.pop();
  CPPUNIT_ASSERT_EQUAL(3, heap.size());
  CPPUNIT_ASSERT_EQUAL(1, heap.top().cost);
}

void VebTreeTest::test_maps() {
  VebTree heap(4);

  heap.push(Edge(5, 1));
  heap.push(Edge(4, 1));
  heap.push(Edge(6, 1));

  CPPUNIT_ASSERT(heap.vert2dist_.find(4) != heap.vert2dist_.end());
  CPPUNIT_ASSERT(heap.vert2dist_.find(5) != heap.vert2dist_.end());
  CPPUNIT_ASSERT(heap.vert2dist_.find(6) != heap.vert2dist_.end());

  int same_distance = heap.dist2verts_[1].size();
  CPPUNIT_ASSERT_EQUAL(3, same_distance);

  // Check that the size is correct.
  CPPUNIT_ASSERT_EQUAL(3, heap.size());

  // Now let's pop some elements out.
  const Edge& e = heap.top();
  CPPUNIT_ASSERT_EQUAL(1, e.cost);
  CPPUNIT_ASSERT_EQUAL(4, e.dest);

  heap.pop();
  CPPUNIT_ASSERT(heap.vert2dist_.find(4) == heap.vert2dist_.end());
  same_distance = heap.dist2verts_[1].size();
  CPPUNIT_ASSERT_EQUAL(2, same_distance);

  // Check that the size is still correct.
  CPPUNIT_ASSERT_EQUAL(2, heap.size());

  const Edge& e2 = heap.top();
  CPPUNIT_ASSERT_EQUAL(1, e2.cost);
  CPPUNIT_ASSERT_EQUAL(5, e2.dest);
  heap.pop();
  CPPUNIT_ASSERT(heap.vert2dist_.find(5) == heap.vert2dist_.end());

  same_distance = heap.dist2verts_[1].size();
  CPPUNIT_ASSERT_EQUAL(1, same_distance);
}

void VebTreeTest::test_update() {
  VebTree heap(16);

  heap.push(edge(2));
  heap.push(edge(3));
  heap.push(edge(4));
  heap.push(edge(5));
  heap.push(edge(6));

  CPPUNIT_ASSERT_EQUAL(2, heap.top().cost);
  heap.update(2, 7);
  CPPUNIT_ASSERT_EQUAL(3, heap.top().cost);
  heap.update(3, 8);
  CPPUNIT_ASSERT_EQUAL(4, heap.top().cost);
  heap.update(4, 9);
  CPPUNIT_ASSERT_EQUAL(5, heap.top().cost);
  heap.update(5, 10);
  CPPUNIT_ASSERT_EQUAL(6, heap.top().cost);
  heap.update(6, 11);
  CPPUNIT_ASSERT_EQUAL(2, heap.top().dest);
  CPPUNIT_ASSERT_EQUAL(7, heap.top().cost);

  heap.update(2, 8);
  CPPUNIT_ASSERT_EQUAL(2, heap.top().dest);
  CPPUNIT_ASSERT_EQUAL(8, heap.top().cost);
  heap.pop();
  CPPUNIT_ASSERT_EQUAL(3, heap.top().dest);
  CPPUNIT_ASSERT_EQUAL(8, heap.top().cost);
}

void VebTreeTest::test_push_pop() {
  VebTree heap(1024);
  for (int i = 1023; i >= 0; i--) {
    heap.push(edge(i));
    CPPUNIT_ASSERT_EQUAL(i, heap.top().cost);
  }
  for (int i = 0; i < 1023; i++) {
    heap.pop();
    CPPUNIT_ASSERT_EQUAL(i+1, heap.top().cost);
  }
  heap.pop();
  CPPUNIT_ASSERT(heap.empty());
}

