#ifndef VECTOR_HPP
#define VECTOR_HPP

# include <cmath>
# include <iostream>
# include <memory>

# include "iterator.hpp"
# include "reverse_iterator.hpp"
# include "../utils.hpp"

namespace ft{

///////////////////////
/*-----Exception-----*/
///////////////////////
class errorIndex: public std::exception{
public:
	const char* what(void) const _NOEXCEPT{
		return "vector";
	}
};

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
	typedef myIterator<const T>								const_iterator;
	typedef myReverseIterator<T>						reverse_iterator;
private:
	size_type	_size;
	size_type	_capacity;
	value_type	*_arr;
	allocator_type	_alloc;

	void		doublingCapacity(){
		_capacity = (!_capacity) ? (1) : (_capacity<<1);
		value_type *new_arr = _alloc.allocate(_capacity);
		for (size_type i = 0; i < _size; ++i){
			_alloc.construct(new_arr + i, *(_arr + i));
			_alloc.destroy(_arr + i);
		}
		if (_capacity > 1)
			_alloc.deallocate(_arr, _capacity>>1);
		_arr = new_arr;
	}
	iterator	doublingCapacity(iterator save){
		bool isNewIter = false;
		_capacity = (!_capacity) ? (1) : (_capacity<<1);
		value_type *new_arr = _alloc.allocate(_capacity);
		for (size_type i = 0; i < _size; ++i){
			_alloc.construct(new_arr + i, *(_arr + i));
			_alloc.destroy(_arr + i);
			if (!isNewIter && &(*save) == _arr + i){
				save = iterator(new_arr);
				isNewIter = true;
			}
		}
		if (_capacity > 1)
			_alloc.deallocate(_arr, _capacity>>1);
		_arr = new_arr;
		if (_size == 0)
			save = iterator(_arr);
		return (save);
	}
	iterator	reserve(size_type n, iterator save){
		if ((signed)n < 0)
			throw errorIndex();
		bool isNewIter = false;
		if (n != _capacity){
			value_type *new_arr = _alloc.allocate(n);
			for (size_type i = 0; i < _size && i < n; ++i){
				_alloc.construct(new_arr + i, *(_arr + i));
				_alloc.destroy(_arr + i);
				if (!isNewIter && &(*save) == _arr + i){
					save = iterator(new_arr);
					isNewIter = true;
				}
			}
			if (_capacity)
				_alloc.deallocate(_arr, _capacity);
			_arr = new_arr;
			_capacity = n;
		}
		if (_size == 0)
			save = iterator(_arr);
		return (save);
	}
public:
	////////////////////////
	/*-----Constructs-----*/
	////////////////////////
	vector() : _size(0), _capacity(0){};
	vector(size_type size, value_type val = value_type()) : _size(0), _capacity(0), _arr(NULL){
		if ((signed)size < 0)
			throw errorIndex();
		resize(size, val);
	};
	vector (const vector& copy) :_size(0), _capacity(0){
		this->operator=(copy);
	}
	template <class InputIterator>
	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
			typename ft::enable_if<ft::is_iterator<InputIterator>::value>::type* = 0)
			:_size(0), _capacity(1), _alloc(alloc){
		_arr = _alloc.allocate(_capacity);
		insert(begin(), first, last);
	}
	virtual ~vector() {
		for (size_type i = 0; i < _size; ++i)
			_alloc.destroy(_arr + i);
		if (_capacity)
			_alloc.deallocate(_arr, _capacity);
	}
	///////////////////////
	/*-----Operators-----*/
	///////////////////////
	vector &operator=(const vector& op){
		if (this == &op)
			return (*this);
		while (_size)
			_alloc.destroy(this->_arr + --_size);
		if (this->_capacity){
			_alloc.deallocate(this->_arr, this->_capacity);
			_capacity = 0;
		}
		if (op._capacity){
			this->_capacity = op._capacity;
			this->_size = op._size;
			this->_arr = _alloc.allocate(this->_capacity);
			for (size_type i = 0; i < this->_size; ++i)
				_alloc.construct(this->_arr + i, *(op._arr + i));
		}
		return (*this);
	}
	bool	operator==(const vector& rVal){
		if (this->size() != rVal.size())
			return (false);
		int i = -1;
		while (++i < (int)_size)
			if (_arr[i] != rVal.at(i))
				return (false);
		return (true);
	}
	bool	operator!=(const vector& rVal){
		return (!operator==(rVal));
	}
	bool	operator<(const vector& rVal){
		int i = 0;
		while (i < (int)_size && i < (int)rVal.size() && _arr[i] == rVal.at(i))
			i++;
		if (i == (int)rVal.size())
			return (false);
		else if (i == (int)_size)
			return (true);
		return (_arr[i] < rVal.at(i));
	}
	bool	operator>(const vector& rVal){
		int i = 0;
		while (i < (int)_size && i < (int)rVal.size() && _arr[i] == rVal.at(i))
			i++;
		if (i == (int)_size)
			return (false);
		else if (i == (int)rVal.size())
			return (true);
		return (_arr[i] > rVal.at(i));
	}
	bool	operator>=(const vector& rVal){
		return (!operator<(rVal));
	}
	bool	operator<=(const vector& rVal){
		return (!operator>(rVal));
	}
	reference	operator[](size_type i){
		return (*(_arr + i));
	}
	const_reference	operator[](size_type i) const{
		return (*(_arr + i));
	}
	//////////////////////////////////
	/*-----begin-end-front-back-----*/
	//////////////////////////////////
	iterator begin() { return (iterator(_arr)); }
	iterator end() { return (iterator(_arr + _size)); }
	reverse_iterator rbegin() { return (reverse_iterator(_arr + _size)); }
	reverse_iterator rend() { return (reverse_iterator(_arr)); }
	const_reference	front() const { return (*_arr); }
	reference	front() { return (*_arr); }
	const_reference	back() const { return (_arr[_size - 1]); }
	reference	back() { return (_arr[_size - 1]); }
	///////////////////////
	/*-----Functions-----*/
	///////////////////////
	void	push_back(const value_type &val){
		if (!_capacity)
			_arr = _alloc.allocate(_capacity = 1);
		else if (_size == _capacity)
			doublingCapacity();
		_alloc.construct(_arr + _size++, val);
	}
	void	pop_back(){
		if (_size)
			_alloc.destroy(_arr + --_size);
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
	void	swap(vector& x){
		size_type	size = _size;
		size_type	capacity = _capacity;
		value_type	*arr = _arr;
		allocator_type	alloc = _alloc;
		_size = x._size;
		_capacity = x._capacity;
		_arr = x._arr;
		_alloc = x._alloc;
		x._size = size;
		x._capacity = capacity;
		x._arr = arr;
		x._alloc = alloc;
	}
	void	clear(){
		while (_size)
			_alloc.destroy(this->_arr + --_size);
	}
	reference	at(size_type i){
		if ((signed)i < 0 || i >= _size)
			throw errorIndex();
		return (*(_arr + i));
	}
	const_reference	at(size_type i) const{
		if ((signed)i < 0 || i >= _size)
			throw errorIndex();
		return (*(_arr + i));
	}
	void	reserve(size_type n){
		if (n != _capacity){
			value_type *new_arr = _alloc.allocate(n);
			for (size_type i = 0; i < _size && i < n; ++i){
				_alloc.construct(new_arr + i, *(_arr + i));
				_alloc.destroy(_arr + i);
			}
			if (_capacity)
				_alloc.deallocate(_arr, _capacity);
			_arr = new_arr;
			_capacity = n;
		}
	}
	void	resize(size_type n, value_type val = value_type()){
		if ((signed)n < 0)
			throw errorIndex();
		if (_capacity >= n)
			while (_size < n)
				push_back(val);
		else{
			value_type *new_arr = _alloc.allocate(n);
			for (size_t i = 0; i < _size && i < n; ++i){
				_alloc.construct(new_arr + i, *(_arr + i));
				_alloc.destroy(_arr + i);
			}
			for (size_t i = _size; i < n; ++i)
				_alloc.construct(new_arr + i, val);
			if (_capacity)
				_alloc.deallocate(_arr, _capacity);
			_arr = new_arr;
			_capacity = n;
			_size = n;
		}
		while (_size > n)
			pop_back();
	}
	////////////////////
	/*-----Assign-----*/
	////////////////////
	void	assign(size_type n, const value_type &val){
		if ((signed)n < 0)
			throw errorIndex();
		resize(n, val);
	}
	template <class InputIterator>
	typename ft::enable_if
	< !ft::is_integral< InputIterator >::value, void >::type
	assign(InputIterator first, InputIterator last){
		if (size_type(last - first) <= _capacity){
			clear();
			while (first != last)
				push_back(*(first++));
		}
		else{
			clear();
			reserve(last - first);
			while (first != last)
				push_back(*(first++));
		}
	}
	////////////////////
	/*-----Insert-----*/
	////////////////////
	iterator insert(iterator position, const value_type& val){
		if (_size == _capacity)
			position = doublingCapacity(position);
		for (iterator i = end() - 1; i >= position; --i){
			_alloc.construct(&(*i) + 1, *i);
			_alloc.destroy(&(*i));
		}
		_alloc.construct(&(*position), val);
		++_size;
		return (position);
	}
	void	insert(iterator position, size_type n, const value_type& val){
		if ((signed)n < 0)
			throw errorIndex();
		if (_size + n >= _capacity)
			position = reserve(_size + n, position);
		for (iterator i = end() - 1; i >= position; --i){
			_alloc.construct(&(*i) + n, *i);
			_alloc.destroy(&(*i));
		}
		for (int i = 0; i < (int)n; ++i)
			_alloc.construct(&(*(position + i)), val);
		_size += n;
	}
	template <class InputIterator>
	typename ft::enable_if
	< !ft::is_integral<InputIterator>::value, void >::type
	insert(iterator position, InputIterator first, InputIterator last){
		size_type n = (last - first);
		if (_size + n > _capacity)
			position = reserve(_size + n, position);
		while (_size + n > _capacity)
			position = doublingCapacity(position);
		for (iterator i = end() - 1; i >= position && _size; --i){
			_alloc.construct(&(*i) + n, *i);
			_alloc.destroy(&(*i));
		}
		for (int i = 0; i < (int)n; ++i)
			_alloc.construct(&(*(position + i)), *(first++));
		_size += n;
	}
	///////////////////
	/*-----Erase-----*/
	///////////////////
	iterator	erase(iterator position){
		_alloc.destroy(&(*position));
		for (iterator it = position; it != end(); ++it){
			_alloc.construct(&(*it), *(it + 1));
			_alloc.destroy(&(*(it + 1)));
		}
		--_size;
		return (position);
	}
	iterator	erase(iterator first, iterator last){
		for (iterator it = first; it != last; ++it)
			_alloc.destroy(&(*it));
		for (iterator it = last, itToPast = first; it != end(); ++it){
			_alloc.construct(&(*(itToPast++)), *it);
			_alloc.destroy(&(*it));
		}
		_size -= (last - first);
		return (first);
	}
};

////////////////////////
/*-----GlobalSwap-----*/
////////////////////////
template <class T, class Alloc>
  void swap (vector<T,Alloc>& x, vector<T,Alloc>& y){
	vector<T, Alloc> vec(x);
	x.operator=(y);
	y.operator=(vec);
  }

}//end namespace ft

#endif