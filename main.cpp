#include <deque>//??
// #include <map>
#include <vector>//
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
}

int	main() {
	stackTest();
	return (0);
}
