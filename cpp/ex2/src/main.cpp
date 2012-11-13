#include <cstdio>
#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <ctime>

#include "veb_tree.h"
#include "dijkstra.h"
#include "graph.h"

using namespace std;
using namespace inf5016;

Graph parse_graph(istream& in, int* max_cost);
int next_power(const int size) {
  return 1 << ((int) log2(size) + 1);
}
void print_help();

int main(int argc, char** argv) {
  if (argc < 3 ) {
    print_help();
    return 0;
  }

  int src = atoi(argv[1]);
  int dst = atoi(argv[2]);

  int max_cost = -1;

  // Parse graph and benchmarks.
  const Graph& graph = parse_graph(cin, &max_cost);

  int size = 65536;

  Dijkstra dijkstra(size);

  int distance = dijkstra.run(graph, src, dst);  
  cout << distance << endl;
}

Graph parse_graph(istream& in, int* max_cost) {
  Graph g;
  string line;

  while (getline(in, line)) {
    if (line[0] == 'a') {
      int u, v, w;
      sscanf(line.c_str(), "a %d %d %d", &u, &v, &w);
      g.put(u, v, w);

      if (w > *max_cost) {
        *max_cost = w;
      }
    }
  }

  return g;
}

void print_help() {
  cout << "ex1 - By Leo Chatain (leochatain@gmail.com)" << endl << endl;
  cout << "First argument: src" << endl;
  cout << "Second argument: dst" << endl;
  cout << "Pass the graph on the stdin" << endl;
}
