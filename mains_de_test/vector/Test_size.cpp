#include "print_vector.hpp"

#ifndef NAME_SPACE
# define NAME_SPACE std
#endif

using namespace NAME_SPACE;

#define TESTED_TYPE int

void	is_empty(NAME_SPACE::vector<TESTED_TYPE> const &vct)
{
	std::cout << "is_empty: " << vct.empty() << std::endl;
}

int		main(void)
{
	{
		const int start_size = 7;
		NAME_SPACE::vector<TESTED_TYPE> vct(start_size, 20);
		NAME_SPACE::vector<TESTED_TYPE> vct2;
		NAME_SPACE::vector<TESTED_TYPE>::iterator it = vct.begin();

		for (int i = 2; i < start_size; ++i)
			it[i] = (start_size - i) * 3;
		printSize(vct, true);

		vct.resize(10, 42);
		printSize(vct, true);

		vct.resize(18, 43);
		printSize(vct, true);
		vct.resize(10);
		printSize(vct, true);
		vct.resize(23, 44);
		printSize(vct, true);
		vct.resize(5);
		printSize(vct, true);
		vct.reserve(5);
		vct.reserve(3);
		printSize(vct, true);
		vct.resize(87);
		vct.resize(5);
		printSize(vct, true);

		is_empty(vct2);
		vct2 = vct;
		is_empty(vct2);
		vct.reserve(vct.capacity() + 1);
		printSize(vct, true);
		printSize(vct2, true);

		vct2.resize(0);
		is_empty(vct2);
		printSize(vct2, true);
	}
	{
		vector<int> myints;
		std::cout << "0. size: " << myints.size() << '\n';

		for (int i=0; i<10; i++) myints.push_back(i);
		std::cout << "1. size: " << myints.size() << '\n';

		myints.insert (myints.end(),10,100);
		std::cout << "2. size: " << myints.size() << '\n';

		myints.pop_back();
		std::cout << "3. size: " << myints.size() << '\n';
	}
	return (0);
}