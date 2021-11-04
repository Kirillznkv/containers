// #include <deque>//??
// #include <map>
#include <vector>//
#include <list>
#include <stack>
#include <iostream>

#define BLOCK_COLOR "\033[38;2;0;0;0;48;2;255;255;0m"
#define RESET_COLOR "\033[38;2;255;255;255;48;2;30;30;30m"

void stackTestInt(void);
void stackTestString(void);
void stackTestList(void);

void stackTest(void){
	std::cout<<BLOCK_COLOR"----------STACK-TEST----------"RESET_COLOR<<std::endl;
	stackTestInt();
	stackTestString();
	stackTestList();
	// std::vector<int> a;
	// a.push_back(5);
	// a.push_back(6);
	// std::stack<int> b(a);
	// std::allocator<std::list<int> > _alloc;
	// std::list<int> *b = _alloc.allocate(1);
	// _alloc.construct(b, a);
	// // *b = a;
	// std::cout<<b->size()<<std::endl;
}

int	main() {
	stackTest();
	return (0);
}
