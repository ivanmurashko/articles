#include <iostream>
#include "old.h"

int main() {
  auto res = test::func("ABCD");
  std::cout << "Res:" << res << std::endl;
  res = test::func("ABCDEFG");
  std::cout << "Res:" << res << std::endl;
  return 0;
}
