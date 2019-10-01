#include "Time.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/transport/TServerSocket.h>
#include <string>
#include <ctime>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using namespace ::proto;

class TimeHandler : virtual public TimeIf {
public:
  TimeHandler() {
  }

  /**
   * Retrives the time
   */
  void getInfo(std::string &_return) {
    std::time_t now = std::time(NULL);
    _return = std::ctime(&now);
  }
};

int main(int argc, char **argv) {
  int port = 9090;
  ::apache::thrift::stdcxx::shared_ptr<TimeHandler> handler(new TimeHandler());
  ::apache::thrift::stdcxx::shared_ptr<TProcessor> processor(
      new TimeProcessor(handler));
  ::apache::thrift::stdcxx::shared_ptr<TServerTransport> serverTransport(
      new TServerSocket(port));
  ::apache::thrift::stdcxx::shared_ptr<TTransportFactory> transportFactory(
      new TBufferedTransportFactory());
  ::apache::thrift::stdcxx::shared_ptr<TProtocolFactory> protocolFactory(
      new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory,
                       protocolFactory);
  server.serve();
  return 0;
}
