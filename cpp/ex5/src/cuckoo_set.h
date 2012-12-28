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
  bool put(const ll key);
  bool contains(const ll key);

 private:
  vector<ll> base_;
  HashFunction* f1_;
  HashFunction* f2_;

  const int degree_;
  int last_seed_;

  void generate_hashes(const ll m, const ll degree);
};

#endif
