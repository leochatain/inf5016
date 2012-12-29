#include "cuckoo_set.h"
#include <cassert>

#include <ctime>
#include <iostream>

using namespace std;

CuckooSet::CuckooSet(int m, const int degree)
    : degree_(degree) {
  // We need twice the elemnets because we insert in two positions of the
  // table.
  m = 2*m;

  m_= m;
  last_seed_ = time(0);

  base_.resize(m, -1);
  generate_hashes();
}

void CuckooSet::put(ll key, int& steps) {
  put(key, base_, steps);
}

void CuckooSet::put(ll key, vector<ll>& table, int& steps) {
  steps = 1;

  const ll pos1 = f1_->hash(key);
  const ll pos2 = f2_->hash(key);

  // key is already in the table.
  if (table[pos1] == key || table[pos2] == key) {
    return;
  }

  int p = pos1;
  for (int i = 0; i < m_; i++) {
    steps++;

    if (table[p] == -1) {
      table[p] = key;
      return;
    }
    std::swap(key, table[p]);
    p = other_pos(key, table[p], table);
  }

  rehash(table, steps);
  put(key, table, steps);  
}

// Simply checks whether the key is in one of the positions.
bool CuckooSet::contains(const ll key, int& steps) {
  steps = 1;

  const ll pos1 = f1_->hash(key);
  const ll pos2 = f2_->hash(key);

  return base_[pos1] == key || base_[pos2] == key;
}

HashFunction* CuckooSet::get_new_hash() {
  const int P = 1<<31 - 1;
  last_seed_ = (last_seed_ + 1) % P;
  return new HashFunction(m_, degree_, last_seed_);
}

// Generate hashes. Guarantees different hash functions by using differnet
// seeds to the hash generation.
void CuckooSet::generate_hashes() {
  f1_ = get_new_hash();
  f2_ = get_new_hash();
}

ll CuckooSet::other_pos(const ll key, const ll previous,
    const vector<ll>& table) {
  const ll p1 = f1_->hash(key);
  const ll p2 = f2_->hash(key);
  return table[p1] == previous ? p2 : p1;
}

void CuckooSet::rehash(vector<ll>& table, int& steps) {
  generate_hashes();
  vector<ll> new_table(table.size(), -1);

  for (int i = 0; i < table.size(); i++) {
    if (table[i] != -1) {
      put(table[i], new_table, steps);
    }
  }
  // Manually copy table back.
  for (int i = 0; i < table.size(); i++) {
    table[i] = new_table[i];
  }
}
