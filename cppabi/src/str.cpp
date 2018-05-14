#include <iostream>
#include <string>
void set(std::string& s){
  std::string s_ = "abc";
  std::cout << (void*)(s_.data()) << std::endl;  
  s = s_;
}
int main() {
  std::string s;
  set(s);
  std::cout << (void*)(s.data()) << std::endl;  
  return 0;
}
