#ifndef __LINKED_SET
#define __LINKED_SET

#include <list>
#include <vector>

#include "hash_function.h"
#include "util.h"

using std::list;
using std::vector;

typedef list<ll>::const_iterator list_it;

class LinkedSet {
 public:
  LinkedSet(const ll m);

  void put(const ll key);
  bool contains(const ll key);

 private:
  // Base table.
  vector<list<ll> > base_; 

  HashFunction* function_;

};

#endif
