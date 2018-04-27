#pragma once

#include <exception>

namespace test {

// custom exception
class Exception : public std::exception {
public:
  Exception(){};
  virtual ~Exception() throw(){};
  const char *what() const throw() { return "Custom exception"; }
};

// function to be called
void func();

} // namespace test
