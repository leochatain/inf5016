#include <cstddef>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cassert>
#include <cmath>

#include "graph.h"

namespace inf5016 {

// As described in CLRS.
struct VebNode {
  int min;
  int max;

	const int u;

	VebNode* top;
	std::vector<VebNode*> bottom;

  VebNode(const int size) : u(size) {
    assert(size >= 2);

		top = NULL;
		bottom.resize((int)ceil(sqrt(size)), NULL);
	}

  // Basic tree navigation functions
  int high(const int x) {
    return (int) (x / (int) (sqrt(u)));
  }
  int low (const int x) {
    return (int) x % (int) (sqrt(u));
  }
  int index(const int x, const int y) {
    return (int) x * floor(sqrt(u)) + y;
  }
};

class VebTree {
 public:
  VebTree(const int u);

  // Check whether a vertex is member of the tree.
  bool member(int val);

  // Pushes an edge in the tree.
  void push(const Edge& e);

  // Removes the min element of the tree.
  void pop();

  // Updates the value of vert with new_cost.
  void update(const int vert, const int new_cost);

  // Queries the top value.
  Edge top();

  // The number of elements in the tree.
  int size();
  // Is the tree empty.
  bool empty();
  // Removes all elements from the tree.
  void clean();

 //private:
  // map<vert, dist>
  std::unordered_map<int, int> vert2dist_;

  // map<dist, set<val> >
  std::unordered_map<int, std::unordered_set<int>> dist2verts_;

  // Head
  VebNode* head_;

  // Create the tree, returns a pointer to the head.
  VebNode* create(const int u);

  void push_rec(VebNode* node, int val);
  void del_rec(VebNode* node, int val);
  void clean_rec(VebNode* node);
};

}
