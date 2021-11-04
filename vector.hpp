#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>

// Вопросы:
// Чем отличается max_size от capacity?
// Зачем нужен resize?
// Что будет если вызвать reserve, когда уже есть эллементы и что будет если задать его меньше чем есть эллементов?
// Что будет если увеличить или уменьшить resize?

namespace ft{

template<typename T, class Allocator = std::allocator<T> >
class vector{
public:
	typedef T											value_type;//
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
	size_t	_size;
	size_t	_max_size;
	size_t	_resize;
	size_t	_capacity;
	size_t	_empty;
	size_t	_reserve;
	allocator_type	_alloc;
public:
	vector(void){};
	vector(const vector& copy){}
	~vector(void) {}
	// vector &operator=(const vector& op){
	// 	if (this == &op)
	// 		return (*this);
	// 	return (*this);
	// }
	allocator_type get_allocator() const{
		return _alloc;
	}
};

}//end namespace ft

#endif