all: category objects

category: category.cpp
	gcc -g -O0 -std=c++14 category.cpp -o category -lstdc++

objects: objects.cpp
	gcc -g -O0 -std=c++14 objects.cpp -o objects -lstdc++


clean:
	rm -rf category
	rm -rf objects
	find . \( -name "*.log" -o -name "*~" \) -exec rm -rf {} \; 
