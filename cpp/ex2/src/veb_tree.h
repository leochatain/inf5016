#ifndef __VEB_TREE_H
#define __VEB_TREE_H

#include <cstddef>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cassert>
#include <cmath>

#include "graph.h"

using std::cout;
using std::endl;

namespace inf5016 {

int upper_sqrt(const int u);
int lower_sqrt(const int u);

// As described in CLRS.
struct VebNode {
  int min;
  int max;

	const int u;

	VebNode* top;
	std::vector<VebNode*> bottom;

  VebNode(const int size) : u(size) {
    assert(size >= 2);

    const int num_children = upper_sqrt(u);
		top = NULL;
    if (size > 2) {
      bottom.resize(num_children, NULL);
    }
	}

  bool empty() {
    return min > max;
  }

  // Basic tree navigation functions.
  int high(const int x) {
    return (int) (x / lower_sqrt(u));
  }
  int low (const int x) {
    return x % lower_sqrt(u);
  }
  int index(const int x, const int y) {
    return x * lower_sqrt(u) + y;
  }

  void print(const int ind = 0) {
    for (int i = 0; i < ind; i++) cout << " ";
    cout << "**************************************" << endl;
    for (int i = 0; i < ind; i++) cout << " ";
    cout << "u " << u << "        min " << min << "        max " << max << endl;
    for (int i = 0; i < ind; i++) cout << " ";
    cout << "**************************************" << endl;
  }

};

class VebTree {
 public:
  VebTree(const int u);

  // Check whether a cost is member of the tree.
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

  // Prints the tree.
  void print_tree();

  // Prints all values in order.
  void print_values();

 //private:
  // map<vert, dist>
  std::unordered_map<int, int> vert2dist_;

  // map<dist, set<val> >
  std::unordered_map<int, std::unordered_set<int>> dist2verts_;

  // Head
  VebNode* head_;

  // Create the tree, returns a pointer to the head.
  VebNode* create(const int u);

  // Recursive functions
  void push_rec(VebNode* node, int val);
  void del_rec(VebNode* node, int val);
  void del_from_maps(const int vert, const int dist);
  bool member_rec(VebNode* node, int val);
  void clean_rec(VebNode* node);
  void clean_leaf(VebNode* node);
  void print_rec(VebNode* node, int ind);
};

}

#endif
