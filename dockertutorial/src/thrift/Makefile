thriftdata: proto.thrift
	docker run --rm -v "$$PWD":/usr/src/myapp -w /usr/src/myapp thriftbuilder thrift -r --gen cpp proto.thrift
	docker run --rm -v "$$PWD":/usr/src/myapp -w /usr/src/myapp thriftbuilder thrift -r --gen php proto.thrift

clean:
	docker run --rm -v "$$PWD":/usr/src/myapp -w /usr/src/myapp thriftbuilder rm -rf gen-*
	find . \( -name "*.log" -o -name "*~" \) -exec rm -rf {} \; 
