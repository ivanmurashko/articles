// gcc -g -O0 -std=c++03 str.cpp -o str -lstdc++

#include <iostream>
#include <string>
struct Data {
  std::string s;
};

void set(Data& data){
  std::string s = "abc";
  std::cout << (void*)(s.c_str()) << std::endl;  
  data.s = s;
  
}

int main() {
  Data data;
  set(data);
  std::cout << (void*)(data.s.c_str()) << std::endl;  
  return 0;
}
