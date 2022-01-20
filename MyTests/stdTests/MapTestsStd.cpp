#include <map>////
#include <vector>///
#include <iostream>

#include "../../container/map/tree.hpp"

int main(){
  ft::tree<char,int> mymap;
  ft::tree<char,int>::iterator itlow,itup;

  mymap['a']=20;
  mymap['b']=40;
  mymap['c']=60;
  mymap['d']=80;
  mymap['e']=100;

  itlow=mymap.lower_bound ('b');  // itlow points to b
  itup=mymap.upper_bound ('d');   // itup points to e (not d!)

	std::cout<<itlow->first<<" "<<itup->first<<std::endl;

  return 0;
}