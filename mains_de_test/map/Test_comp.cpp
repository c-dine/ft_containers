#include "print_map.hpp"
#ifndef NAME_SPACE
# define NAME_SPACE std
#endif

using namespace NAME_SPACE;

#define T1 char
#define T2 foo<float>
typedef NAME_SPACE::map<T1, T2> _map;
typedef _map::const_iterator const_it;

static unsigned int i = 0;

void	ft_comp(const _map &mp, const const_it &it1, const const_it &it2)
{
	bool res[2];

	std::cout << "\t-- [" << ++i << "] --" << std::endl;
	res[0] = mp.key_comp()(it1->first, it2->first);
	res[1] = mp.value_comp()(*it1, *it2);
	std::cout << "with [" << it1->first << " and " << it2->first << "]: ";
	std::cout << "key_comp: " << res[0] << " | " << "value_comp: " << res[1] << std::endl;
}


#define T3 int
#define T4 std::string

struct ft_more {
	bool	operator()(const T3 &first, const T3 &second) const {
		return (first > second);
	}
};

typedef NAME_SPACE::map<T3, T4, ft_more> ft_mp;
typedef NAME_SPACE::map<T3, T4, ft_more>::iterator ft_mp_it;

int		main(void)
{
	{
		_map	mp;

		mp['a'] = 2.3;
		mp['b'] = 1.4;
		mp['c'] = 0.3;
		mp['d'] = 4.2;
		printSize(mp);

		for (const_it it1 = mp.begin(); it1 != mp.end(); ++it1)
			for (const_it it2 = mp.begin(); it2 != mp.end(); ++it2)
				ft_comp(mp, it1, it2);

		printSize(mp);
	}
	{
		ft_mp mp;

		mp[42] = "fgzgxfn";
		mp[25] = "funny";
		mp[80] = "hey";
		mp[12] = "no";
		mp[27] = "bee";
		mp[90] = "8";
	}
	return (0);
}
