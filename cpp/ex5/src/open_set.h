#ifndef __OPEN_SET_H
#define __OPEN_SET_H

#include <vector>

#include "hash_function.h"
#include "util.h"

using std::vector;

class OpenSet {
 public:
  OpenSet(ll m, int probing, const int degree = 2);

  // Return whether could add the element.
  bool put(const ll key, int& steps);
  bool contains(const ll key, int& steps);

  inline int size() { return size_; }
  inline int get_probing() { return probing_; }
  inline int get_table_size() { return base_.size(); }

 private:
  vector<ll> base_;
  HashFunction* function_;
  // Probing and m must always be coprimes.
  int probing_;
  int size_;

  ll next_coprime(const ll m, const int probing);
};

#endif
