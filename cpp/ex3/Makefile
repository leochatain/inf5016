CC=g++
CFLAGS=-c -O2 -std=gnu++0x
LDFLAGS= -std=gnu++0x

BIN=bin/ex3

MAIN= src/main.cpp
SOURCES= src/ford_fulkerson.cpp src/graph.cpp
OBJECTS=$(SOURCES:.cpp=.o)

all: ex3

ex3: $(BIN)

$(BIN): $(MAIN) $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) $(MAIN) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf src/.o bin/*
