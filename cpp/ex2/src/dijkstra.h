#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_

#include "graph.h"
#include "veb_tree.h"

namespace inf5016 {

class Dijkstra {
 public:
  Dijkstra(const int n);
	int run(const Graph& graph, const int src, const int dst);

 private:
  int size;
};

}

#endif
