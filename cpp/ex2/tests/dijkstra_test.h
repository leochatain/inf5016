#ifndef DIJKSTRA_TEST_H_
#define DIJKSTRA_TEST_H_

#include <cppunit/extensions/HelperMacros.h>
#include <vector>
#include <iostream>

class DijkstraTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(DijkstraTest);
  CPPUNIT_TEST(test_all);
  CPPUNIT_TEST_SUITE_END();

 public:
  void setUp();

  void test_all();

 private:
  std::vector<std::string> files_;
};

#endif
