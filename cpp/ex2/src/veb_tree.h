#include <cstddef>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cassert>

#include "../../ex1/src/graph.h"

namespace inf5016 {

struct VebNode {
	const int h;
	VebNode* top;
	std::vector<VebNode*> bottom;

  VebNode(const int height) : h(height) {
    assert(height >= 2);

		top = NULL;
		bottom.resize(1 << (h/2), NULL); //  2 ** h/2
	}

  // Basic tree navigation functions
  int subtree(int e) {
    return e >> ((h+1)/2) - 1;
  }
  int subindex(int e) {
    return e & (1 << (h/2) - 1) - 1;
  }
  int element(int s, int i) {
    return ((s << (h/2)) - 1) | i;
  }
};

class VebTree {
 public:
  VebTree(const int u);

  // Check whether a vertex is member of the tree.
  bool member(const int vert);
  const bool member(const int vert) const;

  // Pushes an edge in the tree.
  void push(const Edge& e);

  // Removes the min element of the tree.
  void pop();

  // Updates the value of vert with new_cost.
  void update(const int vert, const int new_cost);

  // Queries the top value.
  Edge& top();
  const Edge& top() const;

  // The number of elements in the tree.
  int size();
  // Is the tree empty.
  bool empty();
  // Removes all elements from the tree.
  void clean();

 private:
  // map<vert, dist>
  std::unordered_map<int, int> vert2dist_;

  // map<dist, set<val> >
  std::unordered_map<int, std::unordered_set<int>> dist2verts_;

  // Head
  VebNode* head_;

  // Create the tree, returns a pointer to the head.
  VebNode* create(const int u);
  // Recursive version of the create function.
  VebNode* create_rec(const int h);

};

}
