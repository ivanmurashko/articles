#include <string>
#include "adapter.h"
namespace test {

std::string func(std::string input) {
  auto res = testadapter::func(std::vector<char>(input.begin(), input.end()));
  return std::string(res.data(), res.size());
}

}
