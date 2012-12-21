#include "ford_fulkerson.h"

#include <algorithm>
#include <queue>
#include <vector>
#include <cassert>

using std::queue;
using std::vector;
using std::map;
using std::max;
using std::min;

namespace inf5016 {

typedef map<int, map<int, int> >::iterator graph_it;
typedef map<int, map<int, int> >::const_iterator const_graph_it;
typedef map<int, int>::iterator edge_it;
typedef map<int, int>::const_iterator const_edge_it;

int FordFulkerson::run(const int src, const int dst) {
  Graph residual = create_residual_graph(graph_);
  while(pfs(residual, src, dst));

  // Count forward edges from the source to find out the max flow.
  int max_flow = 0;
  for (edge_it i = residual[src].begin(); i != residual[src].end(); i++) {
    max_flow += i->second;
  }

  return max_flow;
}

Graph FordFulkerson::create_residual_graph(const Graph& graph) {
  Graph residual;

  for (const_graph_it i = graph.begin(); i != graph.end(); i++) {
    for (const_edge_it j = i->second.begin(); j != i->second.end(); j++) {
      // This edge
      const int from = i->first;
      const int to = j->first;
      const int cost = j->second;

      residual[from][to] += cost;
      residual[to][from] += 0;
    }
  }

  return residual;
}

int FordFulkerson::pfs(Graph& residual, const int src, const int dst) {
  return 0;
}

}
