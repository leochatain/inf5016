#include "dijkstra.h"
#include "binary_heap.h"

#include <algorithm>
#include <cassert>

using std::make_pair;
using std::max;
using std::min;
using std::pair;
using std::vector;

namespace inf5016 {

const int INF = -1;

bool comp(Edge a, Edge b) {
  return a.cost < b.cost;
}

int Dijkstra::dijsktra(const Graph& graph, const int src, const int dst) {
  assert(src >= 0 && src < graph.size());
  assert(dst >= 0 && dst < graph.size());

  vector<bool> visited(graph.size(), false);
  vector<int> dist(graph.size(), INF);
  dist[src] = 0;

  BinaryHeap<Edge> queue(comp);

  queue.push(Edge(src, 0));
  while (!queue.empty()) {
    const int cur = queue.top().dest;
    visited[cur] = true;
    if (cur == dst) {
      return queue.top().cost;
    }
    queue.pop();

    const vector<Edge>& ns = graph[cur];
    for (unsigned i = 0; i < ns.size(); i++) {
      const int to = ns[i].dest;
      const int cost = ns[i].cost;

      if (!visited[to]) {
        if (dist[to] == INF) {
          dist[to] = dist[cur] + cost;
          queue.push(ns[i]);
        } else {
          dist[to] = min(dist[to], dist[cur] + cost);

          Edge new_edge(ns[i].dest, dist[to]);
          queue.update(ns[i], new_edge);
        }
      }
    }
  }

  // Should never get here.
  assert(false);
}

}
