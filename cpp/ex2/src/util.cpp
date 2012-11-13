#include "util.h"
#include <cmath>

using namespace std;

namespace inf5016 {

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

int next_power(const int size) {
  return 1 << ((int) log2(size) + 1);
}

}
