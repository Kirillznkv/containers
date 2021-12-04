#ifndef REVERSE_ITERATOR
#define REVERSE_ITERATOR

# include "iterator.hpp"

namespace ft{

template<typename T>
class myReverseIterator : public myIterator<T>{
public:
	myReverseIterator() : myIterator<T>(){}
	myReverseIterator(T *val){
		this->pVal = val;
	}
	myReverseIterator(const myReverseIterator& copy){
		this->operator=(copy);
	}
	~myReverseIterator(){};
	myReverseIterator &operator=(const myReverseIterator& op){
		if (this == &op)
			return (*this);
		this->pVal = op.pVal;
		return (*this);
	}
	myReverseIterator &operator ++ (void){
		--this->pVal;
		return (*this);
	}
	myReverseIterator operator ++ (int){
		myReverseIterator it(this->pVal--);
		return (it);
	}
	myReverseIterator &operator -- (void){
		++this->pVal;
		return (*this);
	}
	myReverseIterator operator -- (int){
		myReverseIterator it(this->pVal++);
		return (it);
	}
	myReverseIterator &operator -= (int rVal){
		this->pVal += rVal;
		return (*this);
	}
	myReverseIterator &operator += (int rVal){
		this->pVal -= rVal;
		return (*this);
	}
	int	 operator - (const myReverseIterator& rVal) const{
		return (rVal.pVal - this->pVal);
	}
	myReverseIterator operator - (int rVal){
		return (myReverseIterator(this->pVal + rVal));
	}
	myReverseIterator operator + (int rVal){
		return (myReverseIterator(this->pVal - rVal));
	}
	bool operator == (const myReverseIterator& rVal) const{
		return (this->pVal == rVal.pVal);
	}
	bool operator != (const myReverseIterator& rVal) const{
		return (this->pVal != rVal.pVal);
	}
	bool operator <= (const myReverseIterator& rVal) const{
		return (this->pVal >= rVal.pVal);
	}
	bool operator >= (const myReverseIterator& rVal) const{
		return (this->pVal <= rVal.pVal);
	}
	bool operator < (const myReverseIterator& rVal) const{
		return (this->pVal > rVal.pVal);
	}
	bool operator > (const myReverseIterator& rVal) const{
		return (this->pVal < rVal.pVal);
	}
	T&	operator* (){
		return (*(this->pVal + 1));
	}
};

}//end ft

#endif