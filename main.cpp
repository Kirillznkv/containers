#include <iostream>
#include <deque>//??
#include <map>
#include <stack>
#include <vector>

#include "container.hpp"

int	main() {
	ft::Container<int> s;
	std::cout<<s.size()<<std::endl;
	s.push_back(1);
	s.push_back(2);
	s.push_back(3);
	s.push_front(4);
	std::cout<<s.begin()<<std::endl;
	std::cout<<s.end()<<std::endl;
	s.pop_front();
	std::cout<<s.size()<<std::endl;
	std::cout<<s.begin()<<std::endl;
	std::cout<<s.end()<<std::endl;
	return (0);
}
