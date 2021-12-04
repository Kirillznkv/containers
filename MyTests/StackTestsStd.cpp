#include <iostream>
#include <stack>
#include <sstream>
// add == <= ...

// Empty, Size, Push, Pop, Top + copy constructor + operator=
void stackTestIntStd(void){
	std::stack<int> s1;
	std::cout<<s1.empty()<<std::endl; // Empty
	s1.push(4); // Push
	std::cout<<s1.top()<<std::endl; // Top
	s1.push(40);
	std::cout<<s1.top()<<std::endl;
	s1.pop(); // Pop
	std::cout<<s1.top()<<std::endl;
	for (int i = 0; i < 100; ++i)
		s1.push(i);
	std::cout<<s1.top()<<std::endl;
	std::cout<<s1.size()<<std::endl; // Size
	std::cout<<s1.empty()<<std::endl;
	std::stack<int> s1_copy(s1);
	std::cout<<s1_copy.top()<<std::endl;
	std::cout<<s1_copy.size()<<std::endl;
	std::cout<<s1_copy.empty()<<std::endl;
	std::stack<int> s1_copy2;
	s1_copy2 = s1;
	std::cout<<s1_copy2.top()<<std::endl;
	std::cout<<s1_copy2.size()<<std::endl;
	std::cout<<s1_copy2.empty()<<std::endl;
}

// Test whis classes into arg
void stackTestStringStd(void){
	std::stack<std::string> s1;
	std::cout<<s1.empty()<<std::endl; // Empty
	s1.push("Hello"); // Push
	std::cout<<s1.top()<<std::endl; //Top
	s1.push("World");
	std::cout<<s1.top()<<std::endl;
	s1.pop(); // Pop
	std::cout<<s1.top()<<std::endl;
	for (int i = 0; i < 100; ++i){
		std::ostringstream ss;
		ss << i;
		std::string str(ss.str());
		s1.push("Str #" + str);
	}
	std::cout<<s1.top()<<std::endl;
	std::cout<<s1.size()<<std::endl; // Size
	std::cout<<s1.empty()<<std::endl;
	std::stack<std::string> s1_copy(s1);
	std::cout<<s1_copy.top()<<std::endl;
	std::cout<<s1_copy.size()<<std::endl;
	std::cout<<s1_copy.empty()<<std::endl;
	std::stack<std::string> s1_copy2;
	s1_copy2 = s1;
	std::cout<<s1_copy2.top()<<std::endl;
	std::cout<<s1_copy2.size()<<std::endl;
	std::cout<<s1_copy2.empty()<<std::endl;
}

// Test whis template into arg
void stackTestListStd(void){
	std::stack<std::stack<int> > s1;
	std::stack<int> myList;
	std::cout<<s1.empty()<<std::endl;
	myList.push(5);
	s1.push(myList); // Push
	std::cout<<s1.top().top()<<std::endl;
	myList.push(10);
	s1.push(myList);
	std::cout<<s1.top().top()<<std::endl;
	s1.pop(); // Pop
	std::cout<<s1.top().top()<<std::endl;
	for (int i = 0; i < 100; ++i){
		myList.push(i);
		s1.push(myList);
	}
	std::cout<<s1.top().top()<<std::endl;
	std::cout<<s1.size()<<std::endl;
	std::cout<<s1.empty()<<std::endl;
	std::stack<std::stack<int> > s1_copy(s1);
	std::cout<<s1.top().top()<<std::endl;
	std::cout<<s1_copy.size()<<std::endl;
	std::cout<<s1_copy.empty()<<std::endl;
	std::stack<std::stack<int> > s1_copy2;
	s1_copy2 = s1;
	std::cout<<s1.top().top()<<std::endl;
	std::cout<<s1_copy2.size()<<std::endl;
	std::cout<<s1_copy2.empty()<<std::endl;
	std::cout<<(int)(s1_copy2.top().top() == s1_copy2.top().top())<<std::endl;
}