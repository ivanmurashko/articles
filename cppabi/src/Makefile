CC=gcc
CPPFLAGS=-g -O0 -std=c++14
LDFLAGS=-lstdc++ -lm -lpthread

all: libtest4.so libtest5.so libtest6.so exception 

libtest4.so: old.cpp clean-libtest
	make clean-libtest
	docker run --rm -v "$$PWD":/usr/src/myapp -w /usr/src/myapp gcc:4 make libtest.so
	mv -f libtest.so libtest4.so

libtest5.so: old.cpp clean-libtest
	docker run --rm -v "$$PWD":/usr/src/myapp -w /usr/src/myapp gcc:5 make libtest.so
	mv -f libtest.so libtest5.so

libtest6.so: old.cpp clean-libtest
	docker run --rm -v "$$PWD":/usr/src/myapp -w /usr/src/myapp gcc:6 make libtest.so
	mv -f libtest.so libtest6.so

main.o: main.cpp
	gcc $(CPPFLAGS) -fPIC -c main.cpp

exception: main.o libtest5.so
	$(CC) main.o -o exception $(LDFLAGS) -L. -ltest4

libtest.so: old.o
	gcc -shared -fPIC -o libtest.so -c old.cpp

clean-libtest:
	rm -rf old.o libtest.so

clean:
	rm -rf *.o *.so exception
	find . \( -name "*.log" -o -name "*~" \) -exec rm -rf {} \; 
