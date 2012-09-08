#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>

namespace inf5016 {

struct Edge {
  int dest;
  int cost;

  Edge(const int dest, const int cost) : dest(dest), cost(cost) {}
};

class Graph {
 public:
  Graph();

  std::vector<Edge> get_edges(const int node);
  void add_node(std::vector<Edge> neighbours);
  void add_edge(const int node, Edge edge);
  void add_edges(const int node, std::vector<Edge> edges);

 private:
  std::vector<std::vector<Edge> > base_;
};

}

#endif
