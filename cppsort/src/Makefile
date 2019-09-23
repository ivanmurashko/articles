CC=gcc
CPPFLAGS=-g -O0 -std=c++14
LDFLAGS=-lstdc++


sort: sort.cpp
	gcc -g -O0 -std=c++11 sort.cpp -o sort -lstdc++

clean:
	rm -rf *.o *.so sort
	find . \( -name "*.log" -o -name "*~" \) -exec rm -rf {} \; 
