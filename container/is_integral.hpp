#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

# include <stdio.h>

namespace ft{

struct true_type{
    static const bool	value = true;
};
struct false_type{
    static const bool	value = false;
};

template <class _Tp> struct is_integral				: public false_type {};
template <>			struct is_integral<bool>		: public true_type {};
template <>			struct is_integral<char>		: public true_type {};
template <>			struct is_integral<char16_t>	: public true_type {};
template <>			struct is_integral<char32_t>	: public true_type {};
template <>			struct is_integral<wchar_t>		: public true_type {};
template <>			struct is_integral<short>		: public true_type {};
template <>			struct is_integral<int>			: public true_type {};
template <>			struct is_integral<long>		: public true_type {};
template <>			struct is_integral<long long>	: public true_type {};
template <>			struct is_integral<size_t>		: public true_type {};

}

#endif