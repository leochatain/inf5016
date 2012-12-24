#include "hopcroft_karp.h"

#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

namespace inf5016 {

int HopcroftKarp::run() {
  return matching_.size() / 2;
}

void HopcroftKarp::bfs(map_ii& dist) {
  set_i visited;

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

    const set_i& edges = graph_[cur];
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

void HopcroftKarp::dfs(const int v) {

}

}
