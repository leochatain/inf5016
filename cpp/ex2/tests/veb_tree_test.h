#ifndef VEB_TREE_TEST_
#define VEB_TREE_TEST_

#include <cppunit/extensions/HelperMacros.h>

class VebTreeTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(VebTreeTest);
  CPPUNIT_TEST(test_create);
  CPPUNIT_TEST(test_push);
  CPPUNIT_TEST(test_pop);
  CPPUNIT_TEST(test_update);
  CPPUNIT_TEST_SUITE_END();

 public:
  void test_create();
  void test_push();
  void test_pop();
  void test_update();
};

#endif
