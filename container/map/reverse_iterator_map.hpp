#ifndef REVERSE_ITERATOR_MAP_HPP
#define REVERSE_ITERATOR_MAP_HPP

# include "iterator_map.hpp"

namespace ft{

template <class T = ft::pair<class Key, class Value>, class Category = std::forward_iterator_tag, class Distance = ptrdiff_t,//add const to Key
          class Pointer = T*, class Reference = T&>
class myReverseIteratorMap : public myIteratorMap{
public:
	myReverseIteratorMap() : myIteratorMap(){}// need *?
	myReverseIteratorMap(value_type &val) : pVal(val.value, val.parent, val.left, val.right){}
	myReverseIteratorMap(const myReverseIteratorMap& copy){
		this->operator=(copy);
	}
	virtual ~myReverseIteratorMap(){};
	myReverseIteratorMap &operator=(const myReverseIteratorMap& op){
		if (this == &op)
			return (*this);
		pVal = op.pVal;
		return (*this);
	}
	myReverseIteratorMap &operator ++ (void){
		ft::myNode<T> *nil = pVal->left;
		if ((pVal->isNil()))
			return(*this);
		else if (!(pVal->left->isNil())){
			pVal = pVal->left;
			while (!(pVal->right->isNil()))
				pVal = pVal->right;
		}
		else{
			while (pVal->parent && pVal->parent->left == pVal)
				pVal = pVal->parent;
			if (!(pVal->parent))
				pVal = nil;
		}
		return (*this);
	}
	myReverseIteratorMap operator ++ (int){
		myReverseIteratorMap it(pVal);
		ft::myNode<T> *res = pVal->left;
		if ((pVal->isNil()))
			return (it);
		else if (!(pVal->left->isNil())){
			pVal = pVal->left;
			while (!(pVal->right->isNil()))
				pVal = pVal->right;
			res = pVal;
		}
		else{
			while (pVal->parent && pVal->parent->left == pVal)
				pVal = pVal->parent;
			if (pVal->parent)
				res = pVal;
			else
				pVal = res;
		}
		return (it);
	}
	myReverseIteratorMap &operator -- (void){
		ft::myNode<T> *nil = pVal->right;
		if ((pVal->isNil()))
			pVal = pVal->parent;
		else if (!(pVal->right->isNil())){
			pVal = pVal->right;
			while (!(pVal->left->isNil()))
				pVal = pVal->left;
		}
		else{
			while (pVal->parent && pVal->parent->right == pVal)
				pVal = pVal->parent;
			if (!(pVal->parent))
				pVal = nil;
		}
		return (*this);
	}
	myReverseIteratorMap operator -- (int){
		myReverseIteratorMap it(pVal);
		ft::myNode<T> *res = pVal->right;
		if ((pVal->isNil()))
			pVal = pVal->parent;
		else if (!(pVal->right->isNil())){
			pVal = pVal->right;
			while (!(pVal->left->isNil()))
				pVal = pVal->left;
			res = pVal;
		}
		else{
			while (pVal->parent && pVal->parent->right == pVal)
				pVal = pVal->parent;
			if (pVal->parent)
				res = pVal;
			else
				pVal = res;
		}
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
};

}

#endif