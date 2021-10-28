#include <iostream>
#include <stack>
#include <list>
#include "stack.hpp"
#include <sstream>


#define TYPE_COLOR "\033[38;2;0;255;255m"
#define RESET_COLOR "\033[38;2;255;255;255;48;2;30;30;30m"

template <typename T>
void out(const T& v1,const T& v2){
	std::cout<<v1<<"\t\t\t"<<v2<<std::endl;
}

// Empty, Size, Push, Pop, Top + copy constructor + operator=
void stackTestInt(void){
	std::cout<<TYPE_COLOR"(INT)"RESET_COLOR<<std::endl;
	std::stack<int> s1;
	ft::stack<int> s2;
	out(s1.empty(), s2.empty()); // Empty
	s1.push(4); // Push
	s2.push(4);
	out(s1.top(), s2.top()); //Top
	s1.push(40);
	s2.push(40);
	out(s1.top(), s2.top());
	s1.pop(); // Pop
	s2.pop();
	out(s1.top(), s2.top());
	for (int i = 0; i < 100; ++i){
		s1.push(i);
		s2.push(i);
	}
	out(s1.top(), s2.top());
	out(s1.size(), s2.size()); // Size
	out(s1.empty(), s2.empty());
	std::stack<int> s1_copy(s1);
	ft::stack<int> s2_copy(s2);
	out(s1_copy.top(), s2_copy.top());
	out(s1_copy.size(), s2_copy.size());
	out(s1_copy.empty(), s2_copy.empty());
	std::stack<int> s1_copy2;
	ft::stack<int> s2_copy2;
	s1_copy2 = s1;
	s2_copy2 = s2;
	out(s1_copy2.top(), s2_copy2.top());
	out(s1_copy2.size(), s2_copy2.size());
	out(s1_copy2.empty(), s2_copy2.empty());
}

// Test whis classes into arg
void stackTestString(void){
	std::cout<<TYPE_COLOR"(String)"RESET_COLOR<<std::endl;
	std::stack<std::string> s1;
	ft::stack<std::string> s2;
	out(s1.empty(), s2.empty()); // Empty
	s1.push("Hello"); // Push
	s2.push("Hello");
	out(s1.top(), s2.top()); //Top
	s1.push("World");
	s2.push("World");
	out(s1.top(), s2.top());
	s1.pop(); // Pop
	s2.pop();
	out(s1.top(), s2.top());
	for (int i = 0; i < 100; ++i){
		std::ostringstream ss;
		ss << i;
		std::string str(ss.str());
		s1.push("Str #" + str);
		s2.push("Str #" + str);
	}
	out(s1.top(), s2.top());
	out(s1.size(), s2.size()); // Size
	out(s1.empty(), s2.empty());
	std::stack<std::string> s1_copy(s1);
	ft::stack<std::string> s2_copy(s2);
	out(s1_copy.top(), s2_copy.top());
	out(s1_copy.size(), s2_copy.size());
	out(s1_copy.empty(), s2_copy.empty());
	std::stack<std::string> s1_copy2;
	ft::stack<std::string> s2_copy2;
	s1_copy2 = s1;
	s2_copy2 = s2;
	out(s1_copy2.top(), s2_copy2.top());
	out(s1_copy2.size(), s2_copy2.size());
	out(s1_copy2.empty(), s2_copy2.empty());
}

// Test whis template into arg
void stackTestList(void){
	std::cout<<TYPE_COLOR"(List)"RESET_COLOR<<std::endl;
	std::stack<std::list<int> > s1;
	ft::stack<std::list<int> > s2;
	std::list<int> myList;
	out(s1.empty(), s2.empty()); // Empty
	myList.push_back(5);
	s1.push(myList); // Push
	s2.push(myList);
	// out(s1.top(), s2.top()); //Top
	myList.push_back(10);
	s1.push(myList);
	s2.push(myList);
	// out(s1.top(), s2.top());
	s1.pop(); // Pop
	s2.pop();
	// out(s1.top(), s2.top());
	myList.pop_back();
	myList.pop_back();
	for (int i = 0; i < 100; ++i){
		myList.push_back(i);
		s1.push(myList);
		s2.push(myList);
	}
	// out(s1.top(), s2.top());
	out(s1.size(), s2.size()); // Size
	out(s1.empty(), s2.empty());
	std::stack<std::list<int> > s1_copy(s1);
	ft::stack<std::list<int> > s2_copy(s2);
	// out(s1_copy.top(), s2_copy.top());
	out(s1_copy.size(), s2_copy.size());
	out(s1_copy.empty(), s2_copy.empty());
	std::stack<std::list<int> > s1_copy2;
	ft::stack<std::list<int> > s2_copy2;
	s1_copy2 = s1;
	s2_copy2 = s2;
	// out(s1_copy2.top(), s2_copy2.top());
	out(s1_copy2.size(), s2_copy2.size());
	out(s1_copy2.empty(), s2_copy2.empty());
}