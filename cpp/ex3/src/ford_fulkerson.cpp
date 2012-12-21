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

// TODO(leochatain): check this
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

/*
// TODO(leochatain): this should really be a pfs, rather than a dfs.
int FordFulkerson::pfs(Graph& residual, const int src, const int dst,
    const int cur, const int cap) {
  if (cur == dst) {
    return cap;
  }

  for (edge_it it = residual[cur].begin(); it != residual[cur].end(), it++) {
    const int to = i->first;
    const int path_cap = min(cap, residual[cur][i].cost);
    const int path = pfs(residual, src, dst, to, path_cap);

    // If this path lead to the dst node, update the path and return the value.
    if (path != 0) {
      residual[cur][i].cost -= path;
      residual[i][cur] += path;
    }
  }

  return 0;
}*/

int FordFulkerson::pfs(Graph& residual, const int src, const int dst) {
  return 0;
}

/*
// Updates the residual graph with the augmenting path. Returns the increment
// on the flow.
int bfs(Graph& residual, const int src, const int dst) {
  queue<int> q;
  vector<int> from(residual.size() + 1, -1);

  for (int i = 0; i < residual[src].size(); i++) {
    q.push(residual[src][i]);
    from[residual[src][i].dest] = src;
  }

  while (!q.empty()) {
    const int cur = q.front();
    q.pop();

    if (cur != dst) {
      for (int i = 0; i < residual[cur].size(); i++) {
        const int 
        const int cost = residual[cur][i];
        // Skip edges with no capacity or vertices already visited.
        if (cost == 0 || from[to.dest] != -1) {
          continue;
        }

        from[dest] = cur;
        q.push(to);
      }
    } else {
      // Found the sink, recreate the path, finding the minimum.
      int path = cur;
      while (path != src) {
        
      }
    }
  }
}
*/

}
