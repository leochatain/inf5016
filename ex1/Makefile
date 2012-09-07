CXX := g++
CXX_FLAGS := -Wall -o2

all: ex1

ex1: src/main.cpp src/binary_heap.h
	$(CXX) $(CXX_FLAGS) src/main.cpp src/binary_heap.h -o bin/ex1

clean:
	rm -rf bin/* obj/*
