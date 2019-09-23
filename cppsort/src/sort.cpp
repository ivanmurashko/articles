#include <iostream>
#include <vector>
#include <algorithm>

void print(std::vector<int>& data) {
    for (int item : data) {
      std::cout << item << " ";
    }
    std::cout << std::endl;
}


int main(){
  std::vector<int> data = {1, 1, 1, 1, 1, 1, 1, 1, 1, 
                           1, 1, 1, 1, 1, 1, 1, 1};
  auto comp = [](int i1, int i2) { return i1 <= i2; }; 
  std::sort(data.begin(), data.end(), comp);
  print(data);
  return 0;
}

