#include <map>////
#include <vector>///
#include <iostream>

#include "../../container/map/tree.hpp"
#include "../../container/vector/vector.hpp"
#include "../../container/utils.hpp"

int main(){
	std::vector<std::pair<int, int> > vec;
	vec.push_back(std::make_pair(1, 1));
	vec.push_back(std::make_pair(2, 3));
	vec.push_back(std::make_pair(3, 3));
	vec.push_back(std::make_pair(4, 4));
	std::vector<std::pair<int, int> >::reverse_iterator i = vec.rbegin() + 2;
	std::cout<<i[1].first<<" "<<i[1].second<<std::endl;

	std::cout<<"------------------------------"<<std::endl;

	ft::vector<ft::pair<int, int> > v;
	v.push_back(ft::make_pair(1, 1));
	v.push_back(ft::make_pair(2, 3));
	v.push_back(ft::make_pair(3, 3));
	v.push_back(ft::make_pair(4, 4));
	ft::vector<ft::pair<int, int> >::reverse_iterator inx = v.rbegin() + 2;
	std::cout<<inx[1].first<<" "<<inx[1].second<<std::endl;
	return 0;
}