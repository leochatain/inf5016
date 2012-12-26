#ifndef __HASH_SET
#define __HASH_SET

#include <vector>
#include <list>

using std::list;
using std::vector;

typedef list<int>::const_iterator list_it;

class HashSet {
 public:
  HashSet(const int m);

  void put(const int key);
  void contains(const int key);
}

#endif
