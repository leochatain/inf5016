#include "open_set.h"

#include <cassert>

using namespace std;

OpenSet::OpenSet(ll m, int probing, const int degree) {
  probing = probing % m; // ensure that probing is always smaller than m
  probing_ = probing;

  m = next_coprime(m, probing);
  base_.resize(m, -1);
  function_ = new HashFunction(m, degree);
  size_ = 0;
}

bool OpenSet::put(const ll key) {
  assert (key >= 0); // we only accept positive keys.

  if (size_ >= base_.size()) { // no more space left
    return false;
  }

  ll pos = function_->hash(key);
  // Because the size of the table and hops are coprimes, if the
  // occupancy is smaller than the size of the table, eventually the place
  // will be found.
  int hops = 0;
  while (base_[pos] != -1) {
    pos = (pos + probing_) % base_.size();

    assert(hops++ < base_.size());
  }

  base_[pos] = key;

  size_++;
  return true;
}

bool OpenSet::contains(const ll key) {
  ll pos = function_->hash(key);

  int hops = 0;
  while(base_[pos] != key) {
    pos = (pos + probing_) % base_.size();

    // We don't support deletion, so we can stop when we find an empty slot.
    if (base_[pos] == -1) {
      return false;
    }
    // Maybe we've searched all over already.
    if (hops++ > base_.size()) {
      return false;
    }
  }
  return true;
}

ll OpenSet::next_coprime(const ll m, const int probing) {
  if (probing == 1) {
    return m;
  }

  // Folowing Bertrands postulate, there's always a prime p such that
  // n < p < 2*p - 2
  for (int i = m; i < 2 * m; i++) {
    if (i % probing != 0) {
      return i;
    }
  }

  assert(false); // Mathematics don't work anymore...
}
