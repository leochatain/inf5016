#include "dijkstra.h"

#include <algorithm>
#include <cassert>

using std::make_pair;
using std::max;
using std::min;
using std::pair;
using std::vector;

using namespace std;

namespace inf5016 {

const int INF = 1 << 31 - 1;

bool comp(const Edge a, const Edge b) {
  return a.cost < b.cost;
}

Dijkstra::Dijkstra() {
  this->heap_ = new BinaryHeap<Edge>(comp);
}

int Dijkstra::run(const Graph& graph, const int src, const int dst) {
  assert(src >= 0 && src < graph.size());
  assert(dst >= 0 && dst < graph.size());
  heap_->clear();

  vector<bool> visited(graph.size(), false);
  vector<int> dist(graph.size(), INF);
  dist[src] = 0;

  heap_->push(Edge(src, 0));
  while (!heap_->empty()) {
    const int cur = heap_->top().dest;

    visited[cur] = true;
    if (cur == dst) {
      return min(heap_->top().cost, dist[dst]);
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

  return -1;
}

}
