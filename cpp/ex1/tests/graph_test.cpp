#include "graph_test.h"
#include "../src/graph.h"

#include <algorithm>
#include <vector>

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(GraphTest);

using namespace std;
using namespace inf5016;

void GraphTest::test_put() {
  Graph graph;

  graph.put(10, 100, 5);
  const vector<Edge>& list = graph[10];
  CPPUNIT_ASSERT(find(list.begin(), list.end(), Edge(100, 5)) != list.end());
  CPPUNIT_ASSERT_EQUAL(1, (int) list.size());
  CPPUNIT_ASSERT_EQUAL(11, graph.size());

  graph.put(1, 100, 5);
  const vector<Edge>& list2 = graph[1];
  CPPUNIT_ASSERT_EQUAL(11, graph.size());
  CPPUNIT_ASSERT(find(list2.begin(), list2.end(), Edge(100, 5)) != list2.end());
}
