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
	ft::vector<std::string> vct;

	vct = ft::vector<std::string>(345667987654324567, "HELLoo");
	return (0);
}
