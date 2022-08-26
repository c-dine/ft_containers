#include "print_map.hpp"
#include <list>
#ifndef NAME_SPACE
# define NAME_SPACE std
#endif

using namespace NAME_SPACE;

#define T1 float
#define T2 foo<int>
#define T4 int
#define T5 int

typedef _pair<const T1, T2> T3;

int		main(void)
{
	{
		std::list<T3> lst;
		unsigned int lst_size = 5;
		for (unsigned int i = 0; i < lst_size; ++i)
			lst.push_back(T3(2.5 + i, i + 1));

		NAME_SPACE::map<T1, T2> mp(lst.begin(), lst.end());
		NAME_SPACE::map<T1, T2>::iterator it(mp.begin());
		NAME_SPACE::map<T1, T2>::const_iterator ite(mp.begin());
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
	
	return (0);
}
