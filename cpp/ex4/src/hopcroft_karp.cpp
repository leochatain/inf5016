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
  return matching_.size() / 2;
}

void HopcroftKarp::bfs(unordered_map<int, int>& dist) {
  unordered_set<int> visited;

  // q only contains vertices in S.
  queue<int> q;

  // Enqueue all free nodes in s.
  for (set_it it = s_.begin(); it != s_.end(); it++) {
    if (matching_.find(*it) == matching_.end()) {
      q.push(*it);
      dist[*it] = 0;
    }
  }

  // Do the search.
  while (!q.empty()) {
    const int cur = q.front(); q.pop();
    visited.insert(cur);

    const Set& edges = graph_[cur];
    for (const_set_it to = edges.begin(); to != edges.end(); to++) {
      // If the edge has a matching, add it to the queue.
      if (matching_.find(*to) != matching_.end()) {
        const int next = matching_[*to];
        q.push(next);
        dist[next] = dist[cur] + 1;
      }
    }
  }
}

}
