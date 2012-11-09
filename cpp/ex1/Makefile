CC=g++
CFLAGS=-c -O2 -std=gnu++0x
LDFLAGS= -std=gnu++0x

MAIN= src/main.cpp
SOURCES= src/dijkstra.cpp src/graph.cpp src/binary_heap.cpp
BENCH_HEAP = src/bench_heap.cpp
BENCH_DIJ = src/bench_dijkstra.cpp

TESTS = tests/binary_heap_test.cpp tests/graph_test.cpp \
	tests/dijkstra_test.cpp tests/runner.cpp

OBJECTS=$(SOURCES:.cpp=.o)
TEST_OBJECTS=$(TESTS:.cpp=.o)

BIN=bin/ex1
BIN_TESTS=bin/ex1_tests
BIN_GEN=bin/gen
BIN_BENCH_HEAP=bin/bench_heap
BIN_BENCH_DIJ=bin/bench_dij

all: ex1 test gen benchs

ex1: $(BIN)

test: $(SOURCES) $(TESTS) $(BIN_TESTS)

benchs: $(BIN_BENCH_DIJ) $(BIN_BENCH_HEAP)

gen: ../files/gen.cpp
	$(CC) ../files/gen.cpp -o $(BIN_GEN)

$(BIN): $(OBJECTS) $(MAIN)
	$(CC) $(LDFLAGS) $(OBJECTS) $(MAIN) -o $@

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
	rm -rf src/*.o tests/*.o $(BIN) $(BIN_TESTS) $(BIN_GEN)
