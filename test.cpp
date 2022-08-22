#include <vector>
#include <string>
#include <map>
#include <iostream>
#include "containers/vector.hpp"
#include "utils/pair.hpp"
#include "containers/map.hpp"
#include "containers_test/srcs/base.hpp"

template <typename T>
std::string     printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
		std::cout << "TEST : " << *iterator << std::endl;
        o << "key: " << iterator->first << " | value: " << iterator->second;
        if (nl)
                o << std::endl;
        return ("");
}

template <typename T_MAP>
void    printSize(T_MAP const &mp, bool print_content = 1)
{
        std::cout << "size: " << mp.size() << std::endl;
        std::cout << "max_size: " << mp.max_size() << std::endl;
        if (print_content)
        {
                typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
                std::cout << std::endl << "Content is:" << std::endl;
                for (; it != ite; ++it)
                        std::cout << "- " << printPair(it, false) << std::endl;
        }
        std::cout << "###############################################" << std::endl;
}
template <typename T1, typename T2>
void    printReverse(ft::map<T1, T2> &mp)
{
        typename ft::map<T1, T2>::iterator it = mp.end(), ite = mp.begin();

        std::cout << "printReverse:" << std::endl;
        while (it != ite) {
                it--;
				std::cout << it->first << " ok\n";		
                // std::cout << "-> " << printPair(it, false) << std::endl;
        }
        std::cout << "_______________________________________________" << std::endl;
}

#define T1 int
#define T2 int

int             main(void)
{
        ft::map<T1, T2> const mp;
        ft::map<T1, T2>::iterator it = mp.begin(); // <-- error expected

        std::cout << it->second << std::endl;
        return (0);
}