#include "hash_set.h"

#include <cassert>

HashSet::HashSet(const ll m, const int degree) {
  base_.resize(m);
  function_ = new HashFunction(m, degree);
}

void HashSet::put(const ll key) {
  assert(false);
}

bool HashSet::contains(const ll key) {
  assert(false);
}
