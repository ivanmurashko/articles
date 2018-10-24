#include <iostream>
#include <functional>
#include <list>
#include <string>


template <class A, class B>
std::list<B> fmap(std::function<B(A)> f, std::list<A> a) {
  std::list<B> res;
  std::transform(a.begin(), a.end(), back_inserter(res), f);
  return res;
}

int main() 
{
  std::list<std::string> a = {"1", "2", "3"};
  std::function<int(std::string)> f = [](std::string s) {
    return 2 * atoi(s.c_str());
  };
  std::list<int> res = fmap<>(f, a);
  for (auto i : res) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return 0;
}
