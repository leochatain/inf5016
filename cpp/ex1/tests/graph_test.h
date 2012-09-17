#ifndef GRAPH_TEST_H_
#define GRAPH_TEST_H_

#include <cppunit/extensions/HelperMacros.h>

class GraphTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(GraphTest);
  CPPUNIT_TEST(test_put);
  CPPUNIT_TEST_SUITE_END();

 public:
  void test_put();
};

#endif
