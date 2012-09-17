#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_

#include "graph.h"
#include "binary_heap.h"

namespace inf5016 {

class Dijkstra {
 public:
  Dijkstra();
	int run(const Graph& graph, const int src, const int dst);

 private:
  BinaryHeap<Edge> *heap_;
};

}

#endif
