#ifndef __LINKED_SET_TEST
#define __LINKED_SET_TEST

#include <cppunit/extensions/HelperMacros.h>

class LinkedSetTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(LinkedSetTest);
  CPPUNIT_TEST(test_set);
  CPPUNIT_TEST(test_set2);
  CPPUNIT_TEST(test_set_rand);
  CPPUNIT_TEST_SUITE_END();

 public:
  void test_set();
  void test_set2();
  void test_set_rand();
};

#endif
