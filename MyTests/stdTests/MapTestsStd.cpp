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
	m2["hello10"] = 2;
	m2["hello20"] = 3;
	m2["hello15"] = 34234;

	for (std::map<std::string, int>::iterator it = --m1.end(); it != m1.begin(); --it)
		std::cout<<"["<<(*it).first<<"] = "<<(*it).second<<std::endl;
	for (ft::tree<std::string, int>::iterator it = --m2.end(); it != m2.begin(); --it)
		std::cout<<"["<<(*it).first<<"] = "<<(*it).second<<std::endl;

	 for (std::map<std::string, int>::iterator it = --m1.end(); it != m1.begin(); it--)
	 	std::cout<<"["<<(*it).first<<"] = "<<(*it).second<<std::endl;
	 for (ft::tree<std::string, int>::iterator it = --m2.end(); it != m2.begin(); it--)
	 	std::cout<<"["<<(*it).first<<"] = "<<(*it).second<<std::endl;

	std::cout<<"------------------------------------------------"<<std::endl;
	
	for (std::map<std::string, int>::reverse_iterator it = m1.rbegin(); it != m1.rend(); ++it)
		std::cout<<"["<<(*it).first<<"] = "<<(*it).second<<std::endl;
	for (ft::tree<std::string, int>::reverse_iterator it = m2.rbegin(); it != m2.rend(); ++it)
		std::cout<<"["<<(*it).first<<"] = "<<(*it).second<<std::endl;

	return (0);
}