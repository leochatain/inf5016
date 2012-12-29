#ifndef __HASH_FUNCTION
#define __HASH_FUNCTION

#include "util.h"

#include <vector>

using std::vector;

class HashFunction {
 public:
  HashFunction(const ll m, const int degree, int seed = -1);

  ll hash(const ll key);

  void print();
  
 private:
  vector<int> function_;

  const ll m_;
  ll prime_;
};

#endif
