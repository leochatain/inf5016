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
  cout << "Created residual" << endl;
  //while(pfs(residual, src, dst));
  pfs(residual, src, dst);

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
  cout << "looking for " << src <<  " " << dst << endl;
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

    // Because we don't update anything, we might have multiple versions of
    // the same element on the heap, and must check whether we have already
    // processed it.
    if (visited.find(cur) != visited.end()) { // if visited(cur)
      continue;
    }

    visited.insert(cur);

    cout << "looking at " << cur << " with cap " << cur_cap << endl;

    if (cur == dst) {
      cout << "FOUND IT" << endl;
      // found destiny, now go back and modify the path.
      // cur_cap holds the value of the bottleneck for this path.
      cout << "Found dst with bottleneck " << cur_cap << endl;
      int path = cur;
      cout << "Path:" << endl;
      while (path != src) {
        cout << path << endl;
        path = from[path];
      }
      cout << path << endl;

      return cur_cap;
    }

    const map<int, int>& ns = residual[cur];
    for (const_edge_it i = ns.begin(); i != ns.end(); i++) {
      const int to = i->first;
      const int cap = i->second;

      if (cap == 0) {
        continue;
      }

      cout << "neighbour: " << to << " with cap " << cap << endl;

      if (visited.find(to) == visited.end()) { // !visited(to)
        if (bottleneck.find(to) == bottleneck.end()) { // first time
          bottleneck[to] = min(bottleneck[cur], cap);
        } else {
          bottleneck[to] = max(bottleneck[to], min(bottleneck[cur], cap));
        }

        cout << "pushing " << to << " " << bottleneck[to] << endl;
        heap.push(make_pair(to, bottleneck[to])); // just push it, no updates
        from[to] = cur;
      }
    }
    cout << endl << endl;
  }

  cout << "There is no path, yay" << endl;
  return 0;
}

}
