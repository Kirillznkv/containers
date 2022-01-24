#include "../../container/map/map.hpp"
#include <iostream>
#include "TestsUtils.hpp"

void	mapTestBaseFt() {
	fFtMap<<"---Map-Test-Base-(namespace:ft)---"<<std::endl;
	ft::map<unsigned char, int> m;
	m['k'] = 1;
	m['i'] = 2;
	m['r'] = 3;
	m['i'] = 4;
	m['l'] = 5;
	m['l'] = 6;
	fFtMap<<m['k']<<m['i']<<m['r']<<m['i']<<m['l']<<std::endl;
	fFtMap<<"size = "<<m.size()<<std::endl;
	fFtMap<<"max_size = "<<m.max_size()<<std::endl;
	fFtMap<<"empty = "<<m.empty()<<std::endl;

	ft::map<std::string, int> ms;
	ms["kirill"] = 1;
	ms["kshanti"] = 2;
	ms["home"] = 3;
	ms["chess"] = 4;
	ms["mac"] = 5;
	ms["mac"] = 6;
	fFtMap<<ms["kirill"]<<ms["kshanti"]<<ms["home"]<<ms["chess"]<<ms["mac"]<<std::endl;
	fFtMap<<"size = "<<ms.size()<<std::endl;
	fFtMap<<"empty = "<<ms.empty()<<std::endl;

	m.clear();
	fFtMap<<"size = "<<m.size()<<std::endl;
	fFtMap<<"empty = "<<m.empty()<<std::endl;

	m['k'] = 1;
	m['i'] = 2;
	m['r'] = 3;
	m['i'] = 4;
	m['l'] = 5;
	m['l'] = 6;
	ft::map<unsigned char, int> m2;
	m2['k'] = 1000;
	m2['i'] = 20000;
	m2['l'] = 60000;
	m.swap(m2);
	fFtMap<<"size = "<<m.size()<<std::endl;
	fFtMap<<"size = "<<m2.size()<<std::endl;
	for (ft::map<unsigned char, int>::iterator it = m.begin(); it != m.end(); ++it)
		fFtMap<<"1)"<<it->first<<" = "<<it->second<<std::endl;
	for (ft::map<unsigned char, int>::iterator it = m2.begin(); it != m2.end(); ++it)
		fFtMap<<"2)"<<it->first<<" = "<<it->second<<std::endl;
}

void	mapTestIteratorFt() {
	fFtMap<<"---Map-Test-Iterator-(namespace:ft)---"<<std::endl;
	ft::map<int, int> map;
	map[0] = 0;
	map[10] = 10;
	map[-10] = -10;
	map[-1000] = -1000;
	map[1000] = 1000;
	for (ft::map<int, int>::iterator it = map.begin(); it != map.end(); ++it)
		fFtMap<<it->first<<" = "<<it->second<<std::endl;
	for (ft::map<int, int>::iterator it = map.begin(); it != map.end(); it++)
		fFtMap<<it->first<<" = "<<it->second<<std::endl;
	for (ft::map<int, int>::reverse_iterator it = map.rbegin(); it != map.rend(); ++it)
		fFtMap<<it->first<<" = "<<it->second<<std::endl;
	for (ft::map<int, int>::reverse_iterator it = map.rbegin(); it != map.rend(); it++)
		fFtMap<<it->first<<" = "<<it->second<<std::endl;
}