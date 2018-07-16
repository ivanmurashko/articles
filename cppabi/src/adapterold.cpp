#define _GLIBCXX_USE_CXX11_ABI 0
#include "adapter.h"
#include "old.h"

namespace testadapter {
std::vector<char> func(std::vector<char> input){
  auto res = test::func(std::string(input.data(), input.size()));
  return std::vector<char>(res.begin(), res.end());
}
}
