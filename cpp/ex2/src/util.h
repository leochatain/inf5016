#ifndef __UTIL_H
#define __UTIL_H

#include "graph.h"

#include <fstream>
#include <iostream>

namespace inf5016 {

Graph parse_graph(std::istream& in, int* max_cost);

int next_power(const int size);

}

#endif
