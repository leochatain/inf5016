#ifndef __CUCKOO_SET_TEST
#define __CUCKOO_SET_TEST

#include <cppunit/extensions/HelperMacros.h>

class CuckooSetTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(CuckooSetTest);
  //CPPUNIT_TEST(test_set);
  CPPUNIT_TEST(test_set_rand);
  CPPUNIT_TEST_SUITE_END();

 public:
  void test_set();
  void test_set_rand();

};

#endif
