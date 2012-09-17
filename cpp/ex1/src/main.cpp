#include <cstdio>
#include <iostream>
#include <vector>

#include "binary_heap.h"
#include "dijkstra.h"
#include "graph.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

using namespace inf5016;

Graph read_graph();

bool comp(const Edge a, const Edge b) {
  return a.cost < b.cost;
}

int main(int argc, char** argv) {
  if (argc < 3) {
    cout << "Must pass src and dest as arguments." << endl;
    return 0;
  }
  int src = *argv[1] - '0';
  int dst = *argv[2] - '0';
  cout << src << " " << dst << endl;
  const Graph& graph = read_graph();

  cout << "Read graph, running dijkstra..." << endl;

  Dijkstra dijkstra;

  int distance = dijkstra.run(graph, src, dst);  
  cout << distance << endl;
}

Graph read_graph() {
  Graph g;
  string line;

  while (getline(cin, line)) {
    if (line[0] == 'a') {
      int u, v, w;
      sscanf(line.c_str(), "a %d %d %d", &u, &v, &w);
      g.put(u, v, w);
    }
  }

  return g;
}
