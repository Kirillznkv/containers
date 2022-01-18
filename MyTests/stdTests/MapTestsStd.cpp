#include <map>////
#include <vector>///
#include <iostream>

#include "../../container/map/tree.hpp"

int main(){
	std::map<std::string, int> m1;
	ft::tree<std::string, int> m2;

	m1["hello10"] = 2;
	m1["hello20"] = 3;
	m1["hello15"] = 34234;
	std::string str = "hello10";
	m2[str] = 2;
	str = "hello20";
	m2[str] = 3;
	str = "hello15";
	m2[str] = 34234;

	for (std::map<std::string, int>::iterator it = m1.begin(); it != m1.end(); ++it)
		std::cout<<"["<<(*it).first<<"] = "<<(*it).second<<std::endl;
	for (ft::tree<std::string, int>::iterator it = m2.begin(); it != m2.end(); ++it)
		std::cout<<"["<<(*it).first<<"] = "<<(*it).second<<std::endl;

	 for (std::map<std::string, int>::iterator it = m1.begin(); it != m1.end(); it++)
	 	std::cout<<"["<<(*it).first<<"] = "<<(*it).second<<std::endl;
	 for (ft::tree<std::string, int>::iterator it = m2.begin(); it != m2.end(); it++)
	 	std::cout<<"["<<(*it).first<<"] = "<<(*it).second<<std::endl;

	return (0);
}