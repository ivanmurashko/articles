CC=gcc
CPPFLAGS=-g -O0

all: libtest.so

old.o: old.cpp
	gcc -g -O0 -c old.cpp

libtest.so: old.o
	gcc -shared -o libtest.so -c old.cpp

clean:
	rm -rf *.o *.so
	find . \( -name "*.log" -o -name "*~" \) -exec rm -rf {} \; 
