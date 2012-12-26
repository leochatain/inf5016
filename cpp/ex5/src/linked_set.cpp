#include "linked_set.h"

#include <cassert>

using namespace std;

LinkedSet::LinkedSet(const ll m) {
  base_.resize(m);

  // We only use degree 2 hash functions here.
  function_ = new HashFunction(m, 2);
}

// Key is simpley added to the back of the list.
void LinkedSet::put(const ll key) {
  const ll pos = function_->hash(key);
  assert(pos < base_.size());

  base_[pos].push_back(key);
}

bool LinkedSet::contains(const ll key) {
  const ll pos = function_->hash(key);
  assert(pos < base_.size());

  const list<ll>& elements = base_[pos];
  for (list_it it = elements.begin(); it != elements.end(); it++) {
    if (*it == key)
      return true;
  }

  return false;
}
