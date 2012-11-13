#ifndef VEB_TREE_TEST_
#define VEB_TREE_TEST_

#include <cppunit/extensions/HelperMacros.h>

class VebTreeTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(VebTreeTest);
  CPPUNIT_TEST(test_create);
  CPPUNIT_TEST(test_push_order);
  CPPUNIT_TEST(test_push_out_of_order);
  CPPUNIT_TEST(test_push_not_power);
  CPPUNIT_TEST(test_member);
  CPPUNIT_TEST(test_pop);
  CPPUNIT_TEST(test_pop2);
  CPPUNIT_TEST(test_maps);
  CPPUNIT_TEST(test_update);
  CPPUNIT_TEST(test_push_pop);
  CPPUNIT_TEST_SUITE_END();

 public:
  void test_create();
  void test_push_order();
  void test_push_out_of_order();
  void test_push_not_power();
  void test_member();
  void test_pop();
  void test_pop2();
  void test_maps();
  void test_update();
  void test_push_pop();
};

#endif
