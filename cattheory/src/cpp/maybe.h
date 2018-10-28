
#include <memory>
#include "monad.h"

template <class A> 
class Maybe
{
public:
  Maybe(A a) : a_(std::make_unique_ptr(a)) {};
  Maybe(A a) : isvalid_(true), a_(a) {};



  /// Destructor
  virtual ~Maybe();
private:
  /// Fake copy constructor
  Maybe(const Maybe &);

  /// Fake assigment operator
  Maybe &operator=(const Maybe &);
};
