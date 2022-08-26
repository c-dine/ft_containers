#include "print_map.hpp"
#include <list>

#define T1 int
#define T2 std::string
typedef NAME_SPACE::map<T1, T2>::value_type T3;

#define T4 int
#define T5 int
typedef _pair<const T4, T5> T6;

int		main(void)
{
	{
		std::list<T3> lst;
		std::list<T3>::iterator itlst;

		lst.push_back(T3(42, "lol"));
		lst.push_back(T3(50, "mdr"));
		lst.push_back(T3(35, "funny"));
		lst.push_back(T3(45, "bunny"));
		lst.push_back(T3(21, "fizz"));
		lst.push_back(T3(35, "this key is already inside"));
		lst.push_back(T3(55, "fuzzy"));
		lst.push_back(T3(38, "buzz"));
		lst.push_back(T3(55, "inside too"));

		std::cout << "List contains: " << lst.size() << " elements." << std::endl;
		for (itlst = lst.begin(); itlst != lst.end(); ++itlst)
			printPair(itlst);
		std::cout << "---------------------------------------------" << std::endl;

		NAME_SPACE::map<T1, T2> mp(lst.begin(), lst.end());
		lst.clear();

		printSize(mp);
	}
	{
		std::list<T6> lst;
		unsigned int lst_size = 7;
		for (unsigned int i = 0; i < lst_size; ++i)
			lst.push_back(T6(lst_size - i, i));

		NAME_SPACE::map<T4, T5> mp(lst.begin(), lst.end());
		NAME_SPACE::map<T4, T5>::iterator it = mp.begin(), ite = mp.end();

		NAME_SPACE::map<T4, T5> mp_range(it, --(--ite));
		for (int i = 0; it != ite; ++it)
			it->second = ++i * 5;

		it = mp.begin(); ite = --(--mp.end());
		NAME_SPACE::map<T4, T5> mp_copy(mp);
		for (int i = 0; it != ite; ++it)
			it->second = ++i * 7;

		std::cout << "\t-- PART ONE --" << std::endl;
		printSize(mp);
		printSize(mp_range);
		printSize(mp_copy);

		mp = mp_copy;
		mp_copy = mp_range;
		mp_range.clear();

		std::cout << "\t-- PART TWO --" << std::endl;
		printSize(mp);
		printSize(mp_range);
		printSize(mp_copy);
	}
	return (0);
}
