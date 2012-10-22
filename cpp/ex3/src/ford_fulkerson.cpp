#include "ford_fulkerson.h"

int FordFulkerson::run(const int src, const int dst) const {
  Graph& residual = create_residual_graph(graph_);

  
}

Graph create_residual_graph(const Graph& graph) {
  Graph residual;

  for (int i = 0; i < graph.size(); i++) {
    for (int j = 0; j < graph[i].size(); j++) {
      const Edge& cur = graph[i][j];
      // Reverse edge
      const int ru = cur.to;
      const int rv = i;
      const int rw = cur.weight;
      // Forward edge
      const int fu = i;
      const int fv = cur.to;
      const int fw = 0;

      residual.put(ru, rv, rw);
      residual.put(fu, fv, fw);
    }
  }

  return residual;
}

Graph pfs(Graph& residual) {
}
