#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main(){
  std::vector<int> data = {1, 1, 1, 1, 1, 1, 1, 1, 1, 
                           1, 1, 1, 1, 1, 1, 1, 1};
  auto comp = [](int i1, int i2) { return i1 <= i2; }; 
  std::sort(data.begin(), data.end(), comp);
  std::copy(data.begin(), data.end(),
            std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;
  return 0;
}

