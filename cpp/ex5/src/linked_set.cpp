#include "linked_set.h"
#include "util.h"

#include <ctime>
#include <cassert>

using namespace std;

LinkedSet::LinkedSet(const int m) {
  base_.resize(m);
  P = next_prime(m);

  // Hash function parameters.
  srand(time(0));
  h_a = rand();
  h_b = rand();
}

// Key is simpley added to the back of the list.
void LinkedSet::put(const int key) {
  const int pos = hash(key);
  assert(pos < base_.size());

  base_[pos].push_back(key);
}

bool LinkedSet::contains(const int key) {
  const int pos = hash(key);
  assert(pos < base_.size());

  const list<int>& elements = base_[pos];
  for (list_it it = elements.begin(); it != elements.end(); it++) {
    if (*it == key)
      return true;
  }

  return false;
}

int LinkedSet::hash(const int key) {
  const int a = (key * h_a) % P;
  return ((a + h_b) % P) % base_.size();
}
