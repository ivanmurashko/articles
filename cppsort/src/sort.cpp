#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

void print(const std::vector<int>& data) {
  std::ostream_iterator<int> out_it(std::cout, " ");
  std::copy(data.begin(), data.end(), out_it);
}


int main(){
  std::vector<int> data = {1, 1, 1, 1, 1, 1, 1, 1, 1, 
                           1, 1, 1, 1, 1, 1, 1, 1};
  auto comp = [](int i1, int i2) { return i1 <= i2; }; 
  std::sort(data.begin(), data.end(), comp);
  print(data);
  return 0;
}

