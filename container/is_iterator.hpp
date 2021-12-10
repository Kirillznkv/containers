#ifndef IS_ITERATOR_HPP
#define IS_ITERATOR_HPP

# include "is_integral.hpp"
# include "iterator.hpp"
# include "reverse_iterator.hpp"

namespace ft{

template <class _Tp>		struct is_iterator								: public false_type {};
template <class _T>			struct is_iterator< myIterator<_T> >			: public true_type {};
template <class _T>			struct is_iterator< myReverseIterator<_T> >		: public true_type {};

}

#endif