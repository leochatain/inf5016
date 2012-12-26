#include <fstream>
#include <iostream>
#include <map>

#include "hopcroft_karp.h"

using namespace std;
using namespace inf5016;

Graph parse_graph(istream& in, set_i& s, set_i& t);

int main(int argc, char** argv) {
  set_i s, t;
  Graph graph = parse_graph(cin, s, t);

  HopcroftKarp hk(graph, s, t);

  int max_matching = hk.run();
  cout << max_matching << endl;
}

Graph parse_graph(istream& in, set_i& s, set_i& t) {
}
