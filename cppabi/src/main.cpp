#include <iostream>
#include "old.h"

int main() {
  auto res = test::func("ABCD");
  std::cout << "Res:" << res << std::endl;
  return 0;
}
