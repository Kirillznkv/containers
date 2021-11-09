#include <iostream>
#include <vector>
#include "../srcs/vector.hpp"
#include <sstream>


#define TYPE_COLOR "\033[38;2;0;255;255m"
#define RESET_COLOR "\033[38;2;255;255;255;48;2;30;30;30m"

template <typename T>
void out(const T& v1,const T& v2){
	std::cout<<v1<<"\t\t\t"<<v2<<std::endl;
}
template <typename T>
void outSizes(const std::vector<T>& v1,const ft::vector<T>& v2){
	std::cout<<"size:\t\t"<<v1.size()<<"\t\t\t\t\t"<<v2.size()<<std::endl;
	std::cout<<"capacity:\t"<<v1.capacity()<<"\t\t\t\t\t"<<v2.capacity()<<std::endl;
	std::cout<<"max_size:\t"<<v1.max_size()<<"\t\t\t"<<v2.max_size()<<std::endl;
}

void	vectorTestBase(){
	std::cout<<TYPE_COLOR"(Base)"RESET_COLOR<<std::endl;
	//Test size, capacity, max_size
	std::vector<int> v1;
	ft::vector<int> v2;
	outSizes(v1, v2);
	v1.push_back(21);
	v2.push_back(21);
	outSizes(v1, v2);
	v1.push_back(42);
	v2.push_back(42);
	outSizes(v1, v2);
	//Test reserve
	std::vector<int> vec1;
	ft::vector<int> vec2;
	vec1.reserve(100);
	vec2.reserve(100);
	outSizes(vec1, vec2);
	vec1.push_back(21);
	vec2.push_back(21);
	outSizes(vec1, vec2);
	vec1.push_back(42);
	vec2.push_back(42);
	outSizes(vec1, vec2);
	//Test resize
	v1.resize(2);
	v2.resize(2);
	outSizes(v1, v2);
	v1.resize(12);
	v2.resize(12);
	outSizes(v1, v2);
	v1.resize(1);
	v2.resize(1);
	outSizes(v1, v2);
}

void	vectorTestInt(){
	std::cout<<TYPE_COLOR"(INT)"RESET_COLOR<<std::endl;
}

void	vectorTestString(){
}

void	vectorTestList(){
	std::cout<<TYPE_COLOR"(List)"RESET_COLOR<<std::endl;
}