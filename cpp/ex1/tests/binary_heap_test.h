#ifndef BINARY_HEAP_TEST_
#define BINARY_HEAP_TEST_

#include <cppunit/extensions/HelperMacros.h>

class BinaryHeapTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(BinaryHeapTest);
  CPPUNIT_TEST(test_push);
  CPPUNIT_TEST(test_pop);
  CPPUNIT_TEST(test_update);
  CPPUNIT_TEST_SUITE_END();

 public:
  void test_push();
  void test_pop();
  void test_update();

 private:
};

#endif
