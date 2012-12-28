#include "open_set_test.h"
#include "../src/open_set.h"

#include <ctime>

CPPUNIT_TEST_SUITE_REGISTRATION(OpenSetTest);

#include <iostream>
using namespace std;
void OpenSetTest::test_set() {
  OpenSet set(64, 1);

  for (int i = 0; i < 64; i++) {
    CPPUNIT_ASSERT(!set.contains(i));
    CPPUNIT_ASSERT(set.put(i));
    CPPUNIT_ASSERT(set.contains(i));

    CPPUNIT_ASSERT(!set.put(123));
  }
}

void OpenSetTest::test_set_rand() {
  OpenSet set(64, 1);
  
  srand(0);
  for (int i = 0; i < 64; i++) {
    const int key = rand();
    set.put(key);
    CPPUNIT_ASSERT(set.contains(key));
  }
}

