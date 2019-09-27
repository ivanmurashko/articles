sort: sort.cpp
	docker run -v "$$PWD":/usr/src/myapp -w /usr/src/myapp gcc:7 \
	gcc -g -O0 sort.cpp -o sort -lstdc++

clean:
	rm -rf *.o *.so sort
	find . \( -name "*.log" -o -name "*~" \) -exec rm -rf {} \; 
