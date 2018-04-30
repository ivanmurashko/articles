#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <map>

int main() {
  std::vector<int> v;
  std::cout << "std::vector: " << sizeof(v) << std::endl;  
  std::queue<int> q;
  std::cout << "std::queue: " << sizeof(q) << std::endl;  
  std::priority_queue<int> pq;
  std::cout << "std::priority_queue: " << sizeof(pq) << std::endl;  
  std::deque<int> dq;
  std::cout << "std::deque: " << sizeof(dq) << std::endl;  
  std::stack<int> st;
  std::cout << "std::stack: " << sizeof(st) << std::endl;  
  std::set<int> s;
  std::cout << "std::set: " << sizeof(s) << std::endl;  
  std::multiset<int> ms;
  std::cout << "std::multiset: " << sizeof(ms) << std::endl;  
  std::map<int,int> m;
  std::cout << "std::map: " << sizeof(m) << std::endl;  
  std::multimap<int,int> mm;
  std::cout << "std::multimap: " << sizeof(mm) << std::endl;  
  std::list<int> l;
  std::cout << "std::list: " << sizeof(l) << std::endl;  
  std::string str;
  std::cout << "std::string: " << sizeof(str) << std::endl;  
  return 0;
}
