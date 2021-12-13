#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft{

template <class T1, class T2>
struct pair{
public:
	typedef T1 first_type;
	typedef T2 second_type;

	first_type	first;
	second_type	second;
public:
	pair(){}
	pair(const first_type& x, const second_type& y) : first(x), second(y){}
	pair(const pair<first_type, second_type>& copy) : first(copy.first), second(copy.second){};
	~pair(){}

	pair&	operator=(const pair<first_type, second_type>& op){
		first = op.first();
		second = op.second();
		return (*this);
	}

	bool operator==(const pair<first_type, second_type>& op){
		if (first == op.first && second == op.second)
			return (true);
		return (false);
	}
	bool operator<(const pair<first_type, second_type>& op){
		if (first < op.first)
			return (true);
		if (first == op.first && second < op.second)
			return (true);
		return (false);
	}
	bool operator>(const pair<first_type, second_type>& op){
		if (first > op.first)
			return (true);
		if (first == op.first && second > op.second)
			return (true);
		return (false);
	}
	bool operator!=(const pair<first_type, second_type>& op){
		return (!operator==(op));
	}
	bool operator<=(const pair<first_type, second_type>& op){
		return (!operator>(op));
	}
	bool operator>=(const pair<first_type, second_type>& op){
		return (!operator<(op));
	}
};

template< class T1, class T2 >
ft::pair<T1,T2> make_pair( T1 first, T2 second ){
	return (ft::pair<T1,T2>(first, second));
}

}

#endif