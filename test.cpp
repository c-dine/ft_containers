#include <vector>
#include <string>
#include <map>
#include <iomanip>
#include <iostream>
#include "containers/vector.hpp"
#include "utils/pair.hpp"
#include "containers/map.hpp"
#include "containers_test/srcs/base.hpp"


int		main(void)
{
	ft::vector<std::string> X;
	ft::vector<std::string> Y;

	X = Y;
	Y = X;
	Y.insert(Y.begin(), "y");

	ft::vector<std::string>::iterator it = Y.begin();
	ft::vector<std::string>::iterator it2 = it + 105;

	Y.erase(it, it2);
	X = Y;
	Y = X;
	Y.insert(Y.begin(), "y");
	Y.insert(Y.begin(), "y");
	Y.insert(Y.begin(), "y");
	Y.insert(Y.begin(), "y");
	Y.insert(Y.begin(), "y");
	Y.erase(it, it2);
	return (0);
}
