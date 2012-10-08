#include <cstddef>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../../ex1/src/graph.h"

namespace inf5016 {

struct VebNode {
	int u;
	VebNode* top;
	std::vector<VebNode*> bottom;

  VebNode(const int height) : h(height) {
		top = NULL;
		bottom.resize(1 << (h/2), 0); //  2 ** h/2
	}
};

class VebTree {
 public:
  VebTree();

  // Check whether a vertex is member of the tree.
  bool member(const int vert);
  const bool member(const int vert) const;

  // Pushes an edge in the tree.
  void push(const Edge& e);

  // Pops the min element of the tree.
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
  // map<dist, set<val> >
  std::unordered_map<int, std::unordered_set<int>> index_;

  // set<dist>
  std::unordered_set<int> base_;
};

}
