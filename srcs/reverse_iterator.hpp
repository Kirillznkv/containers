#ifndef REVERSE_ITERATOR
#define REVERSE_ITERATOR

# include "iterator.hpp"

template<typename T>
class myReverseItertor : public myItertor{
public:
	myReverseItertor() : myItertor()){}
	myReverseItertor(T *val){
		this->pVal = val - 1;
	}
	myReverseItertor(const myReverseItertor& copy){
		this->operator=(copy);
	}
	virtual ~myReverseItertor(){};
	virtual myReverseItertor &operator=(const myReverseItertor& op){//
		if (this == &op)
			return (*this);
		this->pVal = op.pVal;
		return (*this);
	}
	virtual myReverseItertor &operator ++ (void){//
		--this->pVal;
		return (*this);
	}
	virtual myReverseItertor operator ++ (int){//
		myReverseItertor it(this->pVal--);
		return (it);
	}
	virtual myReverseItertor &operator -- (void){//
		++this->pVal;
		return (*this);
	}
	virtual myReverseItertor operator -- (int){//
		myReverseItertor it(this->pVal++);
		return (it);
	}
	virtual myReverseItertor &operator -= (int rVal){
		this->pVal += rVal;
		return (*this);
	}
	virtual myReverseItertor &operator += (int rVal){
		this->pVal -= rVal;
		return (*this);
	}
	virtual int	 operator - (const myReverseItertor& rVal) const{/////////?
		return (this->pVal - rVal.pVal);
	}
	virtual myReverseItertor operator - (int rVal){//
		return (myReverseItertor(this->pVal + rVal));
	}
	virtual myReverseItertor operator + (int rVal){//
		return (myReverseItertor(this->pVal - rVal));
	}
	virtual bool operator == (const myReverseItertor& rVal) const{
		return (this->pVal == rVal.pVal);
	}
	virtual bool operator != (const myReverseItertor& rVal) const{
		return (this->pVal != rVal.pVal);
	}
	virtual bool operator <= (const myReverseItertor& rVal) const{
		return (this->pVal >= rVal.pVal);
	}
	virtual bool operator >= (const myReverseItertor& rVal) const{
		return (this->pVal <= rVal.pVal);
	}
	virtual bool operator < (const myReverseItertor& rVal) const{
		return (this->pVal > rVal.pVal);
	}
	virtual bool operator > (const myReverseItertor& rVal) const{
		return (this->pVal < rVal.pVal);
	}
	virtual T&	operator* (){
		return (*(this->pVal + 1));
	}
};

#endif