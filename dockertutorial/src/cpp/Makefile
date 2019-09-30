src = $(wildcard gen-cpp/*.cpp) main.cpp
obj = $(src:.cpp=.o)
LDFLAGS = -lthrift -L/usr/local/lib

all: proto

proto.thrift: ../thrift/proto.thrift
	cp -f ../thrift/proto.thrift .

gen-cpp/Time.cpp: proto.thrift
	docker run --rm -v "$$PWD":/usr/src/myapp -w /usr/src/myapp thriftbuilder thrift -r --gen cpp proto.thrift

.cpp:
   docker run --rm -v "$$PWD":/usr/src/myapp -w /usr/src/myapp thriftbuilder g++  -I/usr/local/include $< -o $@

proto: gen-cpp/Time.o $(obj)
   docker run --rm -v "$$PWD":/usr/src/myapp -w /usr/src/myapp thriftbuilder g++  -o $@ $^ $(LDFLAGS)

clean:
	docker run --rm -v "$$PWD":/usr/src/myapp -w /usr/src/myapp thriftbuilder rm -rf gen-cpp *.o
	rm -rf proto.thrift proto
	find . \( -name "*.log" -o -name "*~" \) -exec rm -rf {} \; 
