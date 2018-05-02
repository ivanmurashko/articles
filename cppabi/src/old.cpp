#include <string>

namespace test {

std::string func(std::string input) {
  std::string res(input.rbegin(), input.rend());
  return res;
}

} // namespace test
