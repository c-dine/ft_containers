#include "print_stack.hpp"
#include <list>

#ifndef NAME_SPACE
# define NAME_SPACE std
#endif

using namespace NAME_SPACE;


#define TESTED_TYPE int
typedef std::list<TESTED_TYPE> container_type;
#define t_stack_ NAME_SPACE::stack<TESTED_TYPE, container_type>

template <class T_STACK>
void	cmp(const T_STACK &lhs, const T_STACK &rhs)
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
		container_type	ctnr;

		ctnr.push_back(21);
		ctnr.push_back(42);
		ctnr.push_back(1337);
		ctnr.push_back(19);
		ctnr.push_back(0);
		ctnr.push_back(183792);

		t_stack_	stck(ctnr);
		t_stack_	stck2(ctnr);

		cmp(stck, stck);  // 0
		cmp(stck, stck2); // 1

		stck2.push(60);
		stck2.push(61);
		stck2.push(62);

		cmp(stck, stck2); // 2
		cmp(stck2, stck); // 3

		stck.push(42);

		cmp(stck, stck2); // 4
		cmp(stck2, stck); // 5

		stck.push(100);

		cmp(stck, stck2); // 6
		cmp(stck2, stck); // 7
	}
	{
		container_type	ctnr;

		ctnr.push_back(21);
		ctnr.push_back(42);
		ctnr.push_back(1337);
		ctnr.push_back(19);
		ctnr.push_back(0);
		ctnr.push_back(183792);

		t_stack_	stck(ctnr);
		t_stack_	stck2(ctnr);

		cmp(stck, stck);  // 0
		cmp(stck, stck2); // 1

		stck2.push(60);
		stck2.push(61);
		stck2.push(62);

		cmp(stck, stck2); // 2
		cmp(stck2, stck); // 3

		stck.push(42);

		cmp(stck, stck2); // 4
		cmp(stck2, stck); // 5

		stck.push(100);

		cmp(stck, stck2); // 6
		cmp(stck2, stck); // 7
		return (0);
	}
	{
		stack<int> a, b, c;
		a.push(10);
		a.push(20);
		a.push(30);

		b.push(10);
		b.push(20);
		b.push(30);

		c.push(30);
		c.push(20);
		c.push(10);

		if (a==b) std::cout << "a and b are equal\n";
		if (b!=c) std::cout << "b and c are not equal\n";
		if (b<c) std::cout << "b is less than c\n";
		if (c>b) std::cout << "c is greater than b\n";
		if (a<=b) std::cout << "a is less than or equal to b\n";
		if (a>=b) std::cout << "a is greater than or equal to b\n";
	}
	return (0);
}


