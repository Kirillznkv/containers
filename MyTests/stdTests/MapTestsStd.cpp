#include <map>////
#include <vector>///
#include <iostream>

#include "../../container/map/tree.hpp"

int main(){
  ft::tree<char,int> mymap;
  ft::tree<char,int>::iterator it;

  mymap['a']=50;
  mymap['b']=100;
  mymap['c']=150;
  mymap['d']=200;


  // print content:
  std::cout << "elements in mymap:" << '\n';
  std::cout << "a => " << mymap.find('a')->second << '\n';
  std::cout << "c => " << mymap.find('c')->second << '\n';
  std::cout << "l => " << mymap.find('l')->second << '\n';
  if (mymap.find('p') == mymap.end())
  	std::cout << "OOOOOK"<< '\n';
  if (mymap.find('d') == mymap.end())
  	std::cout << "KOOOOOOO"<< '\n';

  return 0;
}