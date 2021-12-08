#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

# include "iterator.hpp"

namespace ft{

template<class MyIterator>
struct iterator_traits
{
    typedef typename MyIterator::difference_type difference_type;
    typedef typename MyIterator::value_type value_type;
    typedef typename MyIterator::pointer pointer;
    typedef typename MyIterator::reference reference;
    typedef typename MyIterator::iterator_category iterator_category;
};

template<class T>
struct iterator_traits<T*>
{
    typedef ptrdiff_t difference_type;
    typedef T value_type;
    typedef T* pointer;
    typedef T& reference;
    typedef std::random_access_iterator_tag iterator_category;
};

}

#endif