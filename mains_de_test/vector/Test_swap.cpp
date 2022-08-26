#include "print_vector.hpp"

#ifndef NAME_SPACE
# define NAME_SPACE std
#endif

using namespace NAME_SPACE;

#define TESTED_TYPE int

int main ()
{
	{
		NAME_SPACE::vector<TESTED_TYPE> foo(3, 15);
		NAME_SPACE::vector<TESTED_TYPE> bar(5, 42);
		
		NAME_SPACE::vector<TESTED_TYPE>::const_iterator it_foo = foo.begin();
		NAME_SPACE::vector<TESTED_TYPE>::const_iterator it_bar = bar.begin();

		std::cout << "BEFORE SWAP" << std::endl;

		std::cout << "foo contains:" << std::endl;
		printSize(foo);
		std::cout << "bar contains:" << std::endl;
		printSize(bar);

		foo.swap(bar);

		std::cout << "AFTER SWAP" << std::endl;

		std::cout << "foo contains:" << std::endl;
		printSize(foo);
		std::cout << "bar contains:" << std::endl;
		printSize(bar);

		std::cout << "Iterator validity:" << std::endl;
		std::cout << (it_foo == bar.begin()) << std::endl;
		std::cout << (it_bar == foo.begin()) << std::endl;
	}
	{
		vector<int> foo,bar;

		foo.push_back(100);
		foo.push_back(200);

		bar.push_back(11);
		bar.push_back(22);
		bar.push_back(33);


		vector<int>::const_iterator tmp = foo.begin(); //tmp iterates through foo
		vector<int>::const_iterator tmp2 = bar.begin(); //tmp2 iterates through bar

		swap(bar, foo); //tmp iterates through bar
						//tmp2 iterates through foo


		vector<int>	other;

		other.push_back(73);
		other.push_back(173);
		other.push_back(763);
		other.push_back(73854);
		other.push_back(74683);
		other.push_back(753);

		vector<int>::const_iterator tmp3 = other.begin(); // tmp3 iterates through other

		std::cout << "foo contains:\n";
		for (vector<int>::iterator it=foo.begin(); it!=foo.end(); ++it)
			std::cout << *it << '\n';

		std::cout << "bar contains:\n";
		for (vector<int>::iterator it=bar.begin(); it!=bar.end(); ++it)
			std::cout << *it << '\n';

		while(tmp != bar.end())
		{
			std::cout << *tmp << '\n';
			tmp++;
		}
		tmp--;

		while(tmp2 != foo.end())
		{
			std::cout << *tmp2 << '\n';
			tmp2++;
		}
		tmp2--;

		swap(other, foo); //tmp2 iterates through other
						//tmp3 iterates throught foo
		printSize(other);
		printSize(foo);
		printSize(bar);
		while(tmp != bar.begin())
		{
			std::cout << *tmp << '\n';
			tmp--;
		}
		std::cout << *tmp << '\n';

		while(tmp2 != other.begin())
		{
			std::cout << *tmp2 << '\n';
			tmp2--;
		}
			std::cout << *tmp2 << '\n';

		while(tmp3 != foo.end())
		{
			std::cout << *tmp3 << '\n';
			tmp3++;
		}
		tmp3--;

		swap(bar, foo);
		swap(foo, bar);
		swap(bar, foo); //tmp3 iterates through bar
					//tmp iterates through foo

		printSize(other);
		printSize(foo);
		printSize(bar);

		while(tmp != foo.end())
		{
			std::cout << *tmp << '\n';
			tmp++;
		}

		while(tmp2 != other.end())
		{
			std::cout << *tmp2 << '\n';
			tmp2++;
		}

		while(tmp3 != bar.begin())
		{
			std::cout << *tmp3 << '\n';
			tmp3--;
		}
		std::cout << *tmp3 << '\n';
	}
	return (0);
}
