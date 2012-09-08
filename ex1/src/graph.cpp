#include <cassert>

#include "graph.h"

using std::vector;

namespace inf5016 {

Graph::Graph() { }

vector<Edge> Graph::get_edges(const int node) {
  assert(node >= 0);
  assert(node < base_.size());
  return base_[node];
}

void Graph::add_node(vector<Edge> neighbours) {
  base_.push_back(neighbours);
}

void Graph::add_edge(const int node, Edge edge) {
  base_[node].push_back(edge);
}

void Graph::add_edges(const int node, vector<Edge> edges) {
  for (int i = 0; i < edges.size(); i++) {
    base_[node].push_back(edges[i]);
  }
}

}
