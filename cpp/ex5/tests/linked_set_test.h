#ifndef __LINKED_SET_TEST
#define __LINKED_SET_TEST

#include <cppunit/extensions/HelperMacros.h>

class LinkedSetTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(LinkedSetTest);
  CPPUNIT_TEST(test_set);
  CPPUNIT_TEST_SUITE_END();

 public:
  void test_set();
};

#endif
