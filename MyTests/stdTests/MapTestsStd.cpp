#include <map>////
#include <vector>///
#include <iostream>

#include "../../container/map/tree.hpp"

// using namespace std;

int main(){
	ft::tree<char, int> t;
	char ch = 'c';
	t[ch] = 1;
	ch = 'f';
	t[ch] = 5;
	std::cout<<t[ch]<<"("<<t.size()<<")"<<std::endl;
	return (0);
}