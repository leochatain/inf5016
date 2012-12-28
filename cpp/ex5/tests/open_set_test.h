#ifndef __OPEN_SET_TEST_H
#define __OPEN_SET_TEST_H

#include <cppunit/extensions/HelperMacros.h>

class OpenSetTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(OpenSetTest);
  CPPUNIT_TEST(test_set);
  CPPUNIT_TEST(test_set_rand);
  CPPUNIT_TEST_SUITE_END();

 public:
  void test_set();
  void test_set_rand();
};

#endif
