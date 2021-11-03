#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>

namespace ft{

template <class T, class Allocator = std::allocator<T> >
class vector{
public:
	typedef T											value_type;
	typedef Allocator									allocator_type;
	typedef typename allocator_type::reference			reference;
	typedef typename allocator_type::const_reference	const_reference;
	// typedef implementation-defined						iterator;
	// typedef implementation-defined						const_iterator;
	typedef typename allocator_type::size_type			size_type;
	typedef typename allocator_type::difference_type	difference_type;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::const_pointer		const_pointer;
	// typedef std::reverse_iterator<iterator>				reverse_iterator;
	// typedef std::reverse_iterator<const_iterator>		const_reverse_iterator;
private:
public:
	vector(void){};
	vector(const vector& copy){}
	~vector(void) {}
	vector &operator=(const vector& op){
		if (this == &op)
			return (*this);
		return (*this);
	}
};

}

#endif