#define _GLIBCXX_USE_CXX11_ABI 0
#include "adapter.h"
#include "old.h"

namespace testadapter {
const char* func(const char* input){
  thread_local std::string res;
  res = test::func(input);
  return res.c_str();
}
}
