#include "print_vector.hpp"

#ifndef NAME_SPACE
# define NAME_SPACE std
#endif

using namespace NAME_SPACE;

#define TESTED_TYPE std::string

void	checkErase(NAME_SPACE::vector<TESTED_TYPE> const &vct,
					NAME_SPACE::vector<TESTED_TYPE>::const_iterator const &it)
{
	static int i = 0;
	std::cout << "[" << i++ << "] " << "erase: " << it - vct.begin() << std::endl;
	printSize(vct);
}

int		main(void)
{
	{
		NAME_SPACE::vector<TESTED_TYPE> vct(10);

		for (unsigned long int i = 0; i < vct.size(); ++i)
			vct[i] = std::string((vct.size() - i), i + 65);
		printSize(vct);

		checkErase(vct, vct.erase(vct.begin() + 2));

		checkErase(vct, vct.erase(vct.begin()));
		checkErase(vct, vct.erase(vct.end() - 1));

		checkErase(vct, vct.erase(vct.begin(), vct.begin() + 3));
		checkErase(vct, vct.erase(vct.end() - 3, vct.end() - 1));

		vct.push_back("Hello");
		vct.push_back("Hi there");
		printSize(vct);
		checkErase(vct, vct.erase(vct.end() - 3, vct.end()));

		vct.push_back("ONE");
		vct.push_back("TWO");
		vct.push_back("THREE");
		vct.push_back("FOUR");
		printSize(vct);
		checkErase(vct, vct.erase(vct.begin(), vct.end()));
	}
	{
		vector<int> myvector;

		for (int i=1; i<=10; i++) myvector.push_back(i);
		myvector.erase (myvector.begin()+5);
		myvector.erase (myvector.begin(),myvector.begin()+3);
		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); ++i)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
	}
	return (0);
}
