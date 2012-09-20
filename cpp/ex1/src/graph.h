#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>

namespace inf5016 {

struct Edge {
  int dest;
  int cost;

  Edge(const int dest, const int cost) : dest(dest), cost(cost) {}

  inline bool operator==(const Edge& other) {
    return this->dest == other.dest;
  }
  inline bool operator==(const Edge& other) const {
    return this->dest == other.dest;
  }
  inline bool operator<(const Edge& other) {
    return this->cost < other.cost;
  }
  inline bool operator<(const Edge& other) const {
    return this->cost < other.cost;
  }
};

class Graph {
 public:
  Graph();

  const std::vector<Edge>& operator[](const int node) const;

  void put(const int u, const int v, const int w);

  inline bool empty() const {
    return base_.empty();
  }

  inline int size() const {
    return base_.size();
  }

 private:
  std::vector<std::vector<Edge> > base_;
};

}

#endif
