#include <utility>
#include <iostream>
#include <string>
#include <variant>

template <typename A, typename B> union Either
{
  A left;
  B right;  
};

template <typename A, typename B, typename C, typename D>
auto factor(A f, B g) {
  auto h = [f,g](std::variant<C, D> either) {
             C* left = std::get_if<C>(&either);
             if (left){
               return f(left);               
             }              
             D* right = std::get_if<D>(&either);
             return g(right);             
           };
  return h;
};

auto stringLength = [](std::string s) { return static_cast<int>(s.size()); };
auto id = [](auto x) { return x; };



int main()
{
  std::pair<int, bool> data(0, false);

  std::cout << "First projector: " << data.first << std::endl;
  std::cout << "Second projector: " << data.second << std::endl;

  std::variant<std::string, int> v;
  v = "abc";
  std::cout << "String length:" <<
    factor(stringLength, id)(v) << std::endl;
  v = 4;
  std::cout << "id(int):" <<
    factor(stringLength, id)(v) << std::endl;
  
  
  return 0;
}
