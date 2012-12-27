#include "hash_set.h"

#include <cassert>

HashSet::HashSet(const ll m, const int degree) {
  base_.resize(m);
  function_ = new HashFunction(m, degree);
}
