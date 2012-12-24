#ifndef __HOPCROFT_KARP_H
#define __HOPCROFT_KARP_H

#include <unordered_map>
#include <unordered_set>

typedef std::unordered_set<int> Set;
typedef std::unordered_map<int, Set> Graph;

typedef Graph::iterator graph_it;
typedef Graph::const_iterator const_graph_it;
typedef Set::iterator set_it;
typedef Set::const_iterator const_set_it;

namespace inf5016 {

class HopcroftKarp {
 public:
  HopcroftKarp(Graph& graph, Set& s, Set& t, Set&)
    : graph_(graph), s_(s), t_(t) { }

  int run();

 private:
  Graph& graph_;
  Set& s_;
  Set& t_;

  std::unordered_map<int, int> matching_;

  void bfs(std::unordered_map<int, int>& dist);
  //int next_free_node(Graph& graph);
};

}

#endif
