#include "print_map.hpp"
#include <list>

#define T1 int
#define T2 int

#define T3 float
#define T4 foo<int>
typedef _pair<const T3, T4> T5;

#define T6 char
#define T7 int
typedef _pair<const T6, T7> T8;

int		main(void)
{
	{
		NAME_SPACE::map<T1, T2> mp;
		NAME_SPACE::map<T1, T2>::iterator it = mp.begin();
		NAME_SPACE::map<T1, T2>::const_iterator cit = mp.begin();

		NAME_SPACE::map<T1, T2>::reverse_iterator rit(it);

		NAME_SPACE::map<T1, T2>::const_reverse_iterator crit(rit);
		NAME_SPACE::map<T1, T2>::const_reverse_iterator crit_(it);
		NAME_SPACE::map<T1, T2>::const_reverse_iterator crit_2(cit);
	}
	std::cout << "OK" << std::endl;
	{
		std::list<T5> lst;
		unsigned int lst_size = 5;
		for (unsigned int i = 0; i < lst_size; ++i)
			lst.push_back(T5(2.5 - i, (i + 1) * 7));

		NAME_SPACE::map<T3, T4> mp(lst.begin(), lst.end());
		NAME_SPACE::map<T3, T4>::reverse_iterator it(mp.rbegin());
		NAME_SPACE::map<T3, T4>::const_reverse_iterator ite(mp.rbegin());
		printSize(mp);

		printPair(++ite);
		printPair(ite++);
		printPair(ite++);
		printPair(++ite);

		it->second.m();
		ite->second.m();

		printPair(++it);
		printPair(it++);
		printPair(it++);
		printPair(++it);

		printPair(--ite);
		printPair(ite--);
		printPair(--ite);
		printPair(ite--);

		(*it).second.m();
		(*ite).second.m();

		printPair(--it);
		printPair(it--);
		printPair(it--);
		printPair(--it);
	}
	{
		std::list<T8> lst;
		unsigned int lst_size = 5;
		for (unsigned int i = 0; i < lst_size; ++i)
			lst.push_back(T8('a' + i, (i + 1) * 7));

		NAME_SPACE::map<T6, T7> mp(lst.begin(), lst.end());
		NAME_SPACE::map<T6, T7>::iterator it_ = mp.begin();
		NAME_SPACE::map<T6, T7>::reverse_iterator it(it_), ite;
		printSize(mp);

		std::cout << (it_ == it.base()) << std::endl;
		std::cout << (it_ == dec(it, 3).base()) << std::endl;

		printPair(it.base());
		printPair(inc(it.base(), 1));

		std::cout << "TEST OFFSET" << std::endl;
		--it;
		printPair(it);
		printPair(it.base());

		it = mp.rbegin(); ite = mp.rend();
		while (it != ite)
			std::cout << "[rev] " << printPair(it++, false) << std::endl;
		printReverse(mp);
	}
	return (0);
}
