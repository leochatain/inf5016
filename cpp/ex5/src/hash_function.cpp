#include "hash_function.h"

#include <ctime>
#include <iostream>

using namespace std;

HashFunction::HashFunction(const ll m, const int degree, int seed)
    : m_(m) {
  prime_ = 99991; // TODO(chatain) fix this.
  function_.resize(degree);

  if (seed == -1) {
    seed = time(0);
  } 
  srand(seed);
  for (int i = 0; i < degree; i++) {
    function_[i] = rand();
  }
}

ll HashFunction::hash(const ll key) {
  ll result = function_[0];
  ll base = key;

  for (int i = 1; i < function_.size(); i++) {
    result += mod(base * function_[i], prime_);
    base *= key;
  }

  return mod(result, m_);
}

void HashFunction::print() {
  for (int i = 0; i < function_.size(); i++) {
    cout << function_[i] <<  "  ";
  } cout << endl;
}
