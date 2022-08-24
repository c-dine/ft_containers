#include <vector>
#include <string>
#include <map>
#include <iomanip>
#include <iostream>
#include "containers/vector.hpp"
#include "utils/pair.hpp"
#include "containers/map.hpp"
#include "containers_test/srcs/base.hpp"

#define TESTED_TYPE int

int		main(void)
{
	ft::vector<TESTED_TYPE> vct(10);
	ft::vector<TESTED_TYPE> vct2;

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 3;
	// printSize(vct);

	vct2.insert(vct2.end(), 42);
	vct2.insert(vct2.begin(), 2, 21);
	// printSize(vct2);

	vct2.insert(vct2.end() - 2, 42);
	// printSize(vct2);

	vct2.insert(vct2.end(), 2, 84);
	// printSize(vct2);

	vct2.resize(4);
	// printSize(vct2);

	vct2.insert(vct2.begin() + 2, vct.begin(), vct.end());
	vct.clear();
	// printSize(vct2);

	// printSize(vct);
	return (0);
}
