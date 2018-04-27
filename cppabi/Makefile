CC=gcc
CPPFLAGS=-g -O0 -std=c++14
LDFLAGS=-lstdc++ -lm -lpthread
CPPSOURCES=$(wildcard ./*.cpp)

all: cppabi.tex exception libtest47.so
	pdflatex cppabi.tex
	cd presentation && $(MAKE)

# .cpp:
# 	$(CC) $(CPPFLAGS) $< -o $@

libtest47.so: libtest/old.cpp
	cd libtest && $(MAKE) clean
	docker run --rm -v "$$PWD/libtest":/usr/src/myapp -w /usr/src/myapp gcc:4.7 make
	cp libtest/libtest.so libtest47.so

main.o: main.cpp
	gcc $(CPPFLAGS) -c main.cpp

exception: main.o old.o
	$(CC) main.o old.o -o exception $(LDFLAGS) -L. -ltest47


clean:
	rm -rf cppabi.aux cppabi.bbl cppabi.dvi cppabi.pdf crypto.pdf crypto.dvi 
	rm -rf cppabi.blg cppabi.toc cppabi.out cppabi.idx cppabi.ilg cppabi.ind
	rm -rf algorithmic.sty  algorithm.sty
	rm -rf *.o exception *.so
	find . \( -name "*.log" -o -name "*~" \) -exec rm -rf {} \; 
	cd presentation && $(MAKE) clean
	cd libtest && $(MAKE) clean
