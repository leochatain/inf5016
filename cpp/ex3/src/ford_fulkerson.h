#ifndef __FORD_FULKERSON_H
#define __FORD_FULKERSON_H

#include <unordered_map>

typedef std::pair<int, int> Edge;
typedef std::unordered_map<int, std::unordered_map<int, int> > Graph;

typedef Graph::iterator graph_it;
typedef Graph::const_iterator const_graph_it;
typedef std::unordered_map<int, int>::iterator edge_it;
typedef std::unordered_map<int, int>::const_iterator const_edge_it;

namespace inf5016 {

class FordFulkerson {
 public:
  FordFulkerson(const Graph& graph) : graph_(graph) { }

  // Runs the Ford-Fulkerson algorithm over the graph;
  int run(const int src, int dst);

 private:
  const Graph& graph_;

  // Creates a residual graph out of the original graph.
  Graph create_residual_graph(const Graph& graph);

  // Dijkstra-like max(min(paths)) way of finding the fattest path
  int pfs(Graph& residual, const int src, const int dst);
  int pfs(Graph& residual, const int src, const int dst,
     const int cur, const int cap);
};

}

#endif
