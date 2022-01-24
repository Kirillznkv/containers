#include <map>////
#include <vector>///
#include <iostream>
#include <algorithm>

#include "../../container/map/map.hpp"
#include "../../container/vector/vector.hpp"
#include "../../container/utils.hpp"

int main(){
	ft::map<int, int> map;
	map[1] = 11;
	map[2] = 22;
	map[3] = 33;
	map[4] = 44;
	ft::map<int, int>::reverse_iterator it = map.rbegin() + 2;
	std::cout<<it->second<<std::endl;
	std::cout<<it.base()->second<<std::endl;
	return 0;
}