#ifndef __LINKED_SET
#define __LINKED_SET

#include "hash_set.h"

class LinkedSet : public HashSet {
 public:
  LinkedSet(const ll m, const int degree=2);

  virtual void put(const ll key);
  virtual bool contains(const ll key);
};

#endif
