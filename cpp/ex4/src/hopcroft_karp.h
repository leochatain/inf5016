#ifndef __HOPCROFT_KARP_H
#define __HOPCROFT_KARP_H

#include <unordered_map>
#include <unordered_set>

typedef std::unordered_set<int> set_i;
typedef std::unordered_map<int, int> map_ii;
typedef std::unordered_map<int, set_i> Graph;

typedef Graph::iterator graph_it;
typedef Graph::const_iterator const_graph_it;

typedef set_i::iterator set_it;
typedef set_i::const_iterator const_set_it;

typedef map_ii::iterator map_it;
typedef map_ii::const_iterator const_map_it;

namespace inf5016 {

class HopcroftKarp {
 public:
  HopcroftKarp(Graph& graph, set_i& s, set_i& t)
    : graph_(graph), s_(s), t_(t) { }

  int run();

 private:
  Graph& graph_;
  set_i& s_;
  set_i& t_;

  map_ii matching_;

  void bfs(std::unordered_map<int, int>& dist);
  void dfs(const int v);
};

}

#endif
