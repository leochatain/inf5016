#ifndef __CUCKOO_SET_H
#define __CUCKOO_SET_H

#include <vector>

#include "hash_function.h"
#include "util.h"

using std::vector;

class CuckooSet {
 public:
  CuckooSet(int m, const int degree=2);

  // Return true if we could add the element.
  // Return false if we had to rebuild the hash set.
  void put(ll key);
  void put(ll key, vector<ll>& base);
  bool contains(const ll key);

 private:
  vector<ll> base_;
  HashFunction* f1_;
  HashFunction* f2_;

  const int degree_;
  ll m_;
  int last_seed_;

  void generate_hashes();
  HashFunction* get_new_hash();

  ll other_pos(const ll key, const ll previous, const vector<ll>& table);

  void rehash(vector<ll>& table);
};

#endif
