#include "ford_fulkerson.h"

#include <iostream>

#include <algorithm>
#include <queue>
#include <vector>
#include <cassert>
#include <queue>
#include <set>

using namespace std;

namespace inf5016 {

typedef map<int, map<int, int> >::iterator graph_it;
typedef map<int, map<int, int> >::const_iterator const_graph_it;
typedef map<int, int>::iterator edge_it;
typedef map<int, int>::const_iterator const_edge_it;

int FordFulkerson::run(const int src, const int dst) {
  Graph residual = create_residual_graph(graph_);
  while(pfs(residual, src, dst));
  //pfs(residual, src, dst);

  // Count forward edges from the source to find out the max flow.
  int max_flow = 0;
  for (edge_it i = residual[dst].begin(); i != residual[dst].end(); i++) {
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

struct order {
  bool operator()(const Edge& l, const Edge& r) {
    return l.second < r.second;
  }
};

int FordFulkerson::pfs(Graph& residual, const int src, const int dst) {
  map<int, int> from; // from[i] == j -> j came from i
  map<int, int> bottleneck; // vertex and the bottleneck to get to it
  set<int> visited;

  priority_queue<Edge, vector<Edge>, order> heap;

  heap.push(make_pair(src, 0));
  bottleneck[src] = 1 << 31 - 1;

  while(!heap.empty()) {
    const int cur = heap.top().first;
    const int cur_cap = heap.top().second;
    heap.pop();

    if (visited.find(cur) != visited.end()) { // if visited(cur) already
      continue;
    }
    visited.insert(cur);

    if (cur == dst) {
      // found destiny, now go back and modify the path.
      // cur_cap holds the value of the bottleneck for this path.

      int path = cur;
      while (path != src) {
        const int to = path;
        path = from[path];

        residual[path][to] -= cur_cap;
        residual[to][path] += cur_cap;
      }

      return cur_cap;
    }

    const map<int, int>& ns = residual[cur];
    for (const_edge_it i = ns.begin(); i != ns.end(); i++) {
      const int to = i->first;
      const int cap = i->second;

      if (cap != 0 && visited.find(to) == visited.end()) {
        const int from_here = min(bottleneck[cur], cap);

        if (from_here > bottleneck[to]) {
          bottleneck[to] = from_here;
          heap.push(make_pair(to, bottleneck[to]));
          from[to] = cur;
        }
      }
    }
  }

  return 0;
}

}
