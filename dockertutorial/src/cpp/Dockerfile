FROM thriftbuilder
RUN mkdir -p /usr/src/cpp
COPY ./cpp /usr/src/cpp/
COPY ./thrift/proto.thrift /usr/src/cpp/proto.thrift
RUN cd /usr/src/cpp \
   && make all
CMD /usr/src/cpp/server