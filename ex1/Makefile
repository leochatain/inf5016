CC=g++
CFLAGS=-c
LDFLAGS=
SOURCES= src/dijkstra.cpp src/graph.cpp src/main.cpp
TEMPLATES = src/binary_heap.h
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=bin/ex1

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) $(TEMPLATES) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf src/*.o $(EXECUTABLE)
