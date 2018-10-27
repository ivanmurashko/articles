#include <functional>

template < template< class ...> class M, class A, class B> 
M<B> fmap(std::function<B(A)>, M<A>);

template < template< class ...> class M, class A> 
M<A> pure(A);

template < template< class ...> class M, class A> 
M<A> join(M< M<A> >);

template < template< class ...> class M, class A, class B> 
M<B> bind(M<A> a, std::function< M<B> (A) > f) {
  return join( fmap(f, a) );
};
