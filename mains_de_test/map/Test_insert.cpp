#include "print_map.hpp"
#include <list>
#ifndef NAME_SPACE
# define NAME_SPACE std
#endif

using namespace NAME_SPACE;

#define T1 int
#define T2 std::string
typedef NAME_SPACE::map<T1, T2>::value_type T3;

static int iter = 0;

template <typename MAP, typename U>
void	ft_insert(MAP &mp, U param)
{
	_pair<NAME_SPACE::map<T1, T2>::iterator, bool> tmp;

	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	tmp = mp.insert(param);
	std::cout << "insert return: " << printPair(tmp.first);
	std::cout << "Created new node: " << tmp.second << std::endl;
	printSize(mp);
}

template <typename MAP, typename U, typename V>
void	ft_insert(MAP &mp, U param, V param2)
{
	NAME_SPACE::map<T1, T2>::iterator tmp;

	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	tmp = mp.insert(param, param2);
	std::cout << "insert return: " << printPair(tmp);
	printSize(mp);
}

template <typename MAP, typename U>
void	ft_insert(MAP &mp, U param, U param2)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	mp.insert(param, param2);
	printSize(mp);
}

int		main(void)
{
	{
		NAME_SPACE::map<T1, T2> mp, mp2;

		ft_insert(mp, T3(42, "lol"));
		ft_insert(mp, T3(42, "mdr"));

		ft_insert(mp, T3(50, "mdr"));
		ft_insert(mp, T3(35, "funny"));

		ft_insert(mp, T3(45, "bunny"));
		ft_insert(mp, T3(21, "fizz"));
		ft_insert(mp, T3(38, "buzz"));

		ft_insert(mp, mp.begin(), T3(55, "fuzzy"));

		ft_insert(mp2, mp2.begin(), T3(1337, "beauty"));
		ft_insert(mp2, mp2.end(), T3(1000, "Hello"));
		ft_insert(mp2, mp2.end(), T3(1500, "World"));
	}
	{
		std::list<T3> lst;
		std::list<T3>::iterator itlst;

		lst.push_back(T3(42, "lol"));

		lst.push_back(T3(50, "mdr"));
		lst.push_back(T3(35, "funny"));

		lst.push_back(T3(45, "bunny"));
		lst.push_back(T3(21, "fizz"));
		lst.push_back(T3(38, "buzz"));
		lst.push_back(T3(55, "fuzzy"));

		std::cout << "List contains:" << std::endl;
		for (itlst = lst.begin(); itlst != lst.end(); ++itlst)
			printPair(itlst);

		NAME_SPACE::map<T1, T2> mp;
		ft_insert(mp, lst.begin(), lst.end());

		lst.clear();

		lst.push_back(T3(87, "hey"));
		lst.push_back(T3(47, "eqweqweq"));
		lst.push_back(T3(35, "this key is already inside"));
		lst.push_back(T3(23, "but not that one"));
		lst.push_back(T3(1, "surprising isnt it?"));
		lst.push_back(T3(100, "is it enough??"));
		lst.push_back(T3(55, "inside map too"));

		std::cout << "List contains:" << std::endl;
		for (itlst = lst.begin(); itlst != lst.end(); ++itlst)
			printPair(itlst);

		ft_insert(mp, lst.begin(), lst.begin());
		ft_insert(mp, lst.begin(), lst.end());
	}
	return (0);
}
