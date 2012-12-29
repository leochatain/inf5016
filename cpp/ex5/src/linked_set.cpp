#include "linked_set.h"

using namespace std;

LinkedSet::LinkedSet(const ll m, const int degree) {
  base_.resize(m);
  function_ = new HashFunction(m, degree);
}

// Key is simpley added to the back of the list.
void LinkedSet::put(const ll key, int& steps) {
  steps = 1;
  const ll pos = function_->hash(key);
  base_[pos].push_back(key);
}

bool LinkedSet::contains(const ll key, int& steps) {
  steps = 1;
  const ll pos = function_->hash(key);

  const list<ll>& elements = base_[pos];
  for (list_it it = elements.begin(); it != elements.end(); it++) {
    steps++;
    if (*it == key) {
      return true;
    }
  }

  return false;
}
