CC=g++
CFLAGS=-c -O2 -std=gnu++0x
LDFLAGS= -std=gnu++0x

MAIN= src/main.cpp
SOURCES= src/veb_tree.cpp src/graph.cpp src/dijkstra.cpp

TESTS = tests/veb_tree_test.cpp tests/runner.cpp tests/dijkstra_test.cpp

OBJECTS=$(SOURCES:.cpp=.o)
TEST_OBJECTS=$(TESTS:.cpp=.o)

BIN=bin/ex2
BIN_TESTS=bin/ex2_tests

all: ex2 test

ex2: $(BIN)

test: $(SOURCES) $(TESTS) $(BIN_TESTS)

benchs: $(BIN_BENCH_DIJ) $(BIN_BENCH_HEAP)

$(BIN): $(OBJECTS) $(MAIN)
	$(CC) $(LDFLAGS) $(OBJECTS) $(TEMPLATES) $(MAIN) -o $@ -DNDEBUG

$(BIN_TESTS): $(TEST_OBJECTS) $(OBJECTS)
	$(CC) $(LDFLAGS) $(TEST_OBJECTS) $(OBJECTS) $(TEMPLATES) -o $@ -DNDEBUG -lcppunit

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

check: test
	$(BIN_TESTS)

clean:
	rm -rf src/*.o tests/*.o $(BIN) $(BIN_TESTS) $(BIN_GEN)
