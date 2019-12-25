CC=gcc
CXX=g++

all: libsort.so main

main: main.cpp
	$(CXX) $^ --std=c++11 -g -lsort -I./ -L./ -o $@

libsort.so: sort.cpp
	$(CXX) $^ --std=c++11 -g -fPIC -shared -o $@

clean:
	rm -f main
	rm -f libsort.so

run: 
	LD_LIBRARY_PATH="." ./main

.PHONY: all clear run
