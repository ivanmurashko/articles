#include <iostream>
#include <functional>
#include <string>

std::function<bool(int)> isEven =
  [](int x)
  {
    return x % 2 == 0;                
  };

std::function<int(std::string)> stringLength =
  [](std::string s)
  {
    return static_cast<int>(s.size());
  };

// h = g . f
template < typename A, typename B, typename C> std::function<C(A)>
compose(std::function<C(B)> g, std::function<B(A)> f) 
{
  auto h = [f,g](A a)
         {
           B b = f(a);
           C c = g(b);
           return c;           
         };  
  return h;  
};

std::function<bool(std::string)> isStringLengthEven =
  compose<>(isEven, stringLength);

std::function<bool(bool)> id_bool =
  [](bool x)
  {
    return x;    
  };

std::function<std::string(std::string)> id_string =
  [](std::string x)
  {
    return x;    
  };

std::function<bool(std::string)> isStringLengthEvenLeft =
   compose<>(id_bool, isStringLengthEven);

std::function<bool(std::string)> isStringLengthEvenRight =
  compose<>(isStringLengthEven, id_string);


int main()
{
  std::cout << "3: " << isStringLengthEven("abc") << std::endl;  
  std::cout << "4: " << isStringLengthEven("abcd") << std::endl;  

  std::cout << "id . 3: " << isStringLengthEvenLeft("abc") << std::endl;  
  std::cout << "id . 4: " << isStringLengthEvenLeft("abcd") << std::endl;  

  std::cout << "3 . id: " << isStringLengthEvenRight("abc") << std::endl;  
  std::cout << "4 . id: " << isStringLengthEvenRight("abcd") << std::endl;  

  return 0;
}
