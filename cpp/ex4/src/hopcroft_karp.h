#ifndef __HOPCROFT_KARP_H
#define __HOPCROFT_KARP_H

#include <unordered_map>
#include <unordered_set>

// Boolean: true -> matched, false -> free
typedef std::unordered_map<int, bool> EdgeList;
typedef std::unordered_map<int, EdgeList > Graph;

typedef Graph::iterator graph_it;
typedef Graph::const_iterator const_graph_it;
typedef EdgeList::iterator edge_it;
typedef EdgeList::const_iterator const_edge_it;

typedef std::unordered_set<int> Set;
typedef Set::iterator set_it;

namespace inf5016 {

class HopcroftKarp {
 public:
  HopcroftKarp(Graph& graph, Set& s, Set& t, Set&, Set& free)
    : graph_(graph), s_(s), t_(t), free_(free) { }

  int run();

 private:
  Graph& graph_;
  Set& free_;
  Set& s_;
  Set& t_;

  void bfs(const int next);
  //int next_free_node(Graph& graph);
};

}

#endif
