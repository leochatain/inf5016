#ifndef __LINKED_SET
#define __LINKED_SET

#include <list>
#include <vector>

using std::list;
using std::vector;

typedef list<int>::const_iterator list_it;

class LinkedSet {
 public:
  LinkedSet(const int m);

  void put(const int key);
  bool contains(const int key);

 private:
  // Base table.
  vector<list<int> > base_; 

  // Big prime smaller than 32-bit integer.
  int P;
  // Hash function parameters.
  int h_a;
  int h_b;

  // Gives a hash for a key.
  int hash(const int key);
};

#endif
