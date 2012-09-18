CC=g++
CFLAGS=-c -O2
LDFLAGS=

MAIN= src/main.cpp
SOURCES= src/dijkstra.cpp src/graph.cpp
TEMPLATES = src/binary_heap.h

TESTS = tests/binary_heap_test.cpp tests/graph_test.cpp \
	tests/dijkstra_test.cpp tests/runner.cpp

OBJECTS=$(SOURCES:.cpp=.o)
TEST_OBJECTS=$(TESTS:.cpp=.o)

BIN=bin/ex1
BIN_TESTS=bin/ex1_tests
BIN_GEN=bin/gen

all: ex1 test

ex1: $(BIN)

test: $(SOURCES) $(TESTS) $(BIN_TESTS)

gen: files/gen.cpp
	$(CC) files/gen.cpp -o $(BIN_GEN)

$(BIN): $(OBJECTS) $(MAIN)
	$(CC) $(LDFLAGS) $(OBJECTS) $(TEMPLATES) $(MAIN) -o $@

$(BIN_TESTS): $(TEST_OBJECTS) $(OBJECTS)
	$(CC) $(LDFLAGS) $(TEST_OBJECTS) $(OBJECTS) $(TEMPLATES) -o $@ -lcppunit

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

check: test
	$(BIN_TESTS)

generate: gen
	$(BIN_GEN) 5 1 > files/5.gr
	$(BIN_GEN) 10 1 > files/10.gr
	$(BIN_GEN) 50 1 > files/50.gr
	$(BIN_GEN) 100 1 > files/100.gr

clean:
	rm -rf src/*.o tests/*.o $(BIN) $(BIN_TESTS) $(BIN_GEN)
