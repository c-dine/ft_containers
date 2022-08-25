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
	ft::map<int, int>	tab;

	tab.insert(ft::make_pair(0,0));
	tab.insert(ft::make_pair(1,0));
	// for (int i = 0; i < 5; i++){
	// 	tab.insert(ft::make_pair(i,i));
	// }
	tab.print_tree();
	std::cout << tab.count(0) << std::endl;
	return (0);
}
