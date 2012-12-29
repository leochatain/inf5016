#include "open_set.h"
#include "linked_set.h"
#include "cuckoo_set.h"

#include <iostream>
#include <ctime>

#define SIZE 10000
#define NUM_TESTS 100

using namespace std;

int main() {

  double put_time[3][SIZE];
  double lookup_time[3][SIZE];

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < SIZE; j++) {
      put_time[i][j] = 0;
      lookup_time[i][j] = 0;
    }
  }

  srand(0);

  for (int i = 0; i < NUM_TESTS; i++) {
    LinkedSet lset(SIZE);
    OpenSet oset(SIZE, 1);
    CuckooSet cset(SIZE);

    for (int i = 0; i < SIZE; i++) {
      int steps_l = 0;
      int steps_o = 0;
      int steps_c = 0;

      const int el = rand() % 10000;

      // Puts
      lset.put(el, steps_l);
      oset.put(el, steps_o);
      cset.put(el, steps_c);

      put_time[0][i] += steps_l;
      put_time[1][i] += steps_o;
      put_time[2][i] += steps_c;

      // Lookups
      steps_l = 0;
      steps_o = 0;
      steps_c = 0;

      lset.contains(el, steps_l);
      oset.contains(el, steps_o);
      cset.contains(el, steps_c);

      lookup_time[0][i] += steps_l;
      lookup_time[1][i] += steps_o;
      lookup_time[2][i] += steps_c;
    }
  }

  // Print put times
  for (int i = 0; i < SIZE; i++) {
    put_time[0][i] = put_time[0][i]/NUM_TESTS;
    put_time[1][i] = put_time[1][i]/NUM_TESTS;
    put_time[2][i] = put_time[2][i]/NUM_TESTS;

    cout << put_time[0][i]
        << " " << put_time[1][i]
        << " " << put_time[2][i] << endl;
  }

  // Print lookup times
  /*for (int i = 0; i < SIZE; i++) {
    lookup_time[0][i] = lookup_time[0][i]/NUM_TESTS;
    lookup_time[1][i] = lookup_time[1][i]/NUM_TESTS;
    lookup_time[2][i] = lookup_time[2][i]/NUM_TESTS;

    cout << lookup_time[0][i]
        << " " << lookup_time[1][i]
        << " " << lookup_time[2][i] << endl;
  }*/

}
