#include "cuckoo_set_test.h"
#include "../src/cuckoo_set.h"

#include <ctime>

CPPUNIT_TEST_SUITE_REGISTRATION(CuckooSetTest);

void CuckooSetTest::test_set() {
  const int size = 1280;
  CuckooSet set(size);

  for (int i = 0; i < size; i++) {
    CPPUNIT_ASSERT(!set.contains(i));
    set.put(i);
    CPPUNIT_ASSERT(set.contains(i));
  }
}

#include <iostream>
using namespace std;
void CuckooSetTest::test_set_rand() {
  const int size = 1280;
  CuckooSet set(size);
  
  srand(0);
  for (int i = 0; i < size; i++) {
    const int key = rand();
    set.put(key);
    CPPUNIT_ASSERT(set.contains(key));
  }
}
