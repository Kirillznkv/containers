#include <iostream>
#include <map>//
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
template <typename T>
void boolTest(T v1, T v2, int i){
	std::cout	<<(int)(v1 == v2)<<" " \
				<<(int)(v1 != v2)<<" " \
				<<(int)(v1 <= v2)<<" " \
				<<(int)(v1 >= v2)<<" " \
				<<(int)(v1 < v2)<<" " \
				<<(int)(v1 > v2)<<std::endl;
	i++;
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
	//Test create
	std::vector<int> ve(2, 1);
	ft::vector<int> ve2(2, 1);
	outSizes(ve, ve2);
	out(ve.front(), ve2.front());
	std::vector<int> ve1(2);
	ft::vector<int> ve12(2);
	outSizes(ve1, ve12);
	out(ve1.front(), ve12.front());
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
	// Test ++ -- += -= ...
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
	///////////////////// Test rewrite Variable value
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
	///////////////////// Test post++ prev++ iterator
	std::vector<char> stdVec2;
	ft::vector<char> ftVec2;
	for (char i = 'A'; i <= 'Z'; ++i){
		stdVec2.push_back(i);
		ftVec2.push_back(i);
	}
	std::cout<<*(++stdVec2.begin())<<"\t"<<*(++ftVec2.begin())<<std::endl;
	std::cout<<*(stdVec2.begin()++)<<"\t"<<*(ftVec2.begin()++)<<std::endl;
	///////////////////// Test it - it and it - variable
	std::vector<char>::iterator it1Beg = stdVec2.begin();
	std::vector<char>::iterator it1End = stdVec2.end();
	ft::vector<char>::iterator it2Beg = ftVec2.begin();
	ft::vector<char>::iterator it2End = ftVec2.end();
	std::cout<<*(it1End - 1)<<"\t"<<*(it2End - 1)<<std::endl;
	std::cout<<it1End - it1Beg<<"\t"<<it2End - it2Beg<<std::endl;
}

void vectorTestReverseIterator(){
	std::cout<<TYPE_COLOR"(Reverse Iterator)"RESET_COLOR<<std::endl;
	// Test ++ -- += -= ...
	std::vector<char> stdVec;
	ft::vector<char> ftVec;
	for (char i = 'f'; i < 'z'; ++i){
		stdVec.push_back(i);
		ftVec.push_back(i);
	}
	std::vector<char>::reverse_iterator itStd;
	ft::vector<char>::reverse_iterator itFt;
	for (itStd = stdVec.rbegin(); itStd != stdVec.rend(); ++itStd)
		std::cout<<*itStd;
	std::cout<<std::endl;
	for (itFt = ftVec.rbegin(); itFt != ftVec.rend(); ++itFt)
		std::cout<<*itFt;
	std::cout<<std::endl;
	for (itStd = stdVec.rbegin(); itStd != stdVec.rend(); itStd += 1)
		std::cout<<*itStd;
	std::cout<<std::endl;
	for (itFt = ftVec.rbegin(); itFt != ftVec.rend(); itFt += 1)
		std::cout<<*itFt;
	std::cout<<std::endl;
	for (itStd = stdVec.rbegin(); itStd != stdVec.rend(); itStd = itStd + 1)
		std::cout<<*itStd;
	std::cout<<std::endl;
	for (itFt = ftVec.rbegin(); itFt != ftVec.rend(); itFt = itFt + 1)
		std::cout<<*itFt;
	std::cout<<std::endl;
	///////////////////// Test rewrite Variable value
	int i = 0;
	for (itStd = stdVec.rbegin(); itStd < stdVec.rend(); itStd += 3, i += 3){
		++(*itStd);
		std::cout<<*itStd<<stdVec[i];
	}
	std::cout<<std::endl;
	i = 0;
	for (itFt = ftVec.rbegin(); itFt < ftVec.rend(); itFt += 3, i += 3){
		++(*itFt);
		std::cout<<*itFt<<ftVec[i];
	}
	std::cout<<std::endl;
	i = stdVec.size() - 1;
	for (itStd = stdVec.rend() - 1; itStd >= stdVec.rbegin(); itStd--, i--){
		std::cout<<*itStd<<stdVec[i];
	}
	std::cout<<std::endl;
	i = ftVec.size() - 1;
	for (itFt = ftVec.rend() - 1; itFt >= ftVec.rbegin(); itFt--, i--){
		std::cout<<*itFt<<ftVec[i];
	}
	std::cout<<std::endl;
	///////////////////// Test post++ prev++ iterator
	std::vector<char> stdVec2;
	ft::vector<char> ftVec2;
	for (char i = 'A'; i <= 'Z'; ++i){
		stdVec2.push_back(i);
		ftVec2.push_back(i);
	}
	std::cout<<*(++stdVec2.rbegin())<<"\t"<<*(++ftVec2.rbegin())<<std::endl;
	std::cout<<*(stdVec2.rbegin()++)<<"\t"<<*(ftVec2.rbegin()++)<<std::endl;
	///////////////////// Test it - it and it - variable
	std::vector<char>::reverse_iterator it1Beg = stdVec2.rbegin();
	std::vector<char>::reverse_iterator it1End = stdVec2.rend();
	ft::vector<char>::reverse_iterator it2Beg = ftVec2.rbegin();
	ft::vector<char>::reverse_iterator it2End = ftVec2.rend();
	std::cout<<*(it1End - 1)<<"\t"<<*(it2End - 1)<<std::endl;
	std::cout<<it1End - it1Beg<<"\t"<<it2End - it2Beg<<std::endl;
}

void	vectorTestModifiers(){
	std::cout<<TYPE_COLOR"(Modifiers)"RESET_COLOR<<std::endl;
	///////////////////// Test assign #1
	std::vector<int> v1, v1New;
	ft::vector<int> v2, v2New;
	for (int i = 0; i < 10; ++i){
		v1.push_back(i);
		v2.push_back(i);
	}
	for (int i = 0; i < 100; ++i){
		v1New.push_back(i);
		v2New.push_back(i);
	}
								outSizes(v1, v2);
								outSizes(v1New, v2New);
								v1.assign(5, 123);
								v2.assign(5, 123);
								outSizes(v1, v2);
								v1.assign(50, 2);
								v2.assign(50, 2);
								outSizes(v1, v2);
	///////////////////// Test assign #2
	v1.assign(v1New.begin(), v1New.end());
	v2.assign(v2New.begin(), v2New.end());
	outSizes(v1, v2);
	v1.assign(v1New.begin(), v1New.begin() + 10);
	v2.assign(v2New.begin(), v2New.begin() + 10);
	outSizes(v1, v2);
	int myints[] = {1776,7,4};
	v1.assign(myints,myints+3);
	v2.assign(myints,myints+3);
	outSizes(v1, v2);
	///////////////////// Test insert #1
	std::vector<int>::iterator it = v1.insert(v1.begin(), 100);
	ft::vector<int>::iterator it2 = v2.insert(v2.begin(), 100);
	for (int i = 0; i < (int)v1.size(); ++i)
		std::cout<<v1[i]<<" ";
	std::cout<<"\t"<<*it<<std::endl;
	for (int i = 0; i < (int)v2.size(); ++i)
		std::cout<<v2[i]<<" ";
	std::cout<<"\t"<<*it2<<std::endl;
	outSizes(v1, v2);
	///////////////////// Test insert #2
		v1.insert(v1.begin(), 5, 1);
		v2.insert(v2.begin(), 5, 1);
		for (int i = 0; i < (int)v1.size(); ++i)
			std::cout<<v1[i]<<" ";
		std::cout<<"\t"<<*it<<std::endl;
		for (int i = 0; i < (int)v2.size(); ++i)
			std::cout<<v2[i]<<" ";
		std::cout<<"\t"<<*it2<<std::endl;
		outSizes(v1, v2);
	///////////////////// Test insert #3
	std::vector<int> putVec1(10, 0);
	ft::vector<int> putVec2(10, 0);
	v1.insert(v1.begin() + 1, putVec1.begin(), putVec1.end());
	v2.insert(v2.begin() + 1, putVec2.begin(), putVec2.end());
	for (int i = 0; i < (int)v1.size(); ++i)
		std::cout<<v1[i]<<" ";
	std::cout<<"\t"<<*it<<std::endl;
	for (int i = 0; i < (int)v2.size(); ++i)
		std::cout<<v2[i]<<" ";
	std::cout<<"\t"<<*it2<<std::endl;
	outSizes(v1, v2);
	///////////////////// Test erase #1
	std::vector<int>::iterator itEr1 = v1.erase(v1.end() - 3);
	ft::vector<int>::iterator itEr2 = v2.erase(v2.end() - 3);
	for (int i = 0; i < (int)v1.size(); ++i)
		std::cout<<v1[i]<<" ";
	std::cout<<"\t"<<*it<<std::endl;
	for (int i = 0; i < (int)v2.size(); ++i)
		std::cout<<v2[i]<<" ";
	std::cout<<"\t"<<*it2<<std::endl;
	out(*itEr1, *itEr2);
	outSizes(v1, v2);
	///////////////////// Test erase #2
	std::vector<int>::iterator itEr12 = v1.erase(v1.begin(), v1.end() - 3);
	ft::vector<int>::iterator itEr22 = v2.erase(v2.begin(), v2.end() - 3);
	for (int i = 0; i < (int)v1.size(); ++i)
		std::cout<<v1[i]<<" ";
	std::cout<<"\t"<<*it<<std::endl;
	for (int i = 0; i < (int)v2.size(); ++i)
		std::cout<<v2[i]<<" ";
	std::cout<<"\t"<<*it2<<std::endl;
	out(*itEr12, *itEr22);
	outSizes(v1, v2);
	///////////////////// Test swap
	{
	std::vector<int> v1(20, 5);
	std::vector<int> putVec1(10, 0);
	ft::vector<int> v2(20, 5);
	ft::vector<int>  putVec2(10, 0);
	v1.swap(putVec1);
	v2.swap(putVec2);
	for (int i = 0; i < (int)v1.size(); ++i)
		std::cout<<v1[i];
	std::cout<<" (";
	for (int i = 0; i < (int)putVec1.size(); ++i)
		std::cout<<putVec1[i];
	std::cout<<")"<<std::endl;
	for (int i = 0; i < (int)v2.size(); ++i)
		std::cout<<v2[i];
	std::cout<<" (";
	for (int i = 0; i < (int)putVec2.size(); ++i)
		std::cout<<putVec2[i];
	std::cout<<")"<<std::endl;
	outSizes(v1, v2);
	outSizes(putVec1, putVec2);
	}
	///////////////////// Test clear
	std::vector<int> myvector;
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);
	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << std::endl;
	myvector.clear();
	myvector.push_back (1101);
	myvector.push_back (2202);
	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << std::endl;

	ft::vector<int> myvector2;
	myvector2.push_back (100);
	myvector2.push_back (200);
	myvector2.push_back (300);
	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector2.size(); i++)
		std::cout << ' ' << myvector2[i];
	std::cout << std::endl;
	myvector2.clear();
	myvector2.push_back (1101);
	myvector2.push_back (2202);
	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector2.size(); i++)
		std::cout << ' ' << myvector2[i];
	std::cout << std::endl;
	outSizes(myvector, myvector2);
}

void vectorTestExept(){
	std::cout<<TYPE_COLOR"(Exeption)"RESET_COLOR<<std::endl;
	///////////////////// Test at
	std::vector<long long> v1;
	ft::vector<long long> v2;
	try { std::cout<<v1.at(0)<<std::endl; }
	catch (std::exception &e) { std::cout<<"Error1: "<<e.what()<<std::endl; }
	try { std::cout<<v2.at(0)<<std::endl; }
	catch (std::exception &e) { std::cout<<"Error1: "<<e.what()<<std::endl; }
	///////////////////// Test erase
	// v1.push_back(1);
	try { v1.resize(-10, 12); }
	catch (std::exception &e) { std::cout<<"Error2: "<<e.what()<<std::endl; }
	try { v2.resize(-10, 12); }
	catch (std::exception &e) { std::cout<<"Error2: "<<e.what()<<std::endl; }
}

void vectorTestRelationalOperators(){
	std::cout<<TYPE_COLOR"(vectorTestRelationalOperators)"RESET_COLOR<<std::endl;
	std::vector<int> std1;
	std::vector<int> std2;
	std::vector<int> std11;
	std::vector<int> std12;
	ft::vector<int> ft1;
	ft::vector<int> ft2;
	ft::vector<int> ft11;
	ft::vector<int> ft12;
	std1.push_back(1);
	std2.push_back(2);
	std11.push_back(1);
	std11.push_back(1);
	std12.push_back(1);
	std12.push_back(2);
	ft1.push_back(1);
	ft2.push_back(2);
	ft11.push_back(1);
	ft11.push_back(1);
	ft12.push_back(1);
	ft12.push_back(2);
	///////////////////// Test == != < <= > >=
	boolTest(std11, std11, 100);
	boolTest(ft11, ft11, 100);
	std::cout<<"---";
	boolTest(std11, std12, 100);
	std::cout<<"---";
	boolTest(ft11, ft12, 100);
	boolTest(std1, std11, 100);
	boolTest(ft1, ft11, 100);
	std::cout<<"---";
	boolTest(std12, std11, 100);
	std::cout<<"---";
	boolTest(ft12, ft11, 100);
	boolTest(std11, std1, 100);
	boolTest(ft11, ft1, 100);
	std::cout<<"---";
	boolTest(std11, std2, 100);
	std::cout<<"---";
	boolTest(ft11, ft2, 100);
}