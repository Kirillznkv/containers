#include "TestsUtils.hpp"

/////////////////////////////
/*----------Stack----------*/
/////////////////////////////
void stackTestIntStd();
void stackTestStringStd();
void stackTestListStd();

//////////////////////////////
/*----------Vector----------*/
//////////////////////////////
void vectorTestBaseStd();
void vectorTestDoubleStd();
void vectorTestListStd();
void vectorTestIteratorStd();
void vectorTestReverseIteratorStd();
void vectorTestModifiersStd();
void vectorTestExeptStd();
void vectorTestRelationalOperatorsStd();

/////////////////////////////
/*----------Tests----------*/
/////////////////////////////
void	stackTest(){
	stackTestIntStd();
	stackTestStringStd();
	stackTestListStd();
	fStdStack.close();
}
void	vectorTest(){
	vectorTestBaseStd();
	vectorTestDoubleStd();
	vectorTestListStd();
	vectorTestIteratorStd();
	vectorTestReverseIteratorStd();
	vectorTestModifiersStd();
	vectorTestExeptStd();
	vectorTestRelationalOperatorsStd();
	fStdVector.close();
}

int		main() {
	stackTest();
	vectorTest();
	return (0);
}
