#include <map>////
#include <vector>///
#include <iostream>

#include "../../container/map/tree.hpp"

int main(){
	ft::tree<int, int> map;

	map[1] = 1;
	ft::pair<ft::tree<int, int>::iterator,bool> p = map.insert(ft::make_pair(1, 10));
	std::cout<<(int)(p.second)<<" "<<map[1]<<std::endl;
	// for (ft::tree<int, int>::iterator it = map.begin(); it != map.end(); ++it)
	// 	std::cout<<it->first<<" "<<it->second<<std::endl;
	// std::cout<<map.size()<<std::endl;
	return 0;
}