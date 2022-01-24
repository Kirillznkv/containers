#include <map>////
#include <vector>///
#include <iostream>

#include "../../container/map/tree.hpp"
#include "../../container/vector/vector.hpp"

int main(){
	ft::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	ft::vector<int>::reverse_iterator it = vec.rbegin() + 2;
	ft::vector<int>::iterator i = it.base();
	std::cout<<*it<<" "<<*i<<std::endl;


	std::vector<int> vec1;
	vec1.push_back(1);
	vec1.push_back(2);
	vec1.push_back(3);
	vec1.push_back(4);
	std::vector<int>::reverse_iterator it1 = vec1.rbegin() + 2;
	std::vector<int>::iterator i1 = it1.base();
	std::cout<<*it1<<" "<<*i1<<std::endl;
	return 0;
}