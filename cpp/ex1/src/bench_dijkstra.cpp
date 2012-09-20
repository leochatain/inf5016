#include <cstdio>
#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

#include "binary_heap.h"
#include "dijkstra.h"
#include "graph.h"

using namespace std;
using namespace inf5016;

const int ERROR = -1;
const int HELP = 0;
const int PROGRAM = 1;

bool comp(const Edge a, const Edge b) {
  return a.cost < b.cost;
}

int parse_args(int argc, char* argv[], int& num_bench, string& graph_path);
vector<pair<int, int> > parse_bench(ifstream& in);
Graph parse_graph(ifstream& in);

void print_help();

int main(int argc, char** argv) {
  int num_bench;
  string graph_path;
  switch (parse_args(argc, argv, num_bench, graph_path)) {
    case ERROR:
      return ERROR;
    case HELP:
      print_help();
      return HELP;
  };

  // Parse graph and benchmarks.
  ifstream graph_file(graph_path.c_str());
  const Graph& graph = parse_graph(graph_file);

  Dijkstra dijkstra;

  // Run benchmarks.
  srand((int)time(0));
  double sum = 0;
  for (int i = 0; i < num_bench; i++) {
    int src = rand() % graph.size();
    int dst = rand() % (graph.size() - 1);

    if (dst == src) dst = graph.size() -1;

    time_t init_time = clock();
    int distance = dijkstra.run(graph, src, dst);  
    time_t end_time = clock();

    sum += (end_time - init_time) / (double)CLOCKS_PER_SEC;
  }
  cout << sum / (double) num_bench << endl;
}

int parse_args(int argc, char* argv[], int& num_bench, string& graph_path) {
  if (argc < 3) {
    return HELP;
  }
  for (int i = 1; i < argc; i++) {
    if (!(strcmp(argv[i], "-b"))) {
      num_bench = atoi(argv[++i]);
    } else if (!strcmp(argv[i], "-g")) {
      graph_path = argv[++i];
    } else {
      cout << "Unknown option " << argv[i] << endl;
      return ERROR;
    }
  }
  return PROGRAM;
}

Graph parse_graph(ifstream& in) {
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
  cout << "ex1 - By Leo Chatain (leochatain@gmail.com)" << endl << endl;
  cout << "-b  Specifies the number of benchmarks (they're all random)"
      << endl
      << "-g  Specifies the graph file." << endl;
}
