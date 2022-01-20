#include <map>////
#include <vector>///
#include <iostream>

#include "../../container/map/tree.hpp"

int main(){
  ft::tree<char,int> mymap;

  mymap['a']=10;
  mymap['b']=20;
  mymap['d']=30;

  ft::pair<ft::tree<char,int>::iterator,ft::tree<char,int>::iterator> ret;
  ret = mymap.equal_range('c');

  std::cout << "lower bound points to: ";
  std::cout << ret.first->first << " => " << ret.first->second << '\n';

  std::cout << "upper bound points to: ";
  std::cout << ret.second->first << " => " << ret.second->second << '\n';

  return 0;
}