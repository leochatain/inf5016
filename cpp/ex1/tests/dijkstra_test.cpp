#include "dijkstra_test.h"
#include "../src/dijkstra.h"

#include <map>
#include <iostream>
#include <fstream>

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(DijkstraTest);

using namespace std;
using namespace inf5016;

typedef map<int, map<int, int> > Solution;

pair<Graph, Solution> parse_graph(ifstream& in) {
  Graph g;
  Solution s;
  string line;

  while (getline(in, line)) {
    if (line[0] == 'a') {
      int u, v, w;
      sscanf(line.c_str(), "a %d %d %d", &u, &v, &w);
      g.put(u, v, w);
    } else if (line[0] == 's') {
      int u, v, w;
      sscanf(line.c_str(), "s %d %d %d", &u, &v, &w);
      s[u][v] = w;
    }
  }

  return make_pair(g, s);
}

void DijkstraTest::setUp() {
  //files_.push_back("7.gr");
  //files_.push_back("10.gr");
  //files_.push_back("50.gr");
  files_.push_back("100.gr");

  for (int i = 0; i < files_.size(); i++) {
    files_[i] = "files/" + files_[i];
  }
}

bool comp(const Edge a, const Edge b) {
  return a.cost < b.cost;
}

void DijkstraTest::test_all() {
  Dijkstra dijkstra;

  for (int i = 0; i < files_.size(); i++) {
    cout << "Opening file " << files_[i] << endl;
    ifstream file(files_[i].c_str());;
    cout << "Parsing graph..." << endl;
    pair<Graph, Solution> p = parse_graph(file);
    const Graph& graph = p.first;
    
    for (int i = 1; i < graph.size(); i++) {
      for (int j = 1; j < graph.size(); j++) {
        if (i == j) continue;
        int mysol = dijkstra.run(graph, i, j);
        cout << "Checking distance between " << i << " and " << j << endl;
        cout << "  correct: " << p.second[i][j] << endl;
        cout << "  mine: " << mysol << endl;
        CPPUNIT_ASSERT_EQUAL(p.second[i][j], mysol);
      }
    }
  }
  cout << endl;
}

