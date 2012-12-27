#include "linked_set_test.h"
#include "../src/linked_set.h"

#include <ctime>


CPPUNIT_TEST_SUITE_REGISTRATION(LinkedSetTest);

void LinkedSetTest::test_set() {
  LinkedSet set(64);

  for (int i = 0; i < 64; i++) {
    CPPUNIT_ASSERT(!set.contains(i));
    set.put(i);
    CPPUNIT_ASSERT(set.contains(i));
  }
}

void LinkedSetTest::test_set2() {
  LinkedSet set(64);

  for (int i = 0; i < 1024; i++) {
    CPPUNIT_ASSERT(!set.contains(i));
    set.put(i);
    CPPUNIT_ASSERT(set.contains(i));
  }
}

void LinkedSetTest::test_set_rand() {
  LinkedSet set(64);
  
  srand(0);
  for (int i = 0; i < 128; i++) {
    const int key = rand();
    set.put(key);
    CPPUNIT_ASSERT(set.contains(key));
  }
}

