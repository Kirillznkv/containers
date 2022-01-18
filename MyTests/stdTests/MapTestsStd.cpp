#include <map>////
#include <vector>///
#include <iostream>

#include "../../container/map/tree.hpp"

int main(){
	std::map<int, int> m1;
	ft::tree<int, int> m2;

	m1[1] = 2;
	m1[2] = 3;
	m1[3] = 34234;
	int str = 1;
	m2[str] = 2;
	str = 2;
	m2[str] = 3;
	str = 3;
	m2[str] = 34234;

	 std::cout<<m1.begin()->second<<std::endl;
	std::cout<<m2.begin()->second<<std::endl;
//	std::cout<<(++m2.begin())->second<<std::endl;
	 std::cout<<(--m1.end())->second<<std::endl;
	 std::cout<<(--m2.end())->second<<std::endl;

	return (0);
}

//доминикано