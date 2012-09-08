#include <cstdio>
#include <iostream>
#include <vector>

#include "binary_heap.h"
#include "graph.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

using namespace inf5016;

Graph read_graph();

int main(int argc, char** argv) {
  int src, dst;
  cin >> src >> dst;
  const Graph& graph = read_graph();

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
