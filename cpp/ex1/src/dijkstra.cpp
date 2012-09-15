#include "dijkstra.h"

#include <algorithm>
#include <cassert>

using std::make_pair;
using std::max;
using std::min;
using std::pair;
using std::vector;

namespace inf5016 {

const int INF = -1;

Dijkstra::Dijkstra(BinaryHeap<Edge>* heap) {
  this->heap_ = heap;
}

int Dijkstra::dijkstra(const Graph& graph, const int src, const int dst) {
  assert(src >= 0 && src < graph.size());
  assert(dst >= 0 && dst < graph.size());

  vector<bool> visited(graph.size(), false);
  vector<int> dist(graph.size(), INF);
  dist[src] = 0;

  heap_->push(Edge(src, 0));
  while (!heap_->empty()) {
    const int cur = heap_->top().dest;
    visited[cur] = true;
    if (cur == dst) {
      return heap_->top().cost;
    }
    heap_->pop();

    const vector<Edge>& ns = graph[cur];
    for (unsigned i = 0; i < ns.size(); i++) {
      const int to = ns[i].dest;
      const int cost = ns[i].cost;

      if (!visited[to]) {
        if (dist[to] == INF) {
          dist[to] = dist[cur] + cost;
          heap_->push(ns[i]);
        } else {
          dist[to] = min(dist[to], dist[cur] + cost);

          Edge new_edge(ns[i].dest, dist[to]);
          heap_->update(ns[i], new_edge);
        }
      }
    }
  }

  // Should never get here.
  assert(false);
}

}
