#include <iostream>
#include <list>
struct Data {
  std::list<int> l;
};

void set(Data& data, std::list<int>& l){
  data.l = l;
}

int main() {
  Data data;
  std::list<int> l;
  l.push_back(1);
  l.push_back(2);
  std::cout << (void*)(&l.front()) << std::endl;
  set(data, l);
  std::cout << (void*)(&data.l.front()) << std::endl;  
  return 0;
}
