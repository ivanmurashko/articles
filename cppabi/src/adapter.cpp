#define _GLIBCXX_USE_CXX11_ABI 0

#include "old.h"
namespace test {

std::__cxx11::string func(std::__cxx11::string input) {
  std::_cxx11::string res = func(input.c_str()).c_str();
  return res;
}

}
