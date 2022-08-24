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
	ft::vector<std::string> vct(2, "hello");

	vct.resize(287, "How did you get this scar?");
	std::cout << vct.capacity() << std::endl;
	return (0);
}
