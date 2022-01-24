#include <map>
#include <iostream>
#include "TestsUtils.hpp"

void	mapTestBaseStd() {
	fStdMap<<"---Map-Test-Base-(namespace:std)---"<<std::endl;
	std::map<unsigned char, int> m;
	m['k'] = 1;
	m['i'] = 2;
	m['r'] = 3;
	m['i'] = 4;
	m['l'] = 5;
	m['l'] = 6;
	fStdMap<<m['k']<<m['i']<<m['r']<<m['i']<<m['l']<<std::endl;
	fStdMap<<"size = "<<m.size()<<std::endl;
	fStdMap<<"max_size = "<<m.max_size()<<std::endl;
	fStdMap<<"empty = "<<m.empty()<<std::endl;

	std::map<std::string, int> ms;
	ms["kirill"] = 1;
	ms["kshanti"] = 2;
	ms["home"] = 3;
	ms["chess"] = 4;
	ms["mac"] = 5;
	ms["mac"] = 6;
	fStdMap<<ms["kirill"]<<ms["kshanti"]<<ms["home"]<<ms["chess"]<<ms["mac"]<<std::endl;
	fStdMap<<"size = "<<ms.size()<<std::endl;
	fStdMap<<"empty = "<<ms.empty()<<std::endl;

	m.clear();
	fStdMap<<"size = "<<m.size()<<std::endl;
	fStdMap<<"empty = "<<m.empty()<<std::endl;

	m['k'] = 1;
	m['i'] = 2;
	m['r'] = 3;
	m['i'] = 4;
	m['l'] = 5;
	m['l'] = 6;
	std::map<unsigned char, int> m2;
	m2['k'] = 1000;
	m2['i'] = 20000;
	m2['l'] = 60000;
	m.swap(m2);
	fStdMap<<"size = "<<m.size()<<std::endl;
	fStdMap<<"size = "<<m2.size()<<std::endl;
	for (std::map<unsigned char, int>::iterator it = m.begin(); it != m.end(); ++it)
		fStdMap<<"1)"<<it->first<<" = "<<it->second<<std::endl;
	for (std::map<unsigned char, int>::iterator it = m2.begin(); it != m2.end(); ++it)
		fStdMap<<"2)"<<it->first<<" = "<<it->second<<std::endl;
}

void	mapTestIteratorStd() {
	fStdMap<<"---Map-Test-Iterator-(namespace:std)---"<<std::endl;
	std::map<int, int> map;
	map[0] = 0;
	map[10] = 10;
	map[-10] = -10;
	map[-1000] = -1000;
	map[1000] = 1000;
	for (std::map<int, int>::iterator it = map.begin(); it != map.end(); ++it)
		fStdMap<<it->first<<" = "<<it->second<<std::endl;
	for (std::map<int, int>::iterator it = map.begin(); it != map.end(); it++)
		fStdMap<<it->first<<" = "<<it->second<<std::endl;
	for (std::map<int, int>::reverse_iterator it = map.rbegin(); it != map.rend(); ++it)
		fStdMap<<it->first<<" = "<<it->second<<std::endl;
	for (std::map<int, int>::reverse_iterator it = map.rbegin(); it != map.rend(); it++)
		fStdMap<<it->first<<" = "<<it->second<<std::endl;
}