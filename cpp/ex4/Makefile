CC=g++
CFLAGS=-c -O2 -std=gnu++0x
LDFLAGS= -std=gnu++0x

BIN=bin/ex4

MAIN= src/main.cpp
SOURCES= src/hopcroft_karp.cpp
OBJECTS=$(SOURCES:.cpp=.o)

all: ex4

ex4: $(BIN)

$(BIN): $(MAIN) $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) $(MAIN) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf src/.o bin/*
