#include <map>////
#include <vector>///
#include <iostream>

#include "../../container/map/tree.hpp"

int main(){
	ft::tree<int, int> map;
	for (int i = -10, j = 1001, k = -13; i < 1000; i+=2, j-=13, k+=19) {
		map[i] = j;
		map[j] = k;
		map[k] = i;
	}
	// for (ft::tree<int, int>::iterator it = ++map.begin(); it != map.end(); it = ++map.begin())
	map.erase(map.begin(), map.end());
	map[10] = 100;
	map[-10] = -100;
	map[1000] = 1000;
	for (ft::tree<int, int>::iterator it = map.begin(); it != map.end(); ++it)
		std::cout<<it->first<<" "<<it->second<<std::endl;
	std::cout<<map.size()<<std::endl;
	return 0;
}