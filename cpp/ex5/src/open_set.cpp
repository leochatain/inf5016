#include "open_set.h"

using namespace std;

OpenSet::OpenSet(ll m, const int probing, const int degree)
    : probing_(probing) {
  m = next_prime(m);
  base_.resize(m, -1);
  function_ = new HashFunction(m, degree);
}

bool OpenSet::put(const ll key) {
  if (size_ == base_.size()) { // no more space left
    return false;
  }

  ll pos = function_->hash(key);
  // Because the size of the table and hops are coprimes, if the
  // occupancy is smaller than the size of the table, eventually the place
  // will be found.
  while (base_[pos] == -1) {
    pos = (pos + probing_) % base_.size();
  }

  size_++;
  return true;
}

bool OpenSet::contains(const ll key) {
}
