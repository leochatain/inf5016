#include <cassert>

#include "graph.h"

using std::vector;

namespace inf5016 {

Graph::Graph() { }

const vector<Edge>& Graph::operator[](const int node) const {
  assert(node >= 0);
  assert(node < base_.size());
  return base_[node];
}

void Graph::put(const int u, const int v, const int w) {
  while(base_.size() < u) {
    base_.push_back(vector<Edge>());
  }
  base_[u].push_back(Edge(v, w));
}

}
