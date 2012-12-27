#ifndef __OPEN_SET_H
#define __OPEN_SET_H

#include <vector>

#include "hash_function.h"
#include "util.h"

using std::vector;

class OpenSet {
 public:
  OpenSet(ll m, const int probing, const int degree = 2);

  // Return whether could add the element.
  bool put(const ll key);
  bool contains(const ll key);

  int size() {
    return size_;
  }

 private:
  vector<int> base_;
  HashFunction* function_;
  // Because we use a probing, m is always a prime (so it is co-prime with
  // probing.
  const int probing_;
  int size_;
};

#endif
