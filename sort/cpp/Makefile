CC=gcc
CXX=g++

all: libsort.so main

main: main.cpp
	$(CXX) $^ -lsort -I./ -L./ -o $@
libsort.so: sort.cpp
	$(CXX) $^ -shared -o $@
clean:
	rm -f main
	rm -f libsort.so

.PHONY: all clear
