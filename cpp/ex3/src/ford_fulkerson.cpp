#include "ford_fulkerson.h"

#include <algorithm>
#include <queue>
#include <vector>
#include <cassert>

using std::queue;
using std::vector;
using std::min;

namespace inf5016 {

int FordFulkerson::run(const int src, const int dst) {
  Graph residual = create_residual_graph(graph_);
  while(pfs(residual, src, dst));

  // Count forward edges from the source to find out the max flow.
  int max_flow = 0;
  for (int i = 0; i < residual[src].size(); i++) {
    max_flow += residual[src][i].cost;
  }

  return max_flow;
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

// TODO(leochatain): this should really be a pfs, rather than a bfs.
int FordFulkerson::pfs(Graph& residual, const int src, const int dst,
    const int cur, const int cap) {
  if (cur == dst) {
    return cap;
  }

  for (int i = 0; i < residual[cur].size(); i++) {
    const int to = residual[cur][i].dest;
    const int path_cap = min(cap, residual[cur][i].cost);
    const int path = pfs(residual, src, dst, to, path_cap);

    // If this path lead to the dst node, update the path and return the value.
    if (path != 0) {
      residual[cur][i].cost -= path;
      bool found = false;
      for (int  j = 0; j < residual[to].size(); j++) {
        if (residual[to][j].dest == cur) {
          residual[to][j].cost += path;
          found = true;
        }
      }
      assert (found);
      return path;
    }
  }

  return 0;
}

int FordFulkerson::pfs(Graph& residual, const int src, const int dst) {
  return pfs(residual, src, dst, src, 0);
}

// Updates the residual graph with the augmenting path. Returns the increment
// on the flow.
int bfs(Graph& residual, const int src, const int dst) {
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

    if (cur != dst) {
      for (int i = 0; i < residual[cur].size(); i++) {
        const Edge& to = residual[cur][i];
        // Skip edges with no capacity or vertices already visited.
        if (to.cost == 0 || from[to.dest] != -1) {
          continue;
        }

        from[to.dest] = cur;
        q.push(to);
      }
    } else {
      // Found the sink, recreate the path, finding the minimum.

    }
  }
}

}
