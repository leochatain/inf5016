CC=g++
CFLAGS=-c -O2 -std=gnu++0x
LDFLAGS= -std=gnu++0x

BIN_LINKED=bin/linked
BIN_OPEN=bin/open
BIN_CUCKOO=bin/cuckoo

BIN_BENCH=bin/bench

BIN_TESTS=bin/ex5_tests

MAIN_LINKED= src/main_linked.cpp
MAIN_OPEN= src/main_open.cpp
MAIN_CUCKOO= src/main_cuckoo.cpp
MAIN_BENCH= src/benchmark.cpp

SOURCES= src/linked_set.cpp \
         src/open_set.cpp \
         src/cuckoo_set.cpp \
         src/util.cpp \
         src/hash_function.cpp

TESTS = tests/runner.cpp \
        tests/linked_set_test.cpp \
        tests/open_set_test.cpp \
        tests/cuckoo_set_test.cpp

OBJECTS=$(SOURCES:.cpp=.o)
TEST_OBJECTS=$(TESTS:.cpp=.o)

all: ex5_linked ex5_open ex5_cuckoo test bench

ex5_linked: $(BIN_LINKED)
ex5_open: $(BIN_OPEN)
ex5_cuckoo: $(BIN_CUCKOO)
bench: $(BIN_BENCH)

test: $(BIN_TESTS)

$(BIN_LINKED): $(MAIN_LINKED) $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) $(MAIN_LINKED) -o $@

$(BIN_OPEN): $(MAIN_OPEN) $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) $(MAIN_OPEN) -o $@

$(BIN_CUCKOO): $(MAIN_CUCKOO) $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) $(MAIN_CUCKOO) -o $@

$(BIN_BENCH): $(MAIN_BENCH) $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) $(MAIN_BENCH) -o $@

$(BIN_TESTS): $(TEST_OBJECTS) $(OBJECTS)
	$(CC) $(LDFLAGS) $(TEST_OBJECTS) $(OBJECTS) -o $@ -lcppunit


.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

check:
	$(BIN_TESTS)

clean:
	rm -rf src/*.o bin/* tests/*.o
