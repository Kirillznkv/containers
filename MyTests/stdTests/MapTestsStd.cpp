#include <map>////
#include <vector>///
#include <iostream>

#include "../../container/map/tree.hpp"

int main(){
	ft::tree<int, int> map;

	map[1] = 1;
	map[2] = 2;
	map[3] = 3;
	ft::tree<int, int> map2;
	map2.insert(map.begin(), map.end());
	for (ft::tree<int, int>::iterator it = map2.begin(); it != map2.end(); ++it)
		std::cout<<it->first<<" "<<it->second<<std::endl;
	// std::cout<<map.size()<<std::endl;
	return 0;
}