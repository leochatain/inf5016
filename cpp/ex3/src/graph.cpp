#include <cassert>
#include <algorithm>

#include "graph.h"

using std::map;
using std::max;

namespace inf5016 {

Graph::Graph() { }

map<int>& Graph::operator[](const int node) {
  assert(node >= 0);
  assert(node < base_.size());

  return base_[node];
}

void Graph::put(const int u, const int v, const int w) {
  assert(u >= 0);
  assert(v >= 0);
  assert(w >= 0);

  base_[u][v] = w;
}

}
