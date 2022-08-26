#include "print_vector.hpp"

#ifndef NAME_SPACE
# define NAME_SPACE std
#endif

using namespace NAME_SPACE;

#define TESTED_TYPE std::string

template <class T>
void	push_pop_back_tests(void)
{
	std::cout << std::endl << "PUSH BACK & POP BACK TESTS" << std::endl;
	vector<T> test;

	std::cout << "Empty ? " << test.empty() << " / Capacity : " << test.capacity() << " / Size : " << test.size() << std::endl;
	for (size_t i = 0; i < 51; i++)
	{
		test.push_back(i);
		std::cout << test.size() << ": " << test.capacity() << " - ";
		if (!(i % 10) && i != 0)
			std::cout << std::endl;
	}
	printSize(test);
	test.pop_back();
	test.pop_back();
	test.pop_back();
	test.pop_back();
	printSize(test);
}

int		main(void)
{
	{	
		NAME_SPACE::vector<TESTED_TYPE> vct(8);
		NAME_SPACE::vector<TESTED_TYPE> vct2;
		NAME_SPACE::vector<TESTED_TYPE>::iterator it = vct.begin();

		for (unsigned long int i = 0; i < vct.size(); ++i)
			it[i] = std::string((vct.size() - i), i + 65);
		printSize(vct, true);

		std::cout << "push_back():\n" << std::endl;

		vct.push_back("One long string");
		vct2.push_back("Another long string");

		printSize(vct);
		printSize(vct2);

		vct.pop_back();
		vct2.pop_back();

		printSize(vct);
		printSize(vct2);
	}
	{
		vector<int> myvector;
		int sum (0);
		myvector.push_back (100);
		myvector.push_back (200);
		myvector.push_back (300);

		while (!myvector.empty())
		{
			sum+=myvector.back();
			myvector.pop_back();
		}

		std::cout << "The elements of myvector add up to " << sum << '\n';

	}
	{
		vector<int> myvector;
		int myint = 42;

		do {
			myint += 5;
			myint /= 9;
			myint -= 2;
			myint *= 42;
			myvector.push_back (myint);
		} while (myint < 1000000);

			printSize(myvector);
		std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
	}
	push_pop_back_tests<int>();
	return (0);
}

