#include <utility>
#include <iostream>
#include <string>
#include <stdexcept>

template <typename A, typename B> class Either
{
public:
  Either(const A& l) : left_(l), is_left_(true){    
  }
  Either(const B& r) : right_(r), is_left_(false){    
  }
  const A& left() const {
    if (!is_left_){
      throw std::logic_error("no left");      
    }    
    return left_;    
  }
  const B& right() const {
    if (is_left_){
      throw std::logic_error("no right");      
    }    
    return right_;    
  }
private:
  A left_;
  B right_;
  bool is_left_;  
};

template <typename A, typename B, typename C, typename D>
auto factor(A f, B g, const Either<C, D>& either) {
  try {
    return f(either.left());               
  }
  catch(...) {
    return g(either.right());                              
  }
};

auto stringLength = [](std::string s) { return static_cast<int>(s.size()); };
auto id = [](auto x) { return x; };

int main()
{
  std::pair<int, bool> data(0, false);

  std::cout << "First projector: " << data.first << std::endl;
  std::cout << "Second projector: " << data.second << std::endl;

  Either<std::string, int> str = std::string("abc");
  std::cout << "String length:" <<
    factor<>(stringLength, id, str) << std::endl;
  Either<std::string, int> i = 4;
  std::cout << "id(int):" <<
    factor<>(stringLength, id, i) << std::endl;
  
  
  return 0;
}
