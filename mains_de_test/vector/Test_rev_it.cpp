#include "print_vector.hpp"

#ifndef NAME_SPACE
# define NAME_SPACE std
#endif

using namespace NAME_SPACE;

#define TESTED_TYPE int

int		main(void)
{
	{
		NAME_SPACE::vector<TESTED_TYPE> vct;
		NAME_SPACE::vector<TESTED_TYPE>::iterator it = vct.begin();
		NAME_SPACE::vector<TESTED_TYPE>::const_iterator cit = vct.begin();

		NAME_SPACE::vector<TESTED_TYPE>::reverse_iterator rit(it);

		NAME_SPACE::vector<TESTED_TYPE>::const_reverse_iterator crit(rit);
		NAME_SPACE::vector<TESTED_TYPE>::const_reverse_iterator crit_(it);
		NAME_SPACE::vector<TESTED_TYPE>::const_reverse_iterator crit_2(cit);
	}
	{
		const int size = 5;
		NAME_SPACE::vector<TESTED_TYPE> vct(size);
		NAME_SPACE::vector<TESTED_TYPE>::iterator it_ = vct.begin();
		NAME_SPACE::vector<TESTED_TYPE>::reverse_iterator it(it_);

		for (int i = 0; i < size; ++i)
			vct[i] = (i + 1) * 5;
		printSize(vct);

		std::cout << (it_ == it.base()) << std::endl;
		std::cout << (it_ == (it + 3).base()) << std::endl;

		std::cout << *(it.base() + 1) << std::endl;
		std::cout << *(it - 3) << std::endl;
		std::cout << *(it - 3).base() << std::endl;
		it -= 3;
		std::cout << *it.base() << std::endl;

		std::cout << "TEST OFFSET" << std::endl;
		std::cout << *(it) << std::endl;
		std::cout << *(it).base() << std::endl;
		std::cout << *(it - 0) << std::endl;
		std::cout << *(it - 0).base() << std::endl;
		std::cout << *(it - 1).base() << std::endl;
	}
	{
		const int size = 5;
		NAME_SPACE::vector<TESTED_TYPE> vct(size);
		NAME_SPACE::vector<TESTED_TYPE>::reverse_iterator it = vct.rbegin();
		NAME_SPACE::vector<TESTED_TYPE>::const_reverse_iterator ite = vct.rbegin();

		for (int i = 0; i < size; ++i)
			it[i] = (size - i) * 5;

		it = it + 5;
		it = 1 + it;
		it = it - 4;
		std::cout << *(it += 2) << std::endl;
		std::cout << *(it -= 1) << std::endl;

		*(it -= 2) = 42;
		*(it += 2) = 21;

		std::cout << "const_ite +=/-=: " << *(ite += 2) << " | " << *(ite -= 2) << std::endl;

		std::cout << "(it == const_it): " << (ite == it) << std::endl;
		std::cout << "(const_ite - it): " << (ite - it) << std::endl;
		std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

		printSize(vct, true);
	}
	{
		vector<int> myvector (5);  // 5 default-constructed ints

		int i=0;

		vector<int>::reverse_iterator rit = myvector.rbegin();
		for (; rit!= myvector.rend(); ++rit)
			*rit = ++i;

		std::cout << "myvector contains:";
		for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	{
		vector<int> myvector (5);  // 5 default-constructed ints

		vector<int>::reverse_iterator rit = myvector.rbegin();

		int i=0;
		for (rit = myvector.rbegin(); rit!= myvector.rend(); ++rit)
			*rit = ++i;

		std::cout << "myvector contains:";
		for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	return (0);
}
