#include "print_stack.hpp"

#ifndef NAME_SPACE
# define NAME_SPACE std
#endif

using namespace NAME_SPACE;

#define TESTED_TYPE foo<int>
#define t_stack_ NAME_SPACE::stack
typedef t_stack_<TESTED_TYPE>::container_type container_type;

int		main(void)
{
	NAME_SPACE::stack<TESTED_TYPE> stck;

	std::cout << "empty: " << stck.empty() << std::endl;
	std::cout << "size: " << stck.size() << std::endl;

	stck.push(41);
	stck.push(29);
	stck.push(10);
	stck.push(42);
	std::cout << "Added some elements" << std::endl;

	std::cout << "empty: " << stck.empty() << std::endl;
	printSize(stck);

	return (0);
}
