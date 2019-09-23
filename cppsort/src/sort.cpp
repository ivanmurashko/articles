// Invalid comparator produces SIGSEGV

#include <iostream>
#include <vector>
#include <algorithm>

void print(std::vector<int>& data) {
    std::cout << "{";
    for (int item : data) {
      std::cout << item << ", ";
    }
    std::cout << "}" << std::endl;
}


int main(){
  std::vector<int> data = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

  // the comparator is not strict weak ordering
  auto comp = [](int i1, int i2) { return i1 <= i2; };
 
  // The following code that distribute data based on pivot
  // Hoare partition scheme
  // https://en.wikipedia.org/wiki/Quicksort#Hoare_partition_scheme
  // template<typename _RandomAccessIterator, typename _Compare>
  //   _RandomAccessIterator
  //   __unguarded_partition(_RandomAccessIterator __first,
  //   		  _RandomAccessIterator __last,
  //   		  _RandomAccessIterator __pivot, _Compare __comp)
  //   {
  //     while (true)
  //   {
  //     while (__comp(__first, __pivot))
  //       ++__first;
  //     --__last;
  //     while (__comp(__pivot, __last))
  //       --__last;
  //     if (!(__first < __last))
  //       return __first;
  //     std::iter_swap(__first, __last);
  //     ++__first;
  //   }
  //   }
  // the __first iterator icreamented until gets into the end of vector
  // as result we will get the SIGSEGV

  std::sort(data.begin(), data.end(), comp);
  print(data);
  return 0;
}

