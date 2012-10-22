#include <cassert>
#include <algorithm>

#include "graph.h"

using std::vector;
using std::max;

namespace inf5016 {

Graph::Graph() { }

const vector<Edge>& Graph::operator[](const int node) const {
  assert(node >= 0);
  assert(node < base_.size());

  return base_[node];
}

void Graph::put(const int u, const int v, const int w) {
  assert(u >= 0);
  assert(v >= 0);
  assert(w >= 0);

  int big = max(u, v) + 1;
  if (base_.size() < big) {
    base_.resize(big);
  }
  for (int i = 0; i < base_[u].size(); i++) {
    assert(base_[u][i].dest != v);
  }
  base_[u].push_back(Edge(v, w));
}

}
