#include "TestsUtils.hpp"

/////////////////////////////
/*----------Stack----------*/
/////////////////////////////
void stackTestIntStd();
void stackTestStringStd();
void stackTestListStd();
void stackTestRelationalOperatorsStd();

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
void	stackTestStd() {
	stackTestIntStd();
	stackTestStringStd();
	stackTestListStd();
	stackTestRelationalOperatorsStd();
	fStdStack.close();
}
void	vectorTestStd() {
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
	stackTestStd();
	vectorTestStd();
	return (0);
}
