#include <map>////
#include <vector>///
#include <iostream>

#include "../../container/map/tree.hpp"

int main(){
	ft::tree<int, int> map;
	map[0] = 10;
	map[10] = 100;
	map.erase(0);
	for (ft::tree<int, int>::iterator it = map.begin(); it != map.end(); ++it)
		std::cout<<"map["<<it->first<<"] = "<<it->second<<std::endl;
	return 0;
}