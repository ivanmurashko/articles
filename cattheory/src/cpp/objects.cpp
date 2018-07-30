#include <utility>
#include <iostream>

int main()
{
  std::pair<int, bool> data(0, false);

  std::cout << "First projector: " << data.first << std::endl;
  std::cout << "Second projector: " << data.second << std::endl;

  return 0;
}
