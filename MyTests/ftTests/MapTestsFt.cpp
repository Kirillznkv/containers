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
	for (ft::map<int, int>::reverse_iterator it = map.rbegin(); it != map.rend(); ++it)
		fFtMap<<(*it).first<<" = "<<(*it).second<<std::endl;
	ft::map<int, int>::reverse_iterator rev_iter = ++map.rbegin();
	ft::map<int, int>::iterator iter = rev_iter.base();
	fFtMap<<iter->first<<" = "<<iter->second<<std::endl;
	fFtMap<<rev_iter->first<<" = "<<rev_iter->second<<std::endl;
}

void	mapTestObserversFt() {
	fFtMap<<"---Map-Test-Observers-(namespace:ft)---"<<std::endl;
	ft::map<std::string, int> map;
	map["hello"] = 1;
	map["world"] = 2;
	ft::map<std::string, int>::key_compare comp = map.key_comp();
	if (comp("hello", "world"))
		fFtMap<<"key hello < key world"<<std::endl;
	if (comp("world", "hello"))
		fFtMap<<"key world < key hello"<<std::endl;
	ft::map<std::string, int>::value_compare comp2 = map.value_comp();
	ft::map<std::string, int>::iterator it1 = map.begin(), it2 = ++map.begin();
	if (comp2(*it1, *it2))
		fFtMap<<"value hello < value world"<<std::endl;
	if (comp2(*it2, *it1))
		fFtMap<<"value world < value hello"<<std::endl;
}

void	mapTestOperationsFt() {
	fFtMap<<"---Map-Test-Operations-(namespace:ft)---"<<std::endl;
	//find
	ft::map<std::string, int> map;
	map["hello"] = 1;
	map["world"] = 2;
	map["home"] = 109;
	map["kv"] = 56;
	map["kazan"] = 22;
	map["msk"] = 77;
	ft::map<std::string, int>::iterator it;
	if ((it = map.find("kv")) != map.end())
		fFtMap<<it->first<<" = "<<it->second<<std::endl;
	else
		fFtMap<<"kv not found"<<std::endl;
	if ((it = map.find("world")) != map.end())
		fFtMap<<it->first<<" = "<<it->second<<std::endl;
	else
		fFtMap<<"world not found"<<std::endl;
	if ((it = map.find("aaaaaaaaaa")) != map.end())
		fFtMap<<it->first<<" = "<<it->second<<std::endl;
	else
		fFtMap<<"aaaaaaaaaa not found"<<std::endl;
	//coount
	ft::map<char,int> mymap;
	char c;
	mymap ['a']=101;
	mymap ['c']=202;
	mymap ['f']=303;
	for (c='a'; c<'h'; c++)
	{
		fFtMap << c;
		if (mymap.count(c)>0)
			fFtMap << " is an element of mymap.\n";
		else 
			fFtMap << " is not an element of mymap.\n";
	}
	//lower_bound/upper_bound
	{
	ft::map<char,int> mymap;
 	ft::map<char,int>::iterator itlow,itup;
	mymap['a']=20;
	mymap['b']=40;
	mymap['c']=60;
	mymap['d']=80;
	mymap['e']=100;
	itlow=mymap.lower_bound ('b');
	itup=mymap.upper_bound ('d');
	mymap.erase(itlow,itup);
	for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		fFtMap << it->first << " => " << it->second << '\n';
	}
	//equal_range
	{
	ft::map<char,int> mymap;
	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;
	ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
	ret = mymap.equal_range('b');
	fFtMap << "lower bound points to: ";
	fFtMap << ret.first->first << " => " << ret.first->second << '\n';
	fFtMap << "upper bound points to: ";
	fFtMap << ret.second->first << " => " << ret.second->second << '\n';
	}
}

void	mapTestModifiersFt() {
	fFtMap<<"---Map-Test-Modifiers-(namespace:ft)---"<<std::endl;
	ft::map<int, int> map1;
	ft::map<int, int> map2;
	map1[0] = 0;
	map1[1] = 1;
	map1[2] = 2;
	map1[3] = 3;
	map1[4] = 4;
	map1[5] = 5;

	map2[-1] = -1;
	map2[-2] = -2;
	//swap
	for (ft::map<int,int>::iterator it=map1.begin(); it!=map1.end(); ++it) {
		fFtMap << it->first << " => " << it->second << '\n';
	}
	for (ft::map<int,int>::iterator it=map2.begin(); it!=map2.end(); ++it) {
		fFtMap << it->first << " => " << it->second << '\n';
	}
	fFtMap<<map1.size()<<std::endl;
	fFtMap<<map2.size()<<std::endl;
	map1.swap(map2);
	for (ft::map<int,int>::iterator it=map1.begin(); it!=map1.end(); ++it) {
		fFtMap << it->first << " => " << it->second << '\n';
	}
	for (ft::map<int,int>::iterator it=map2.begin(); it!=map2.end(); ++it) {
		fFtMap << it->first << " => " << it->second << '\n';
	}
	fFtMap<<map1.size()<<std::endl;
	fFtMap<<map2.size()<<std::endl;
	map2.swap(map1);
	for (ft::map<int,int>::iterator it=map1.begin(); it!=map1.end(); ++it) {
		fFtMap << it->first << " => " << it->second << '\n';
	}
	for (ft::map<int,int>::iterator it=map2.begin(); it!=map2.end(); ++it) {
		fFtMap << it->first << " => " << it->second << '\n';
	}
	fFtMap<<map1.size()<<std::endl;
	fFtMap<<map2.size()<<std::endl;
	//erase
	{
	ft::map<char,int> mymap;
	ft::map<char,int>::iterator it;
	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;
	mymap['d']=40;
	mymap['e']=50;
	mymap['f']=60;

	it=mymap.find('b');
	mymap.erase (it);                   // erasing by iterator
	mymap.erase ('c');                  // erasing by key
	it=mymap.find ('e');
	mymap.erase ( it, mymap.end() );    // erasing by range
	for (it=mymap.begin(); it!=mymap.end(); ++it)
	  fFtMap << it->first << " => " << it->second << '\n';
	fFtMap<<mymap.size()<<std::endl;
	}
	//insert
	{
	ft::map<char,int> mymap;
	// first insert function version (single parameter):
	mymap.insert ( ft::pair<char,int>('a',100) );
	mymap.insert ( ft::pair<char,int>('z',200) );
	ft::pair<ft::map<char,int>::iterator,bool> ret;
	ret = mymap.insert ( ft::pair<char,int>('z',500) );
	if (ret.second==false) {
	  fFtMap << "element 'z' already existed";
	  fFtMap << " with a value of " << ret.first->second << '\n';
	}
	// second insert function version (with hint position):
	ft::map<char,int>::iterator it = mymap.begin();
	mymap.insert (it, ft::pair<char,int>('b',300));
	mymap.insert (it, ft::pair<char,int>('c',400));
	// third insert function version (range insertion):
	ft::map<char,int> anothermap;
	anothermap.insert(mymap.begin(),mymap.find('c'));
	// showing contents:
	fFtMap << "mymap contains:\n";
	for (it=mymap.begin(); it!=mymap.end(); ++it)
	  fFtMap << it->first << " => " << it->second << '\n';
	fFtMap << "anothermap contains:\n";
	for (it=anothermap.begin(); it!=anothermap.end(); ++it)
	  fFtMap << it->first << " => " << it->second << '\n';
	//clear
	fFtMap << mymap.size() << '\n';
	mymap.clear();
	fFtMap << mymap.size() << '\n';
	}
}