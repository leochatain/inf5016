#ifndef __LINKED_SET
#define __LINKED_SET

#include <list>
#include <vector>

using std::list;
using std::vector;

class LinkedSet {
 public:
  LinkedSet(const int m);

  void put(const int key);
  bool contains(const int key);

 private:
  vector<list<int> > base_; 

  // Big prime smaller than 32-bit integer.
  const int P = 1 << 31 - 1;
};

#endif
