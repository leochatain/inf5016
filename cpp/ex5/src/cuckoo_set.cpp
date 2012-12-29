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

/*
bool CuckooSet::put(ll key) {
  if (try_insert(key)) {
    return true;
  }

  // Start the cuckoo thing with f1_.
  ll cuckoo_key = key;
  ll cuckoo_pos = f1_->hash(cuckoo_key);
  ll kicked_key = base_[cuckoo_pos];
  ll other_kicked_pos = other_pos(kicked_key, cuckoo_key);
  // This is used to detect loops.
  const ll first_cuckoo_pos = cuckoo_pos;
  cout << "first " << first_cuckoo_pos << endl;

  cout << "ORIGINAL: " << endl;
  cout << "cuckoo_key " << cuckoo_key << endl;
  cout << "cuckoo_pos " << cuckoo_pos << endl;
  cout << "kicked_key " << kicked_key << endl;
  cout << "other_kicked_pos " << other_kicked_pos << endl;
  cout << "stuff on the other pos " << base_[other_kicked_pos];
  cout << endl;

  base_[cuckoo_pos] = cuckoo_key;

  while (base_[other_kicked_pos] != kicked_key) {
    // Kick it out.
    base_[cuckoo_pos] = cuckoo_key;

    // Update keys and pos'.
    const ll previous_key = cuckoo_key;
    cuckoo_key = kicked_key;
    cuckoo_pos = other_pos(cuckoo_key, previous_key);
    kicked_key = base_[cuckoo_pos];
    other_kicked_pos = f2_->hash(kicked_key);

    cout << "cuckoo_key " << cuckoo_key << endl;
    cout << "cuckoo_pos " << cuckoo_pos << endl;
    cout << "kicked_key " << kicked_key << endl;
    cout << "other_kicked_pos " << other_kicked_pos << endl;
    cout << endl;

    if (kicked_key == cuckoo_key) {
      cout << "NO PROBLEMO" << endl;
      return true;
    }

    if (cuckoo_pos == first_cuckoo_pos) {
      // Houston, we have a problem! Rebuild the hashes.
      //rehash(cuckoo_key);
      return false;
    }
  }
  return true;
}
*/

void CuckooSet::put(ll key) {
  put(key, base_);
}

void CuckooSet::put(ll key, vector<ll>& table) {
  const ll pos1 = f1_->hash(key);
  const ll pos2 = f2_->hash(key);
  // key is already in the table.
  if (table[pos1] == key || table[pos2] == key) {
    return;
  }

  int p = pos1;
  for (int i = 0; i < m_; i++) {
    if (table[p] == -1) {
      table[p] = key;
      return;
    }
    std::swap(key, table[p]);
    p = other_pos(key, table[p], table);
  }

  rehash(table);
  put(key, table);  
}

// Simply checks whether the key is in one of the positions.
bool CuckooSet::contains(const ll key) {
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

bool CuckooSet::try_insert(const ll key, const ll pos) {
  if (base_[pos] == -1) {
    base_[pos] = key;
    return true;
  }
  return false;
}

bool CuckooSet::try_insert(const ll key) {
  const ll pos1 = f1_->hash(key);
  const ll pos2 = f2_->hash(key);
  
  // Do this to avoid lazy evaluation.
  bool try1 = try_insert(key, pos1);
  bool try2 = try_insert(key, pos2);

  return try1 || try2;
}

ll CuckooSet::other_pos(const ll key, const ll previous,
    const vector<ll>& table) {
  const ll p1 = f1_->hash(key);
  const ll p2 = f2_->hash(key);
  return table[p1] == previous ? p2 : p1;
}

void CuckooSet::rehash(vector<ll>& table) {
  generate_hashes();
  vector<ll> new_table(table.size(), -1);

  for (int i = 0; i < table.size(); i++) {
    if (table[i] != -1) {
      put(table[i], new_table);
    }
  }
  // Manually copy table back.
  for (int i = 0; i < table.size(); i++) {
    table[i] = new_table[i];
  }
}
