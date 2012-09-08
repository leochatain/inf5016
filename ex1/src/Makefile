CC=g++
CFLAGS=-c
LDFLAGS=
SOURCES= dijkstra.cpp graph.cpp binary_heap.h main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=ex1

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLE)
