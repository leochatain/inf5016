#include "ford_fulkerson.h"

#include <queue>
#include <vector>

using std::queue;
using std::vector;

namespace inf5016 {

int FordFulkerson::run(const int src, const int dst) {
  Graph residual = create_residual_graph(graph_);
}

Graph FordFulkerson::create_residual_graph(const Graph& graph) {
  Graph residual;

  for (int i = 0; i < graph.size(); i++) {
    for (int j = 0; j < graph[i].size(); j++) {
      const Edge& cur = graph[i][j];
      // Reverse edge
      const int ru = cur.dest;
      const int rv = i;
      const int rw = cur.cost;
      // Forward edge
      const int fu = i;
      const int fv = cur.dest;
      const int fw = 0;

      residual.put(ru, rv, rw);
      residual.put(fu, fv, fw);
    }
  }

  return residual;
}

// Updates the residual graph with the augmenting path. Returns the increment
// on the flow.
// TODO(leochatain): this should really be a pfs, rather than a bfs.
int FordFulkerson::pfs(Graph& residual, const int src, const int dst) {
  queue<Edge> q;
  vector<int> from(residual.size() + 1, -1);

  for (int i = 0; i < residual[src].size(); i++) {
    q.push(residual[src][i]);
    from[residual[src][i].dest] = src;
  }

  while (!q.empty()) {
    const Edge& edge = q.front();
    const int cur = edge.dest;
    const int capacity = edge.cost;
    q.pop();

    // Skips edges with no capacity.
    if (capacity == 0) {
      continue;
    }

    // Haven't visited this guy yet, add edges to the queue.
    if (cur != dst && from[cur] == -1) {
      for (int i = 0; i < residual[cur].size(); i++) {
        from[residual[cur][i].dest] = cur;
        q.push(residual[cur][i]);
      }
    } else if (cur == dst) {
      // Found the sink.
      
    }
  }
}

}
