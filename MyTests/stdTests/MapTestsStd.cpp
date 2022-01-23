#include <map>////
#include <vector>///
#include <iostream>

#include "../../container/map/tree.hpp"

int main(){
	std::map<int, int> map;
	for (int i = -10, j = 1001, k = -13; i < 1000; i+=2, j-=13, k+=19) {
		map[i] = j;
		map[j] = k;
		map[k] = i;
	}
	 std::cout<<map.size()<<std::endl;
	 for (int i = -100; i < 1000; i += 2)
	 	map.erase(i);
	 // map.erase(-10);
	 std::cout<<map.size()<<std::endl;
	return 0;
}