#include <iostream>
#include "exception.h"

int main() {
  std::exception_ptr eptr;
  try {
    test::func();
  } catch (...) {
    eptr = std::current_exception();
  }

  try {
    if (eptr) {
      std::rethrow_exception(eptr);
    }
  } catch (std::exception& ex) {
    std::cout << "std expection:" << ex.what() << std::endl;
  } catch (...) {
    std::cout << "Unknown expection" << std::endl;
  }
}
