#include "hopcroft_karp.h"

#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

namespace inf5016 {

/*int HopcroftKarp::next_free_node(Graph& graph) {
  for (graph_it it = graph.begin(); it != graph.end(); it++) {
    if (free_.find(it->first) == free_.end()) {
      return it->first;
    }
  }
  return -1;
}*/

int HopcroftKarp::run() {
  // Iterate over free vertices in S, and call bfs on them.
  // Because bfs goes from S to T using free edges (and free S nodes) and 
  // comes back using matched S-T edges (ending in matched S nodes), we can
  // safely call it for all free nodes in parallel.
  for (set_it it = s_.begin(); it != s_.end(); it++) {
    if (free_.find(*it) != free_.end()) // is a free node
      bfs(*it);
  }

  return (graph_.size() - free_.size()) / 2;
}

void HopcroftKarp::bfs(const int next) {
  unordered_set<int> visited;
  unordered_map<int, int> from;
  queue<int> q;

  q.push(next);
  while (!q.empty()) {
    const int cur = q.front(); q.pop();
    visited.insert(cur);

    // If cur is in T we're looking for matched edges. Else we're looking for
    // free edges.
    const bool matched = (t_.find(cur) == t_.end());

    // Push all edges that are 'matched'.
    const EdgeList& edges = graph_[cur];
    for (const_edge_it it = edges.begin(); it != edges.end(); it++) {
      const int to = it->first;
      const int mat = it->second;

      if (mat == matched && visited.find(to) == visited.end()) {
        q.push(to);
        from[to] = cur;
      }
    }
  }
}

}
