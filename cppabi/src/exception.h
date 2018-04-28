#pragma once

#include <exception>
#include <string>

namespace test {

// custom exception
class Exception : public std::exception {
public:
  Exception();
  virtual ~Exception() throw();
  const char *what() const throw();
  const std::string whatstr() const throw();
};

// function to be called
void func();

} // namespace test
