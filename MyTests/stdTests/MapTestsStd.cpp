#include <map>////
#include <vector>///
#include <iostream>
#include <algorithm>

#include "../../container/map/tree.hpp"
#include "../../container/vector/vector.hpp"
#include "../../container/utils.hpp"

int main(){
	ft::tree<int, int> map;
	map[1] = 11;
	map[2] = 22;
	map[3] = 33;
	map[4] = 44;
	ft::tree<int, int>::reverse_iterator it = map.rbegin() + 2;
	std::cout<<it->second<<std::endl;
	std::cout<<it.base()->second<<std::endl;
	return 0;
}