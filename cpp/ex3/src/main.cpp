#include <cstdio>
#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

#include "ford_fulkerson.h"

using namespace std;
using namespace inf5016;

Graph parse_graph(istream& in, int& s, int& t);
void print_help();

int main(int argc, char** argv) {
  int s = -1, t = -1;
  // Parse graph and benchmarks.
  const Graph graph = parse_graph(cin, s, t);

  if (s == -1 || t == -1) {
    cout << "Source or sink are not defined" << endl;
  }

  FordFulkerson ff(graph);

  int max_flow = ff.run(s, t);
  cout << max_flow << endl;
}

Graph parse_graph(istream& in, int& s, int& t) {
  Graph g;
  string line;

  while (getline(in, line)) {
    if (line[0] == 'a') {
      int u, v, w;
      sscanf(line.c_str(), "a %d %d %d", &u, &v, &w);
      g[u][v] = w;
    } else if (line[0] == 'n') {
      char which;
      int val;
      sscanf(line.c_str(), "n %d %c", &val, &which);
      if (which == 's')
        s = val;
      else
        t = val;
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
