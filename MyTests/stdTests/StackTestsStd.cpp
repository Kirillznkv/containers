#include <stack>
#include <sstream>
#include "TestsUtils.hpp"
// add == <= ...

// Empty, Size, Push, Pop, Top + copy constructor + operator=
void stackTestIntStd(void){
	fStdStack<<"---Stack-Test-Int-(namespace:std)---"<<std::endl;
	std::stack<int> s1;
	fStdStack<<s1.empty()<<std::endl; // Empty
	s1.push(4); // Push
	fStdStack<<s1.top()<<std::endl; // Top
	s1.push(40);
	fStdStack<<s1.top()<<std::endl;
	s1.pop(); // Pop
	fStdStack<<s1.top()<<std::endl;
	for (int i = 0; i < 100; ++i)
		s1.push(i);
	fStdStack<<s1.top()<<std::endl;
	fStdStack<<s1.size()<<std::endl; // Size
	fStdStack<<s1.empty()<<std::endl;
	std::stack<int> s1_copy(s1);
	fStdStack<<s1_copy.top()<<std::endl;
	fStdStack<<s1_copy.size()<<std::endl;
	fStdStack<<s1_copy.empty()<<std::endl;
	std::stack<int> s1_copy2;
	s1_copy2 = s1;
	fStdStack<<s1_copy2.top()<<std::endl;
	fStdStack<<s1_copy2.size()<<std::endl;
	fStdStack<<s1_copy2.empty()<<std::endl;
}

// Test whis classes into arg
void stackTestStringStd(void){
	fStdStack<<"---Stack-Test-String-(namespace:std)---"<<std::endl;
	std::stack<std::string> s1;
	fStdStack<<s1.empty()<<std::endl; // Empty
	s1.push("Hello"); // Push
	fStdStack<<s1.top()<<std::endl; //Top
	s1.push("World");
	fStdStack<<s1.top()<<std::endl;
	s1.pop(); // Pop
	fStdStack<<s1.top()<<std::endl;
	for (int i = 0; i < 100; ++i){
		std::ostringstream ss;
		ss << i;
		std::string str(ss.str());
		s1.push("Str #" + str);
	}
	fStdStack<<s1.top()<<std::endl;
	fStdStack<<s1.size()<<std::endl; // Size
	fStdStack<<s1.empty()<<std::endl;
	std::stack<std::string> s1_copy(s1);
	fStdStack<<s1_copy.top()<<std::endl;
	fStdStack<<s1_copy.size()<<std::endl;
	fStdStack<<s1_copy.empty()<<std::endl;
	std::stack<std::string> s1_copy2;
	s1_copy2 = s1;
	fStdStack<<s1_copy2.top()<<std::endl;
	fStdStack<<s1_copy2.size()<<std::endl;
	fStdStack<<s1_copy2.empty()<<std::endl;
}

// Test whis template into arg
void stackTestListStd(void){
	fStdStack<<"---Stack-Test-List-(namespace:std)---"<<std::endl;
	std::stack<std::stack<int> > s1;
	std::stack<int> myList;
	fStdStack<<s1.empty()<<std::endl;
	myList.push(5);
	s1.push(myList); // Push
	fStdStack<<s1.top().top()<<std::endl;
	myList.push(10);
	s1.push(myList);
	fStdStack<<s1.top().top()<<std::endl;
	s1.pop(); // Pop
	fStdStack<<s1.top().top()<<std::endl;
	for (int i = 0; i < 100; ++i){
		myList.push(i);
		s1.push(myList);
	}
	fStdStack<<s1.top().top()<<std::endl;
	fStdStack<<s1.size()<<std::endl;
	fStdStack<<s1.empty()<<std::endl;
	std::stack<std::stack<int> > s1_copy(s1);
	fStdStack<<s1.top().top()<<std::endl;
	fStdStack<<s1_copy.size()<<std::endl;
	fStdStack<<s1_copy.empty()<<std::endl;
	std::stack<std::stack<int> > s1_copy2;
	s1_copy2 = s1;
	fStdStack<<s1.top().top()<<std::endl;
	fStdStack<<s1_copy2.size()<<std::endl;
	fStdStack<<s1_copy2.empty()<<std::endl;
	fStdStack<<(int)(s1_copy2.top().top() == s1_copy2.top().top())<<std::endl;
}