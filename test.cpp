#include <vector>
#include <string>
#include <map>
#include <iostream>
#include "containers/vector.hpp"

int	main() {
	std::map<int, int, std::greater<int>>	tab;

	tab.insert(std::pair<int,int>(0,0));
	tab.insert(std::pair<int,int>(1,1));
	tab.insert(std::pair<int,int>(2,2));
	tab.insert(std::pair<int,int>(3,3));
	tab.insert(std::pair<int,int>(4,4));
	tab.insert(std::pair<int,int>(5,5));
	tab.insert(std::pair<int,int>(6,6));

	for (std::map<int, int>::iterator it = tab.begin(); it != tab.end(); it++)
		std::cout << it->first << std::endl;

	return (0);
}