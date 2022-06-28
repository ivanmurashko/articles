// calculate fibonacci numbers
unsigned int fib(unsigned int n) {
  if (n <= 1) {
    return 1;
  }
  return fib(n - 1) + fib(n - 2);
}
