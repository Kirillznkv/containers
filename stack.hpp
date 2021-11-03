#ifndef STACK_HPP
#define STACK_HPP

#include "deque.hpp"

namespace ft{

template <class T, class Container = deque<T> >//
class stack{
public:
	typedef Container									container_type;
	typedef typename container_type::value_type			value_type;
	typedef typename container_type::reference			reference;
	typedef typename container_type::const_reference	const_reference;
	typedef typename container_type::size_type			size_type;
private:
	container_type c;
public:
	stack(void) : c() {};
	stack(const stack& copy){ this->operator=(copy); }
	~stack(void) {}
	stack &operator=(const stack& op){
		if (this == &op)
			return (*this);
		c.operator=(op.c);
		return (*this);
	}
	size_type size(void) const{ return c.size(); }
	reference top(void) const{ return c.back(); }
	bool empty(void) const{ return c.isEmpty(); }
	void push(const value_type& value) { c.push_back(value); }
	void pop(void) { c.pop_back(); }
};

}

#endif