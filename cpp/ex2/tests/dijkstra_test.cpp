#include "dijkstra_test.h"
#include "../src/dijkstra.h"

#include <map>
#include <fstream>
#include <iostream>

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(DijkstraTest);

using namespace std;
using namespace inf5016;

typedef map<int, map<int, int> > Solution;

int next_pow(const int size) {
  return 1 << ((int) log2(size) + 1);
}

pair<Graph, Solution> parse_graph(ifstream& in, int* max_cost) {
  Graph g;
  Solution s;
  string line;

  while (getline(in, line)) {
    if (line[0] == 'a') {
      int u, v, w;
      sscanf(line.c_str(), "a %d %d %d", &u, &v, &w);
      g.put(u, v, w);


      if (w > *max_cost) {
        *max_cost = w;
      }
    } else if (line[0] == 's') {
      int u, v, w;
      sscanf(line.c_str(), "s %d %d %d", &u, &v, &w);
      s[u][v] = w;
    }
  }

  return make_pair(g, s);
}

void DijkstraTest::setUp() {
  files_.push_back("32.gr");
  files_.push_back("64.gr");
  files_.push_back("128.gr");

  for (int i = 0; i < files_.size(); i++) {
    files_[i] = "../files/" + files_[i];
  }
}

void DijkstraTest::test_all() {
  for (int i = 0; i < files_.size(); i++) {
    ifstream file(files_[i].c_str());;

    int max_cost = -1;
    pair<Graph, Solution> p = parse_graph(file, &max_cost);
    const Graph& graph = p.first;

    cout << "max cost " << max_cost << endl;

    int size = next_pow(max_cost);

    cout << "size " << size << endl;
    Dijkstra dijkstra(size);

    
    for (int i = 1; i < graph.size(); i++) {
      for (int j = 1; j < graph.size(); j++) {
        int mysol = dijkstra.run(graph, i, j);
        CPPUNIT_ASSERT_EQUAL(p.second[i][j], mysol);
      }
    }
  }
}

