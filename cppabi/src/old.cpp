#include "exception.h"

namespace test {

Exception::Exception(){};
Exception::~Exception() throw() {};
const char *Exception::what() const throw() { return "Custom exception"; }
const std::string Exception::whatstr() const throw() { return "Custom exception"; }


void func() { throw Exception(); }

} // namespace test
