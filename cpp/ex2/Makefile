CC=g++
CFLAGS=-c -O2 -std=gnu++0x
LDFLAGS= -std=gnu++0x

MAIN= src/main.cpp
SOURCES= src/veb_tree.cpp src/graph.cpp src/dijkstra.cpp src/util.cpp
BENCH_HEAP = src/bench_heap.cpp
BENCH_DIJ = src/bench_dijkstra.cpp

TESTS = tests/veb_tree_test.cpp tests/runner.cpp tests/dijkstra_test.cpp

OBJECTS=$(SOURCES:.cpp=.o)
TEST_OBJECTS=$(TESTS:.cpp=.o)

BIN=bin/ex2
BIN_TESTS=bin/ex2_tests
BIN_BENCH_HEAP=bin/bench_heap
BIN_BENCH_DIJ=bin/bench_dij

all: ex2 test benchs

ex2: $(BIN)

test: $(SOURCES) $(TESTS) $(BIN_TESTS)

benchs: $(BIN_BENCH_DIJ) $(BIN_BENCH_HEAP)

$(BIN): $(OBJECTS) $(MAIN)
	$(CC) $(LDFLAGS) $(OBJECTS) $(MAIN) -o $@ -DNDEBUG

$(BIN_TESTS): $(TEST_OBJECTS) $(OBJECTS)
	$(CC) $(LDFLAGS) $(TEST_OBJECTS) $(OBJECTS) -o $@ -lcppunit

$(BIN_BENCH_HEAP): $(OBJECTS) $(BENCH_HEAP)
	$(CC) $(LDFLAGS) $(OBJECTS) $(BENCH_HEAP) -o $@

$(BIN_BENCH_DIJ): $(OBJECTS) $(BENCH_DIJ)
	$(CC) $(LDFLAGS) $(OBJECTS) $(BENCH_DIJ) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

check: test
	$(BIN_TESTS)

clean:
	rm -rf src/*.o tests/*.o bin/*
