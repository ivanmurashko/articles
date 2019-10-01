SRC = main.cpp \
      gen-cpp/Time.cpp \
      gen-cpp/proto_constants.cpp \
      gen-cpp/proto_types.cpp
LIBTHRIFT = /usr/local/lib/libthrift.a
CPPFLAGS = -O0 -g -Wall -Igen-cpp -I/usr/local/include

thrift: proto.thrift
	thrift -r --gen cpp proto.thrift

all: thrift 
	g++ $(CPPFLAGS) -o server $(SRC) $(LIBTHRIFT) -lpthread
