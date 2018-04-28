CC=gcc
CPPFLAGS=-g -O0 -std=c++14
LDFLAGS=-lstdc++ -lm -lpthread
CPPSOURCES=$(wildcard ./*.cpp)

all: cppabi.tex exception libtest4.so libtest5.so libtest6.so
	pdflatex cppabi.tex
	cd presentation && $(MAKE)

# .cpp:
# 	$(CC) $(CPPFLAGS) $< -o $@

libtest4.so: libtest/old.cpp
	cd libtest && $(MAKE) clean
	docker run --rm -v "$$PWD/libtest":/usr/src/myapp -w /usr/src/myapp gcc:4 make
	cp libtest/libtest.so libtest4.so

libtest5.so: libtest/old.cpp
	cd libtest && $(MAKE) clean
	docker run --rm -v "$$PWD/libtest":/usr/src/myapp -w /usr/src/myapp gcc:5 make
	cp libtest/libtest.so libtest5.so

libtest6.so: libtest/old.cpp
	cd libtest && $(MAKE) clean
	docker run --rm -v "$$PWD/libtest":/usr/src/myapp -w /usr/src/myapp gcc:6 make
	cp libtest/libtest.so libtest6.so


main.o: main.cpp
	gcc $(CPPFLAGS) -fPIC -c main.cpp

exception: main.o libtest4.so
	$(CC) main.o -o exception $(LDFLAGS) -L. -ltest4


clean:
	rm -rf cppabi.aux cppabi.bbl cppabi.dvi cppabi.pdf crypto.pdf crypto.dvi 
	rm -rf cppabi.blg cppabi.toc cppabi.out cppabi.idx cppabi.ilg cppabi.ind
	rm -rf algorithmic.sty  algorithm.sty
	rm -rf *.o exception *.so
	find . \( -name "*.log" -o -name "*~" \) -exec rm -rf {} \; 
	cd presentation && $(MAKE) clean
	cd libtest && $(MAKE) clean
