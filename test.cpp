#include <vector>
#include <string>
#include <iostream>
#include "containers/vector.hpp"

int	main() {
	ft::vector<int> tab(1,9);

	tab.assign(2,5);
	for (size_t i = 0; i < tab.size(); i++)
		std::cout << tab[0] << " ";
	std::cout << "\n";

	return (0);
}