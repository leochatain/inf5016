#include "ford_fulkerson.h"

#include <queue>

using std::queue;

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

// Updates the residual graph with the augmenting path. Returns the
// width of the path.
// TODO(leochatain): this should really be a pfs, rather than a bfs.
int FordFulkerson::pfs(Graph& residual, const int src, const int dst) {
	queue<Edge> q;
	for (int i = 0; i < residual[src].size(); i++) {
		q.push(residual[src][i]);
	}

	while (!q.empty()) {
		const Edge& cur = q.front();
		q.pop();
		if (cur.dest == dst) {
			// we're home boys
		} else {
			// queue up these guys over here.
		}
	}
}

}
