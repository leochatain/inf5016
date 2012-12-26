#include "hash_function.h"

#include <ctime>

HashFunction::HashFunction(const ll m, const int degree, int seed)
    : m_(m) {
  prime_ = 1 << 31 - 1; // TODO(chatain) fix this.
  function_.resize(degree);

  if (seed == -1) {
    seed = time(0);
  }

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
