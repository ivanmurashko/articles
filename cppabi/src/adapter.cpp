#include <string>
#include "adapter.h"
namespace test {

std::string func(std::string input) {
  std::string res = testadapter::func(input.c_str());
  return res;
}

}
