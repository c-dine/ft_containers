#include "print_vector.hpp"

#ifndef NAME_SPACE
# define NAME_SPACE std
#endif

using namespace NAME_SPACE;

#define TESTED_TYPE int

template <class T, class Alloc>
void	cmp(const NAME_SPACE::vector<T, Alloc> &lhs, const NAME_SPACE::vector<T, Alloc> &rhs)
{
	static int i = 0;

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
	std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
	std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}


int		main(void)
{
	{
		NAME_SPACE::vector<TESTED_TYPE> vct(4);
		NAME_SPACE::vector<TESTED_TYPE> vct2(4);

		cmp(vct, vct);  // 0
		cmp(vct, vct2); // 1

		vct2.resize(10);

		cmp(vct, vct2); // 2
		cmp(vct2, vct); // 3

		vct[2] = 42;

		cmp(vct, vct2); // 4
		cmp(vct2, vct); // 5

		swap(vct, vct2);

		cmp(vct, vct2); // 6
		cmp(vct2, vct); // 7
	}
	{
		vector<int> myvector (10);   // 10 zero-initialized elements

		vector<int>::size_type sz = myvector.size();

		printSize(myvector);

		// assign some values:
		for (unsigned i=0; i<sz; i++)
		{
			myvector[i]=i;
			printSize(myvector);
		}

		// reverse vector using operator[]:
		for (unsigned i=0; i<sz/2; i++)
		{
			int temp;
			temp = myvector[sz-1-i];
			myvector[sz-1-i]=myvector[i];
			myvector[i]=temp;
		}

		std::cout << "myvector contains:";
		for (unsigned i=0; i<sz; i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
	}
	{
		vector<int> foo (3,0);
		vector<int> bar (5,0);

		bar = foo;
		foo = vector<int>();

		std::cout << "Size of foo: " << int(foo.size()) << '\n';
		std::cout << "Size of bar: " << int(bar.size()) << '\n';
	}
	return (0);
}


