#ifndef STACK_HPP
#define STACK_HPP

# include "deque.hpp"

namespace ft{

template <class T, class Container = ft::deque<T> >
class stack {
public:
	typedef Container									container_type;
	typedef typename container_type::value_type			value_type;
	typedef typename container_type::reference			reference;
	typedef typename container_type::const_reference	const_reference;
	typedef typename container_type::size_type			size_type;
private:
	container_type c;
public:
	stack(void) {};
	stack(const stack& copy) { this->operator=(copy); }
	~stack() {}
	stack &operator=(const stack& op) {
		if (this == &op)
			return (*this);
		c.operator=(op.c);
		return (*this);
	}
	size_type size() const { return c.size(); }
	reference top() const { return c.back(); }
	bool empty() const { return c.isEmpty(); }
	void push(const value_type& value) { c.push_back(value); }
	void pop() { c.pop_back(); }
	bool	operator==(const stack& rVal) {
		return (c.operator==(rVal.c));
	}
	bool	operator!=(const stack& rVal) {
		return (c.operator!=(rVal.c));
	}
	bool	operator<(const stack& rVal) {
		return (c.operator<(rVal.c));
	}
	bool	operator>(const stack& rVal) {
		return (c.operator>(rVal.c));
	}
	bool	operator>=(const stack& rVal) {
		return (c.operator>=(rVal.c));
	}
	bool	operator<=(const stack& rVal) {
		return (c.operator<=(rVal.c));
	}
};

}

#endif