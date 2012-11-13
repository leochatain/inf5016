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

const int ERROR = -1;
const int HELP = 0;
const int PROGRAM = 1;

int parse_args(int argc, char* argv[], int& num_bench, int& size);
void print_help();
void scramble(vector<Edge>& v);

int main(int argc, char** argv) {
  int num_bench;
  int size;

  switch (parse_args(argc, argv, num_bench, size)) {
    case ERROR:
      return ERROR;
    case HELP:
      print_help();
      return HELP;
  };

  // Run benchmarks.
  double sum_push = 0;
  double sum_pop = 0;
  double sum_update = 0;

  const int heap_size = next_power(2*size);

  for (int i = 0; i < num_bench; i++) {
    VebTree heap_push(heap_size), heap_pop(heap_size), heap_update(heap_size);

    // Generate a random vector and scramble it.
    vector<Edge> vec(size);
    for (int i = 0; i < size; i++) {
      vec[i] = Edge(i, i);
    }
    scramble(vec);

    // init heap pop, heap update
    for (int i = 0; i < size; i++) {
      heap_pop.push(vec[i]);
      heap_update.push(vec[i]);
    }

    // Measure push
    time_t init_time_push = clock();
    for (int i = 0; i < size; i++) {
      heap_push.push(vec[i]);
    }
    time_t end_time_push = clock();

    // Measure pop
    time_t init_time_pop = clock();
    for (int i = 0; i < size; i++) {
      heap_pop.pop();
    }
    time_t end_time_pop = clock();

    // Measure update
    time_t init_time_update = clock();
    for (int i = 0; i < size; i++) {
      srand(time(0));
      int node = rand() % size;
      int val = rand() % size;
      heap_update.update(node, val);
    }
    time_t end_time_update = clock();

    sum_push += (end_time_push - init_time_push) / (double)CLOCKS_PER_SEC;
    sum_pop += (end_time_pop - init_time_pop) / (double)CLOCKS_PER_SEC;
    sum_update += (end_time_update - init_time_update) / (double)CLOCKS_PER_SEC;
  }

  cout << sum_push / (double) num_bench << endl;
  cout << sum_pop / (double) num_bench << endl;
  cout << sum_update / (double) num_bench << endl;
}

void scramble(vector<Edge>& v) {
  srand(0);
  for (int i = 0; i < v.size(); i++) {
    int num = rand() % v.size();
    std::swap(v[i], v[num]);
  }
}

int parse_args(int argc, char* argv[], int& num_bench, int& size) {
  if (argc < 3) {
    return HELP;
  }
  for (int i = 1; i < argc; i++) {
    if (!(strcmp(argv[i], "-b"))) {
      num_bench = atoi(argv[++i]);
    } else if (!strcmp(argv[i], "-s")) {
      size = atoi(argv[++i]);
    } else {
      cout << "Unknown option " << argv[i] << endl;
      return ERROR;
    }
  }
  return PROGRAM;
}

void print_help() {
  cout << "ex1 - By Leo Chatain (leochatain@gmail.com)" << endl << endl;
  cout << "-b  Specifies the number of benchmarks (they're all random)"
      << endl;
  cout << "-s  Specifies the size of each benchmark" << endl;
}
