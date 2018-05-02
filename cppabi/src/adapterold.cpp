#define _GLIBCXX_USE_CXX11_ABI 0
#include "adapter.h"
#include "old.h"

namespace testadapter {
const char* func(const char* input){
  return test::func(input).c_str();
}
}
