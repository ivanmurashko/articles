all: category

category: category.cpp
	gcc -g -O0 -std=c++14 category.cpp -o category -lstdc++

clean:
	rm -rf category
	find . \( -name "*.log" -o -name "*~" \) -exec rm -rf {} \; 
