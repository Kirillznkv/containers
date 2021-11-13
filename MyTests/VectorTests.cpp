#include <iostream>
#include <vector>
#include <stack>
#include "../srcs/vector.hpp"


#define TYPE_COLOR "\033[38;2;0;255;255m"
#define RESET_COLOR "\033[38;2;255;255;255;48;2;30;30;30m"

template <typename T>
void out(const T& v1,const T& v2){
	std::cout<<v1<<"\t\t\t"<<v2<<std::endl;
}
template <typename T1, typename T2>
void outSizes(const std::vector<T1>& v1,const ft::vector<T2>& v2){
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
	//Test front/back
	out(v1.front(), v2.front());
	out(++(v1.front()), ++(v2.front()));
	out(v1.back(), v2.back());
	out(++(v1.back()), ++(v2.back()));
	//Test [] / at()
	out(v1[1], v2[1]);
	out(v1.at(1), v2.at(1));
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
	std::vector<int> t1;
	ft::vector<int> t2;
	t1.resize(20);
	t2.resize(20);
	outSizes(t1, t2);
}

void	vectorTestDouble(){
	std::cout<<TYPE_COLOR"(DOUBLE)"RESET_COLOR<<std::endl;
	std::vector<double> v1;
	ft::vector<double> v2;
	for (double i = 0.01; i < 5.078; i += 0.035){
		v1.push_back(i);
		v2.push_back(i);
	}
	outSizes(v1, v2);
	std::vector<double> vec1;
	ft::vector<double> vec2;
	vec1.reserve(144);
	vec2.reserve(144);
	for (double i = 0.01; i < 5.078; i += 0.035){
		vec1.push_back(i);
		vec2.push_back(i);
	}
	outSizes(vec1, vec2);
	// Test base iterators
	std::vector<double>::iterator it1 = vec1.begin();
	ft::vector<double>::iterator it2 = vec2.begin();
	for (;it1 < vec1.end() && it2 < vec2.end(); it1 += 10, it2 += 10)
		std::cout<<*it1<<"\t\t"<<*it2<<std::endl;
}

void	vectorTestList(){
	std::cout<<TYPE_COLOR"(List)"RESET_COLOR<<std::endl;
	std::vector<std::vector<int> > v1;
	ft::vector<ft::vector<int> > v2;
	std::vector<int> vec1[5];
	ft::vector<int> vec2[5];
	for (int i = 0; i < 5; ++i){
		for (int val = 10; val < 1000; val += 13 + i){
			vec1[i].push_back(val);
			vec2[i].push_back(val);
		}
		v1.push_back(vec1[i]);
		v2.push_back(vec2[i]);
	}
	outSizes(v1, v2);
}

void	vectorTestIterator(){
	std::cout<<TYPE_COLOR"(Iterator)"RESET_COLOR<<std::endl;
	std::vector<char> stdVec;
	ft::vector<char> ftVec;
	for (char i = 'f'; i < 'z'; ++i){
		stdVec.push_back(i);
		ftVec.push_back(i);
	}
	std::vector<char>::iterator itStd;
	ft::vector<char>::iterator itFt;
	for (itStd = stdVec.begin(); itStd != stdVec.end(); ++itStd)
		std::cout<<*itStd;
	std::cout<<std::endl;
	for (itFt = ftVec.begin(); itFt != ftVec.end(); ++itFt)
		std::cout<<*itFt;
	std::cout<<std::endl;
	for (itStd = stdVec.begin(); itStd != stdVec.end(); itStd += 1)
		std::cout<<*itStd;
	std::cout<<std::endl;
	for (itFt = ftVec.begin(); itFt != ftVec.end(); itFt += 1)
		std::cout<<*itFt;
	std::cout<<std::endl;
	for (itStd = stdVec.begin(); itStd != stdVec.end(); itStd = itStd + 1)
		std::cout<<*itStd;
	std::cout<<std::endl;
	for (itFt = ftVec.begin(); itFt != ftVec.end(); itFt = itFt + 1)
		std::cout<<*itFt;
	std::cout<<std::endl;
	/////////////////////
	int i = 0;
	for (itStd = stdVec.begin(); itStd < stdVec.end(); itStd += 3, i += 3){
		++(*itStd);
		std::cout<<*itStd<<stdVec[i];
	}
	std::cout<<std::endl;
	i = 0;
	for (itFt = ftVec.begin(); itFt < ftVec.end(); itFt += 3, i += 3){
		++(*itFt);
		std::cout<<*itFt<<ftVec[i];
	}
	std::cout<<std::endl;
	i = stdVec.size() - 1;
	for (itStd = stdVec.end() - 1; itStd >= stdVec.begin(); itStd--, i--){
		std::cout<<*itStd<<stdVec[i];
	}
	std::cout<<std::endl;
	i = ftVec.size() - 1;
	for (itFt = ftVec.end() - 1; itFt >= ftVec.begin(); itFt--, i--){
		std::cout<<*itFt<<ftVec[i];
	}
	std::cout<<std::endl;
	/////////////////////
	std::vector<char> stdVec2;
	ft::vector<char> ftVec2;
	for (char i = 'A'; i <= 'Z'; ++i){
		stdVec2.push_back(i);
		ftVec2.push_back(i);
	}
	std::cout<<*(++stdVec2.begin())<<"   "<<*(++ftVec2.begin())<<std::endl;
	std::cout<<*(stdVec2.begin()++)<<"   "<<*(ftVec2.begin()++)<<std::endl;
}