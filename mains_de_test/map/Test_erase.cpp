#include "print_map.hpp"
#include <list>

#ifndef NAME_SPACE
# define NAME_SPACE std
#endif

using namespace NAME_SPACE;

#define TESTED_TYPE foo<int>
#define t_stack_ NAME_SPACE::stack<TESTED_TYPE>

#define T1 int
#define T2 std::string
typedef _pair<const T1, T2> T3;

static int iter = 0;

template <typename MAP, typename U>
void	ft_erase(MAP &mp, U param)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	mp.erase(param);
	printSize(mp);
}

template <typename MAP, typename U, typename V>
void	ft_erase(MAP &mp, U param, V param2)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	mp.erase(param, param2);
	printSize(mp);
}

int		main(void)
{
	{	
		std::list<T3> lst;
		unsigned int lst_size = 10;
		for (unsigned int i = 0; i < lst_size; ++i)
			lst.push_back(T3(i, std::string((lst_size - i), i + 65)));
		NAME_SPACE::map<T1, T2> mp(lst.begin(), lst.end());
		printSize(mp);

		ft_erase(mp, ++mp.begin());

		ft_erase(mp, mp.begin());
		ft_erase(mp, --mp.end());

		ft_erase(mp, mp.begin(), ++(++(++mp.begin())));
		ft_erase(mp, --(--(--mp.end())), --mp.end());

		mp[10] = "Hello";
		mp[11] = "Hi there";
		printSize(mp);
		ft_erase(mp, --(--(--mp.end())), mp.end());

		mp[12] = "ONE";
		mp[13] = "TWO";
		mp[14] = "THREE";
		mp[15] = "FOUR";
		printSize(mp);
		ft_erase(mp, mp.begin(), mp.end());
	}
	{
		std::list<T3> lst;
		unsigned int lst_size = 6;
		for (unsigned int i = 0; i < lst_size; ++i)
			lst.push_back(T3(i, std::string((lst_size - i), i + 65)));
		NAME_SPACE::map<T1, T2> mp(lst.begin(), lst.end());
		printSize(mp);

		for (int i = 2; i < 4; ++i)
			ft_erase(mp, i);

		ft_erase(mp, mp.begin()->first);
		ft_erase(mp, (--mp.end())->first);

		mp[-1] = "Hello";
		mp[10] = "Hi there";
		mp[10] = "Hi there";
		printSize(mp);

		ft_erase(mp, 0);
		ft_erase(mp, 1);
	}
	{
		NAME_SPACE::map<T1, T2> mp;

		mp[42] = "lol";

		mp[50] = "mdr";
		mp[25] = "funny";

		mp[46] = "bunny";
		mp[21] = "fizz";
		mp[30] = "buzz";
		mp[55] = "fuzzy";

		mp[18] = "bee";
		mp[23] = "coconut";
		mp[28] = "diary";
		mp[35] = "fiesta";
		mp[44] = "hello";
		mp[48] = "world";
		mp[53] = "this is a test";
		mp[80] = "hey";

		mp[12] = "no";
		mp[20] = "idea";
		mp[22] = "123";
		mp[24] = "345";
		mp[27] = "27";
		mp[29] = "29";
		mp[33] = "33";
		mp[38] = "38";

		mp[43] = "1";
		mp[45] = "2";
		mp[47] = "3";
		mp[49] = "4";
		mp[51] = "5";
		mp[54] = "6";
		mp[60] = "7";
		mp[90] = "8";

		printSize(mp);
		ft_erase(mp, 25); // right != NULL; left != NULL
		ft_erase(mp, 55); // right != NULL; left != NUL
		ft_erase(mp, 24); // right != NULL; left != NULL
		ft_erase(mp, 54); // right != NULL; left != NULL
		ft_erase(mp, 22); // right == NULL; left == NULL
		ft_erase(mp, 51); // right == NULL; left == NULL
		ft_erase(mp, 21); // right == NULL; left != NULL
		ft_erase(mp, 53); // right != NULL; left == NULL
		ft_erase(mp, 20); // right == NULL; left != NULL
		ft_erase(mp, 23); // right != NULL; left != NULL
		ft_erase(mp, 42); // right != NULL; left != NULL; parent == NULL
		ft_erase(mp, 38); // right != NULL; left != NULL; parent == NUL
		ft_erase(mp, 35); // right != NULL; left != NULL; parent == NULL
		ft_erase(mp, 33); // right != NULL; left != NULL; parent == NULL
		printSize(mp);
	}
	return (0);
}
