#include <vector>
#include "VectorTests.hpp"

void	vectorTestBaseStd(){
	//Test size, capacity, max_size
	std::vector<int> v1;
	outSizes(v1);
	v1.push_back(21);
	outSizes(v1);
	v1.push_back(42);
	outSizes(v1);
	//Test front/back
	std::cout<<v1.front()<<std::endl;
	std::cout<<++(v1.front())<<std::endl;
	std::cout<<v1.back()<<std::endl;
	std::cout<<++(v1.back())<<std::endl;
	//Test [] / at()
	std::cout<<v1[1]<<std::endl;
	std::cout<<v1.at(1)<<std::endl;
	//Test reserve
	std::vector<int> vec1;
	vec1.reserve(100);
	outSizes(vec1);
	vec1.push_back(21);
	outSizes(vec1);
	vec1.push_back(42);
	outSizes(vec1);
	//Test resize
	v1.resize(2);
	outSizes(v1);
	v1.resize(12);
	outSizes(v1);
	v1.resize(1);
	outSizes(v1);
	std::vector<int> t1;
	t1.resize(20);
	outSizes(t1);
	//Test create
	std::vector<int> ve(2, 1);
	outSizes(ve);
	std::cout<<ve.front()<<std::endl;
	std::vector<int> ve1(2);
	outSizes(ve1);
	std::cout<<ve1.front()<<std::endl;
}

void	vectorTestDoubleStd(){
	std::vector<double> v1;
	for (double i = 0.01; i < 5.078; i += 0.035)
		v1.push_back(i);
	outSizes(v1);
	std::vector<double> vec1;
	vec1.reserve(144);
	for (double i = 0.01; i < 5.078; i += 0.035)
		vec1.push_back(i);
	outSizes(vec1);
	// Test base iterators
	std::vector<double>::iterator it1 = vec1.begin();
	for (;it1 < vec1.end(); it1 += 10)
		std::cout<<*it1<<std::endl;
}

void	vectorTestListStd(){
	std::vector<std::vector<int> > v1;
	std::vector<int> vec1[5];
	for (int i = 0; i < 5; ++i){
		for (int val = 10; val < 1000; val += 13 + i)
			vec1[i].push_back(val);
		v1.push_back(vec1[i]);
	}
	outSizes(v1);
}

void	vectorTestIteratorStd(){
	// Test ++ -- += -= ...
	std::vector<char> stdVec;
	for (char i = 'f'; i < 'z'; ++i)
		stdVec.push_back(i);
	std::vector<char>::iterator itStd;
	for (itStd = stdVec.begin(); itStd != stdVec.end(); ++itStd)
		std::cout<<*itStd;
	std::cout<<std::endl;
	for (itStd = stdVec.begin(); itStd != stdVec.end(); itStd += 1)
		std::cout<<*itStd;
	std::cout<<std::endl;
	for (itStd = stdVec.begin(); itStd != stdVec.end(); itStd = itStd + 1)
		std::cout<<*itStd;
	std::cout<<std::endl;
	///////////////////// Test rewrite Variable value
	int i = 0;
	for (itStd = stdVec.begin(); itStd < stdVec.end(); itStd += 3, i += 3){
		++(*itStd);
		std::cout<<*itStd<<stdVec[i];
	}
	std::cout<<std::endl;
	i = stdVec.size() - 1;
	for (itStd = stdVec.end() - 1; itStd >= stdVec.begin(); itStd--, i--){
		std::cout<<*itStd<<stdVec[i];
	}
	std::cout<<std::endl;
	///////////////////// Test post++ prev++ iterator
	std::vector<char> stdVec2;
	for (char i = 'A'; i <= 'Z'; ++i)
		stdVec2.push_back(i);
	std::cout<<*(++stdVec2.begin())<<std::endl;
	std::cout<<*(stdVec2.begin()++)<<std::endl;
	///////////////////// Test it - it and it - variable
	std::vector<char>::iterator it1Beg = stdVec2.begin();
	std::vector<char>::iterator it1End = stdVec2.end();
	std::cout<<*(it1End - 1)<<std::endl;
	std::cout<<it1End - it1Beg<<std::endl;
}

void vectorTestReverseIteratorStd(){
	// Test ++ -- += -= ...
	std::vector<char> stdVec;
	for (char i = 'f'; i < 'z'; ++i)
		stdVec.push_back(i);
	std::vector<char>::reverse_iterator itStd;
	for (itStd = stdVec.rbegin(); itStd != stdVec.rend(); ++itStd)
		std::cout<<*itStd;
	std::cout<<std::endl;
	for (itStd = stdVec.rbegin(); itStd != stdVec.rend(); itStd += 1)
		std::cout<<*itStd;
	std::cout<<std::endl;
	for (itStd = stdVec.rbegin(); itStd != stdVec.rend(); itStd = itStd + 1)
		std::cout<<*itStd;
	std::cout<<std::endl;
	///////////////////// Test rewrite Variable value
	int i = 0;
	for (itStd = stdVec.rbegin(); itStd < stdVec.rend(); itStd += 3, i += 3){
		++(*itStd);
		std::cout<<*itStd<<stdVec[i];
	}
	std::cout<<std::endl;
	i = stdVec.size() - 1;
	for (itStd = stdVec.rend() - 1; itStd >= stdVec.rbegin(); itStd--, i--){
		std::cout<<*itStd<<stdVec[i];
	}
	///////////////////// Test post++ prev++ iterator
	std::vector<char> stdVec2;
	for (char i = 'A'; i <= 'Z'; ++i)
		stdVec2.push_back(i);
	std::cout<<*(++stdVec2.rbegin())<<std::endl;
	std::cout<<*(stdVec2.rbegin()++)<<std::endl;
	///////////////////// Test it - it and it - variable
	std::vector<char>::reverse_iterator it1Beg = stdVec2.rbegin();
	std::vector<char>::reverse_iterator it1End = stdVec2.rend();
	std::cout<<*(it1End - 1)<<std::endl;
	std::cout<<it1End - it1Beg<<std::endl;
}

void	vectorTestModifiersStd(){
	///////////////////// Test assign #1
	std::vector<int> v1, v1New;
	for (int i = 0; i < 10; ++i)
		v1.push_back(i);
	for (int i = 0; i < 100; ++i)
		v1New.push_back(i);
	outSizes(v1);
	outSizes(v1New);
	v1.assign(5, 123);
	outSizes(v1);
	v1.assign(50, 2);
	outSizes(v1);
	///////////////////// Test assign #2
	v1.assign(v1New.begin(), v1New.end());
	outSizes(v1);
	v1.assign(v1New.begin(), v1New.begin() + 10);
	outSizes(v1);
	int myints[] = {1776,7,4};
	v1.assign(myints,myints+3);
	outSizes(v1);
	///////////////////// Test insert #1
	std::vector<int>::iterator it = v1.insert(v1.begin(), 100);
	for (int i = 0; i < (int)v1.size(); ++i)
		std::cout<<v1[i]<<" ";
	std::cout<<"\t"<<*it<<std::endl;
	outSizes(v1);
	///////////////////// Test insert #2
	v1.insert(v1.begin(), 5, 1);
	for (int i = 0; i < (int)v1.size(); ++i)
		std::cout<<v1[i]<<" ";
	std::cout<<"\t"<<*it<<std::endl;
	outSizes(v1);
	///////////////////// Test insert #3
	std::vector<int> putVec1(10, 0);
	v1.insert(v1.begin() + 1, putVec1.begin(), putVec1.end());
	for (int i = 0; i < (int)v1.size(); ++i)
		std::cout<<v1[i]<<" ";
	std::cout<<"\t"<<*it<<std::endl;
	outSizes(v1);
	///////////////////// Test erase #1
	std::vector<int>::iterator itEr1 = v1.erase(v1.end() - 3);
	for (int i = 0; i < (int)v1.size(); ++i)
		std::cout<<v1[i]<<" ";
	std::cout<<"\t"<<*it<<std::endl;
	std::cout<<*itEr1<<std::endl;
	outSizes(v1);
	///////////////////// Test erase #2
	std::vector<int>::iterator itEr12 = v1.erase(v1.begin(), v1.end() - 3);
	for (int i = 0; i < (int)v1.size(); ++i)
		std::cout<<v1[i]<<" ";
	std::cout<<"\t"<<*it<<std::endl;
	std::cout<<*itEr12<<std::endl;
	///////////////////// Test swap
	{
	std::vector<int> v1(20, 5);
	std::vector<int> putVec1(10, 0);
	v1.swap(putVec1);
	for (int i = 0; i < (int)v1.size(); ++i)
		std::cout<<v1[i];
	std::cout<<" (";
	for (int i = 0; i < (int)putVec1.size(); ++i)
		std::cout<<putVec1[i];
	std::cout<<")"<<std::endl;
	outSizes(v1);
	outSizes(putVec1);
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
}

void vectorTestExeptStd(){
	///////////////////// Test at
	std::vector<long long> v1;
	try { std::cout<<v1.at(0)<<std::endl; }
	catch (std::exception &e) { std::cout<<"Error1: "<<e.what()<<std::endl; }
	///////////////////// Test erase
	try { v1.resize(-10, 12); }
	catch (std::exception &e) { std::cout<<"Error2: "<<e.what()<<std::endl; }
}

void vectorTestRelationalOperatorsStd(){
	std::vector<int> std1;
	std::vector<int> std2;
	std::vector<int> std11;
	std::vector<int> std12;
	std1.push_back(1);
	std2.push_back(2);
	std11.push_back(1);
	std11.push_back(1);
	std12.push_back(1);
	std12.push_back(2);
	///////////////////// Test == != < <= > >=
	boolTest(std11, std11);
	boolTest(std11, std12);
	boolTest(std1, std11);
	boolTest(std12, std11);
	boolTest(std11, std1);
	boolTest(std11, std2);
}