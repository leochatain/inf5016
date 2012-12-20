#ifndef GRAPH_H_
#define GRAPH_H_

#include <map>
#include <vector>

namespace inf5016 {

/*
struct Edge {
  int dest;
  int cost;

  Edge() : dest(0), cost(0) {}
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
*/

typedef std::map<int, std::map<int, int> > multimap_ii;
typedef std::map<int, std::map<int, int> >::iterator multimap_ii_it;

class Graph {
 public:
  Graph();

  std::map<int, int>& operator[](const int node);
  void put(const int u, const int v, const int w);

  inline bool empty() const {
    return base_.empty();
  }

  inline int size() const {
    return base_.size();
  }

  inline multimap_ii_it begin() {
    return base_.begin();  
  }

  inline multimap_ii_it end() {
    return base_.end();
  }

 private:
   multimap_ii base_;
};

}

#endif
