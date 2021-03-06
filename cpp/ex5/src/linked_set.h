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
  LinkedSet(const ll m, const int degree=2);

  void put(const ll key, int& steps);
  bool contains(const ll key, int& steps);

 private:
  // Base table.
  vector<list<ll> > base_;
  // Base hash function.
  HashFunction* function_;
};

#endif
