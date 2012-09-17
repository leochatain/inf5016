#ifndef DIJKSTRA_TEST_H_
#define DIJKSTRA_TEST_H_

#include <cppunit/extensions/HelperMacros.h>

class DijkstraTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(DijkstraTest);
  CPPUNIT_TEST(test_foo);
  CPPUNIT_TEST_SUITE_END();

 public:
  void test_foo();
};

#endif
