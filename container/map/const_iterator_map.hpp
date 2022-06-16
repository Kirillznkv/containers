#ifndef CONST_ITERATOR_MAP_HPP
#define CONST_ITERATOR_MAP_HPP

# include <iostream>
# include "../utils.hpp"
# include "iterator_map.hpp"

namespace ft{

template	<class T = ft::pair<class Key, class Value>,
			class Category = std::forward_iterator_tag,
			class Distance = ptrdiff_t,
			class Pointer = const T*,
			class Reference = const T&>
class myConstIteratorMap{
public:
	typedef T				value_type;
	typedef Distance		difference_type;
	typedef Pointer			pointer;
	typedef Reference		reference;
	typedef Category		iterator_category;
protected:
	typedef ft::myNode<value_type> node;
	node *pVal;
public:
	myConstIteratorMap(node *val = NULL) : pVal(val){}
	myConstIteratorMap(const myConstIteratorMap& copy){
		this->operator=(copy);
	}
	virtual ~myConstIteratorMap(){};
	myConstIteratorMap &operator=(const myConstIteratorMap& op){
		if (this == &op)
			return (*this);
		pVal = op.pVal;
		return (*this);
	}
	myConstIteratorMap &operator ++ (void){
		node *nil = pVal->right;
		if ((pVal->isNil()))
			return (*this);
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
			else
				pVal = pVal->parent;
		}
		return (*this);
	}
	myConstIteratorMap operator ++ (int){
		myConstIteratorMap it(pVal);
		this->operator++();
		return (it);
	}
	myConstIteratorMap &operator -- (void){
		node *nil = pVal->left;
		if ((pVal->isNil()))
			pVal = pVal->parent;
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
			else
				pVal = pVal->parent;
		}
		return (*this);
	}
	myConstIteratorMap operator -- (int){
		myConstIteratorMap it(pVal);
		this->operator--();
		return (it);
	}
	virtual reference	operator* (){
		return (pVal->value);
	}
	virtual pointer operator->() {
		return (&(pVal->value));
	}
	bool operator==(const myConstIteratorMap& op){
		return (pVal == op.pVal);
	}
	bool operator!=(const myConstIteratorMap& op){
		return (pVal != op.pVal);
	}
};

}

#endif