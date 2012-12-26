#include "hopcroft_karp.h"

#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

namespace inf5016 {

int HopcroftKarp::run() {

  return matching_.size() / 2;
}

// Returns whether an augmenting path was found.
bool HopcroftKarp::bfs(map_ii& dist) {
  set_i visited;

  // This queue will only contain vertices in S.
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
      // If the edge has a matching, add the matching (in S) to the queue.
      if (matching_.find(*to) != matching_.end()) {
        const int next = matching_[*to];
        q.push(next);
        dist[next] = dist[cur] + 1;
      }
    }
  }
}

bool HopcroftKarp::dfs(const int v, map_ii& dist) {
  const set_i& edges = graph_[v];
  for (const_set_it it = edges.begin(); it != edges.end(); it++) {
    if (matching_.find(*it) != matching_.end()
        && dist[matching_[*it]] == dist[v] + 1) {
      if (dfs(matching_[*it], dist)) {
        matching_[v] = *it;
        matching_[*it] = v;
        return true;
      }
    }
    dist.erase(v); // TODO: understand why we do this.
    return false;
  }
  return true;
}

}
