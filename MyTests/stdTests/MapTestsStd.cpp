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
	ft::tree<int, int>::reverse_iterator it = map.rbegin();
	std::cout<<it[1].first<<std::endl;
	return 0;
}