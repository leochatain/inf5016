#include "cuckoo_set.h"

using namespace std;

CuckooSet::CuckooSet(int m, const int degree)
    : degree_(degree), last_seed_(0) {
  // We need twice the elemnets because we insert in two positions of the
  // table.
  m = 2*m;

  base_.resize(m);
  generate_hashes(m, degree);
}

bool CuckooSet::put(const ll key) {
}

// Simply checks whether the key is in one of the positions.
bool CuckooSet::contains(const ll key) {
  ll pos1 = f1_->hash(key);
  ll pos2 = f2_->hash(key);

  return base_[pos1] == key || base_[pos2] == key;
}

// Generate hashes. Guarantees different hash functions by using differnet
// seeds to the hash generation.
void CuckooSet::generate_hashes(const ll m, const ll degree) {
  const int P = 1<<31 - 1;

  last_seed_ = (last_seed_ + 1) % P;
  f1_ = new HashFunction(m, degree);

  last_seed_ = (last_seed_ + 1) % P;
  f2_ = new HashFunction(m, degree);
}
