CC=gcc
CPPFLAGS=-g -O0 -std=c++14
LDFLAGS=-lstdc++

all: libtest4.so libtest5.so tests str sizes

str: str.cpp
	docker run --rm -v "$$PWD":/usr/src/myapp -w /usr/src/myapp gcc:4 \
	gcc -g -O0 -std=c++11 str.cpp -o str4 -lstdc++
	docker run --rm -v "$$PWD":/usr/src/myapp -w /usr/src/myapp gcc:5 \
	gcc -g -O0 str.cpp -o str5 -lstdc++

sizes: sizes.cpp
	docker run --rm -v "$$PWD":/usr/src/myapp -w /usr/src/myapp gcc:4 \
	gcc -g -O0 sizes.cpp -o sizes4 -lstdc++
	docker run --rm -v "$$PWD":/usr/src/myapp -w /usr/src/myapp gcc:5 \
	gcc -g -O0 sizes.cpp -o sizes5 -lstdc++

libtest4.so: old.cpp
	docker run --rm -v "$$PWD":/usr/src/myapp -w /usr/src/myapp gcc:4 \
	gcc -shared -fPIC -o libtest4.so -c old.cpp

libtest5.so: old.cpp
	docker run --rm -v "$$PWD":/usr/src/myapp -w /usr/src/myapp gcc:5 \
	gcc -shared -fPIC -o libtest5.so -c old.cpp

adapter.o: adapter.cpp
	gcc -g -O0 -fPIC -o adapter.o -c adapter.cpp

adapterold.o: adapterold.cpp
	gcc -g -O0 -fPIC -o adapterold.o -c adapterold.cpp

libadapter.so: adapter.o adapterold.o
	gcc -shared -fPIC adapter.o adapterold.o -o libadapter.so 

main.o: main.cpp
	gcc -g -O0 -c main.cpp 

tests: main.o libtest4.so libadapter.so
	gcc -g -O0 main.o -o tests -lstdc++ -L. -ladapter -ltest4

libtest.so: old.o
	gcc -shared -fPIC -o libtest.so -c old.cpp

clean:
	rm -rf *.o *.so tests *4 *5
	find . \( -name "*.log" -o -name "*~" \) -exec rm -rf {} \; 
