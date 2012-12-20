#include <cstdio>
#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

//#include "graph.h"
#include "ford_fulkerson.h"

using namespace std;
using namespace inf5016;

Graph parse_graph(istream& in);
void print_help();

int main(int argc, char** argv) {
  if (argc < 3 ) {
    print_help();
    return 0;
  }

  int src = atoi(argv[1]);
  int dst = atoi(argv[2]);

  // Parse graph and benchmarks.
  const Graph& graph = parse_graph(cin);

  FordFulkerson ff(graph);

  int max_flow = ff.run(src, dst);
  cout << max_flow << endl;
}

Graph parse_graph(istream& in) {
  Graph g;
  string line;

  while (getline(in, line)) {
    if (line[0] == 'a') {
      int u, v, w;
      sscanf(line.c_str(), "a %d %d %d", &u, &v, &w);
      g.put(u, v, w);
    }
  }

  return g;
}

void print_help() {
  cout << "ex3 - By Leo Chatain (leochatain@gmail.com)" << endl << endl;
  cout << "First argument: src" << endl;
  cout << "Second argument: dst" << endl;
  cout << "Pass the graph on the stdin" << endl;
}
