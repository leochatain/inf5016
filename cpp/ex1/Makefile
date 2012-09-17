CC=g++
CFLAGS=-c
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

all: ex1 test

ex1: $(BIN)

test: $(SOURCES) $(TESTS) $(BIN_TESTS)

$(BIN): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) $(TEMPLATES) $(MAIN) -o $@

$(BIN_TESTS): $(TEST_OBJECTS) $(OBJECTS)
	$(CC) $(LDFLAGS) $(TEST_OBJECTS) $(OBJECTS) $(TEMPLATES) -o $@ -lcppunit

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf src/*.o tests/*.o $(BIN) $(BIN_TESTS)

check: test
	$(BIN_TESTS)
