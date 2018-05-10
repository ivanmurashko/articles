#include <iostream>
#include <string>
struct Data {
  std::string s;
};
void set(Data& data){
  std::string s = "abc";
  std::cout << (void*)(s.data()) << std::endl;  
  data.s = s;
}
int main() {
  Data data;
  set(data);
  std::cout << (void*)(data.s.data()) << std::endl;  
  return 0;
}
