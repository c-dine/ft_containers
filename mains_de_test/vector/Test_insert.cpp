#include "print_vector.hpp"

#ifndef NAME_SPACE
# define NAME_SPACE std
#endif

using namespace NAME_SPACE;

#define TESTED_TYPE int

template <class T>
void	insert_tests()
{
	std::cout << std::endl << "INSERT TESTS" << std::endl;
	vector<T> test(1, 1);
	vector<T> test2(5, 5);

	test.insert(test.begin(), 200, 12);
	printSize(test);
	test.insert(test.begin() + 12, 200, 30);
	printSize(test);
	test.insert(test.end(), 12, 50);
	printSize(test);
	test.insert(test.end() - 1, 0, 60);
	printSize(test);
	test.insert(test.end() - 1, 1, 70);
	printSize(test);
	test.insert(test.begin() + 412, test2.begin(), test2.end());
	printSize(test);
	test.insert(test.begin() + 6, test2.begin(), test2.end());
	printSize(test);
	test.insert(test.end(), test2.begin(), test2.end());
	printSize(test);
}

int		main(void)
{
	{
		NAME_SPACE::vector<TESTED_TYPE> vct(10);
		NAME_SPACE::vector<TESTED_TYPE> vct2;
		NAME_SPACE::vector<TESTED_TYPE> vct3;

		for (unsigned long int i = 0; i < vct.size(); ++i)
			vct[i] = (vct.size() - i) * 3;
		printSize(vct);

		vct2.insert(vct2.end(), 42);
		vct2.insert(vct2.begin(), 2, 21);
		printSize(vct2);

		vct2.insert(vct2.end() - 2, 42);
		printSize(vct2);

		vct2.insert(vct2.end(), 2, 84);
		printSize(vct2);

		vct2.resize(4);
		printSize(vct2);

		vct2.insert(vct2.begin() + 2, vct.begin(), vct.end());
		vct.clear();
		printSize(vct2);

		printSize(vct);

		for (int i = 0; i < 5; ++i)
			vct3.insert(vct3.end(), i);
		vct3.insert(vct3.begin() + 1, 2, 111);
		printSize(vct3);
	}
	{
		vector<int> myvector (3,100);
		vector<int>::iterator it;

		it = myvector.begin();
		it = myvector.insert ( it , 200 );

		myvector.insert (it,2,300);

		it = myvector.begin();

		vector<int> anothervector (2,400);
		myvector.insert (it+2,anothervector.begin(),anothervector.end());

		int myarray [] = { 501,502,503 };
		myvector.insert (myvector.begin(), myarray, myarray+3);

		std::cout << "myvector contains:";
		for (it=myvector.begin(); it<myvector.end(); it++)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	insert_tests<int>();
	{
		NAME_SPACE::vector<TESTED_TYPE> vct(5);
		NAME_SPACE::vector<TESTED_TYPE> vct2;
		const int cut = 3;

		for (unsigned long int i = 0; i < vct.size(); ++i)
			vct[i] = (vct.size() - i) * 7;
		printSize(vct);

		vct2.insert(vct2.begin(), vct.begin(), vct.begin() + cut);
		printSize(vct2);
		vct2.insert(vct2.begin(), vct.begin() + cut, vct.end());
		printSize(vct2);
		vct2.insert(vct2.end(), vct.begin(), vct.begin() + cut);
		printSize(vct2);

		std::cout << "insert return:" << std::endl;

		std::cout << *vct2.insert(vct2.end(), 42) << std::endl;
		std::cout << *vct2.insert(vct2.begin() + 5, 84) << std::endl;
		std::cout << "----------------------------------------" << std::endl;

		printSize(vct2);
	}
	return (0);
}
