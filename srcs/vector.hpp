#ifndef VECTOR_HPP
#define VECTOR_HPP

# include <cmath>///
# include <memory>///
# include "iterator.hpp"
# include "reverse_iterator.hpp"

// Вопросы:
// iterator base()?

namespace ft{

template<typename T, class Allocator = std::allocator<T> >
class vector{
public:
	typedef T											value_type;
	typedef Allocator									allocator_type;
	typedef typename allocator_type::reference			reference;
	typedef typename allocator_type::const_reference	const_reference;
	typedef typename allocator_type::size_type			size_type;
	typedef typename allocator_type::difference_type	difference_type;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::const_pointer		const_pointer;
	typedef myIterator<T>								iterator;
	typedef myReverseIterator<T>						reverse_iterator;
private:
	size_type	_size;
	size_type	_capacity;
	value_type	*_arr;
	allocator_type	_alloc;
public:
	vector() : _size(0), _capacity(0), _arr(NULL){};
	vector(const vector& copy){
		this->operator=(copy);
	}//
	~vector(void) {
		for (size_type i = 0; i < _size; ++i)
			_alloc.destroy(_arr + i);
		if (_capacity)
			_alloc.deallocate(_arr, _capacity);
	}
	vector &operator=(const vector& op){
		if (this == &op)
			return (*this);
		this->_capacity = 0;
		this->_size = 0;
		this->_arr = NULL;
		if (op._capacity){
			this->_capacity = op._capacity;
			this->_size = op._size;
			this->_arr = _alloc.allocate(this->_capacity);
			for (size_type i = 0; i < this->_size; ++i)
				_alloc.construct(this->_arr + i, *(op._arr + i));
		}
		return (*this);
	}
	allocator_type	get_allocator() const{
		return _alloc;
	}
	bool		empty() const{
		return (_size ? false : true);
	}
	size_type	capacity() const{
		return (_capacity);
	}
	size_type	size() const{
		return (_size);
	}
	size_type	max_size() const{
		size_type val = (pow(2, 64) / sizeof(value_type));
		val--;
		return (val);
	}
	void	resize(size_type n, value_type val = value_type()){
		if (_capacity >= n)
			while (_size < n)
				push_back(val);
		else{
			value_type *new_arr = _alloc.allocate(n);
			for (size_t i = 0; i < _size; ++i){
				_alloc.construct(new_arr + i, *(_arr + i));
				_alloc.destroy(_arr + i);
			}
			for (size_t i = _size; i < n; ++i)
				_alloc.construct(new_arr + i, val);
			_alloc.deallocate(_arr, _capacity);
			_arr = new_arr;
			_capacity = n;
			_size = n;
		}
		while (_size > n)
			pop_back();
	}
	void	reserve(size_type n){
		if (n != _size){
			value_type *new_arr = _alloc.allocate(n);
			for (size_type i = 0; i < _size; ++i){
				_alloc.construct(new_arr + i, *(_arr + i));
				_alloc.destroy(_arr + i);
			}
			if (_capacity)
				_alloc.deallocate(_arr, _capacity);
			_arr = new_arr;
			_capacity = n;
		}
	}
	void	assign(size_type n, const value_type &val){
		resize(n, val);
	}
	void	push_back(const value_type &val){
		if (!_capacity){
			_arr = _alloc.allocate(_capacity = 1);
		}
		else if (_size == _capacity){
			value_type *new_arr = _alloc.allocate(_capacity <<= 1);
			for (size_type i = 0; i < _size; ++i){
				_alloc.construct(new_arr + i, *(_arr + i));
				_alloc.destroy(_arr + i);
			}
			_alloc.deallocate(_arr, _capacity>>1);
			_arr = new_arr;
		}
		_alloc.construct(_arr + _size++, val);
	}
	void	pop_back(){//исключения
		if (_size)
			_alloc.destroy(_arr + --_size);
	}
	class errorIndex: public std::exception{//Заменить на орегинальный
	public:
		const char* what(void) const _NOEXCEPT{
			return "bad index";
		}
	};
	// const_reference	front() const{
	// 	return (*_arr);
	// }
	reference	front(){
		return (*_arr);
	}
	// const_reference	back() const{
	// 	return (_arr[_size - 1]);
	// }
	reference	back(){
		return (_arr[_size - 1]);
	}
	reference	operator[](size_type i){
		return (*(_arr + i));
	}
	reference	at(size_type i){
		if (i < 0 || i >= _size)
			throw errorIndex();
		return (*(_arr + i));
	}
	iterator begin(){
		return (iterator(_arr));//исключения
	}
	iterator end(){
		return (iterator(_arr + _size));
	}
	reverse_iterator rbegin(){
		return (reverse_iterator(_arr + _size - 2));//исключения
	}
	reverse_iterator rend(){
		return (reverse_iterator(_arr - 2));
	}
};

}//end namespace ft

#endif