#include "print_stack.hpp"
#include <vector>

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
		stack<float>								other_stack;
		NAME_SPACE::vector<TESTED_TYPE>							lst;

		lst.push_back("salut");
		lst.push_back("tu vas bien?");
		lst.push_back("super");
		lst.push_back("et toi?");

		stack<TESTED_TYPE, vector<TESTED_TYPE> >	my_stack(lst);

		std::cout << std::boolalpha << other_stack.empty() << std::endl;
		other_stack.push(8.5); // 8.5;
		other_stack.push(42.4242); // 8.5; 42.4242;
		std::cout << other_stack.size() << '\n'; // 2
		other_stack.pop(); // 8.5;
		std::cout << other_stack.size() << '\n'; // 1
		other_stack.push(78541.987); // 8.5; 78541.987;
		std::cout << other_stack.size() << '\n'; // 2
		std::cout << other_stack.top() << '\n'; //78541.987
		std::cout << std::boolalpha << other_stack.empty() << std::endl;

		const TESTED_TYPE const_top = my_stack.top();

		std::cout << "const top: " << const_top << '\n';

		while (!my_stack.empty())
		{
			std::cout << my_stack.top() << '\n';
			my_stack.pop();
		}
	}
	{
		stack<int> mystack;

		for (int i=0; i<5; ++i) mystack.push(i);

		std::cout << "Popping out elements...";
		while (!mystack.empty())
		{
			std::cout << ' ' << mystack.top();
			mystack.pop();
		}
		std::cout << '\n';
	}
	{
		stack<int> mystack;

		for (int i=0; i<5; ++i) mystack.push(i);

		std::cout << "Popping out elements...";
		while (!mystack.empty())
		{
			std::cout << ' ' << mystack.top();
			mystack.pop();
		}
		std::cout << '\n';
	}
	{
		stack<int> mystack;

		mystack.push(10);
		mystack.push(20);

		mystack.top() -= 5;

		std::cout << "mystack.top() is now " << mystack.top() << '\n';
	}
	return (0);
}

