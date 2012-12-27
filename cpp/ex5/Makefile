CC=g++
CFLAGS=-c -O2 -std=gnu++0x
LDFLAGS= -std=gnu++0x

BIN=bin/ex5
BIN_TESTS=bin/ex5_tests

MAIN= src/main.cpp
SOURCES= src/linked_set.cpp \
         src/util.cpp \
         src/hash_function.cpp \
         src/hash_set.cpp
TESTS = tests/runner.cpp tests/linked_set_test.cpp

OBJECTS=$(SOURCES:.cpp=.o)
TEST_OBJECTS=$(TESTS:.cpp=.o)

all: ex5 test

ex5: $(BIN)

test: $(BIN_TESTS)

$(BIN): $(MAIN) $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) $(MAIN) -o $@

$(BIN_TESTS): $(TEST_OBJECTS) $(OBJECTS)
	$(CC) $(LDFLAGS) $(TEST_OBJECTS) $(OBJECTS) -o $@ -lcppunit

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

check:
	$(BIN_TESTS)

clean:
	rm -rf src/.o bin/* test/.o
