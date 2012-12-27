#ifndef __HASH_SET
#define __HASH_SET

#include <list>
#include <vector>

#include "hash_function.h"
#include "util.h"

using std::list;
using std::vector;

typedef list<ll>::const_iterator list_it;

class HashSet {
 public:
  HashSet(const ll m, const int degree = 2);

  virtual void put(const ll key);
  virtual bool contains(const ll key);

 protected:
  // Base table.
  vector<list<ll> > base_; 
  // Base hash function.
  HashFunction* function_;
};

#endif
