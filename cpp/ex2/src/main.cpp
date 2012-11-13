#include <cstdio>
#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

#include "veb_tree.h"
#include "dijkstra.h"
#include "graph.h"
#include "util.h"

using namespace std;
using namespace inf5016;

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

  int size = next_power(max_cost);

  Dijkstra dijkstra(size);

  int distance = dijkstra.run(graph, src, dst);  
  cout << distance << endl;
}

void print_help() {
  cout << "ex1 - By Leo Chatain (leochatain@gmail.com)" << endl << endl;
  cout << "First argument: src" << endl;
  cout << "Second argument: dst" << endl;
  cout << "Pass the graph on the stdin" << endl;
}
