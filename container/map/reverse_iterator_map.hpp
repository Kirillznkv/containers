#ifndef REVERSE_ITERATOR_MAP_HPP
#define REVERSE_ITERATOR_MAP_HPP

# include "iterator_map.hpp"

namespace ft{

template <class T = ft::pair<class Key, class Value>, class Category = std::forward_iterator_tag, class Distance = ptrdiff_t,//add const to Key
          class Pointer = T*, class Reference = T&>
class myReverseIteratorMap : public myIteratorMap<T, Category, Distance, Pointer, Reference>{
protected:
	typedef ft::myNode<T> node;
public:
	myReverseIteratorMap(node *val = NULL) : myIteratorMap<T, Category, Distance, Pointer, Reference>(val){}
	myReverseIteratorMap(const myReverseIteratorMap& copy){
		this->operator=(copy);
	}
	virtual ~myReverseIteratorMap(){};
	myReverseIteratorMap &operator=(const myReverseIteratorMap& op){
		if (this == &op)
			return (*this);
		this->pVal = op.pVal;
		return (*this);
	}
	myReverseIteratorMap &operator ++ (void){
		node *nil = this->pVal->left;
		if ((this->pVal->isNil()))
			this->pVal = this->pVal->parent;
		else if (!(this->pVal->left->isNil())){
			this->pVal = this->pVal->left;
			while (!(this->pVal->right->isNil()))
				this->pVal = this->pVal->right;
		}
		else{
			while (this->pVal->parent && this->pVal->parent->left == this->pVal)
				this->pVal = this->pVal->parent;
			if (!(this->pVal->parent))
				this->pVal = nil;
			else
				this->pVal = this->pVal->parent;
		}
		return (*this);
	}
	myReverseIteratorMap operator ++ (int){
		myReverseIteratorMap it(this->pVal);
		this->operator++();
		return (it);
	}
	myReverseIteratorMap &operator -- (void){
		node *nil = this->pVal->right;
		if ((this->pVal->isNil()))
			return(*this);
		else if (!(this->pVal->right->isNil())){
			this->pVal = this->pVal->right;
			while (!(this->pVal->left->isNil()))
				this->pVal = this->pVal->left;
		}
		else{
			while (this->pVal->parent && this->pVal->parent->right == this->pVal)
				this->pVal = this->pVal->parent;
			if (!(this->pVal->parent))
				this->pVal = nil;
			else
				this->pVal = this->pVal->parent;
		}
		return (*this);
	}
	myReverseIteratorMap operator -- (int){
		myReverseIteratorMap it(this->pVal);
		this->operator--();
		return (it);
	}
	myReverseIteratorMap &operator+=(int col){
		for (int i = 0; i < col; ++i)
			this->operator++();
		return (*this);
	}
	myReverseIteratorMap &operator-=(int col){
		for (int i = 0; i < col; ++i)
			this->operator--();
		return (*this);
	}
	myReverseIteratorMap operator+(int col){
		myReverseIteratorMap it(*this);
		for (int i = 0; i < col; ++i)
			it.operator++();
		return (it);
	}
	myReverseIteratorMap operator-(int col){
		myReverseIteratorMap it(*this);
		for (int i = 0; i < col; ++i)
			it.operator--();
		return (it);
	}
	T&	operator* (){
		myReverseIteratorMap it((*this) + 1);
		return ((it.pVal)->value);
	}
	T	*operator->() {
		myReverseIteratorMap it((*this) + 1);
		return (&(it.pVal->value));
	}
	bool operator==(const myReverseIteratorMap& op){
		return (this->pVal == op.pVal);
	}
	bool operator!=(const myReverseIteratorMap& op){
		return (this->pVal != op.pVal);
	}
};

}

#endif