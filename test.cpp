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
                for (; it != ite; ++it) {
                        std::cout << "- " << printPair(it, false) << std::endl;
        		}
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
                std::cout << "-> " << printPair(it, false) << std::endl;
        }
        std::cout << "_______________________________________________" << std::endl;
}


#define T1 int
#define T2 std::string
typedef ft::map<T1, T2>::value_type T3;

static int iter = 0;

template <typename MAP>
void    ft_erase(MAP &mp, const T1 param)
{
        std::cout << "\t-- [" << iter++ << "] --" << std::endl;
        mp.erase(param);
        printSize(mp);
}

int             main(void)
{
        ft::map<T1, T2> mp;

        mp[42] = "lol";

        mp[50] = "mdr";
        mp[25] = "funny";

        mp[46] = "bunny";
        mp[21] = "fizz";
        mp[30] = "buzz";
        mp[55] = "fuzzy";

        mp[18] = "bee";
        mp[23] = "coconut";
        mp[28] = "diary";
        mp[35] = "fiesta";
        mp[44] = "hello";
        mp[48] = "world";
        mp[53] = "this is a test";
        mp[80] = "hey";

        mp[12] = "no";
        mp[20] = "idea";
        mp[22] = "123";
        mp[24] = "345";
        mp[27] = "27";
        mp[29] = "29";
        mp[33] = "33";
        mp[38] = "38";

        mp[43] = "1";
        mp[45] = "2";
        mp[47] = "3";
        mp[49] = "4";
        mp[51] = "5";
        mp[54] = "6";
        mp[60] = "7";
        mp[90] = "8";

        printSize(mp);

        /* A classic btree should give this:
         *                                      42
         *                     /                                            \
         *                    25                                            50
         *           /                 \                         /                       \
         *          21                 30                       46                       55
         *      /       \           /      \                /       \             /           \
         *     18       23        28        35            44         48         53             80
         *   /   \    /    \    /    \     /   \        /   \       /   \     /    \         /     \
         *  12   20  22    24  27    29  33    38     43    45    47    49   51    54       60      90
         *
         * */

        ft_erase(mp, 25); // right != NULL; left != NULL
        ft_erase(mp, 55); // right != NULL; left != NULL

        // /* After deleting 25 and 55, I would get:
        //  *                                      42
        //  *                     /                                            \
        //  *                    24                                            50
        //  *           /                 \                         /                      \
        //  *          21                 30                       46                      54
        //  *      /       \           /      \                /       \             /           \
        //  *     18       23        28        35            44         48         53             80
        //  *   /   \    /         /    \     /   \        /   \       /   \     /              /     \
        //  *  12   20  22        27    29  33    38     43    45    47    49   51             60      90
        //  *
        //  * */

        ft_erase(mp, 24); // right != NULL; left != NULL
        ft_erase(mp, 54); // right != NULL; left != NULL

        // /* After deleting 24 and 54, I would get:
        //  *                                      42
        //  *                     /                                            \
        //  *                    23                                            50
        //  *           /                 \                         /                      \
        //  *          21                 30                       46                      53
        //  *      /       \           /      \                /       \             /           \
        //  *     18       22        28        35            44         48         51             80
        //  *   /   \              /    \     /   \        /   \       /   \                    /     \
        //  *  12   20            27    29  33    38     43    45    47    49                  60      90
        //  *
        //  * */

        ft_erase(mp, 22); // right == NULL; left == NULL
        ft_erase(mp, 51); // right == NULL; left == NULL

        mp.print_tree();
        ft_erase(mp, 21); // right == NULL; left != NULL
        mp.print_tree();
        ft_erase(mp, 53); // right != NULL; left == NULL

        // /* After deleting 22, 51 and then 21, 53, I would get:
        //  *                                      42
        //  *                     /                                            \
        //  *                    23                                            50
        //  *           /                 \                         /                      \
        //  *          20                 30                       46                      80
        //  *      /                   /      \                /       \                /        \
        //  *     18                 28        35            44         48             60         90
        //  *   /                  /    \     /   \        /   \       /   \
        //  *  12                 27    29  33    38     43    45    47    49
        //  *
        //  * */

        // ft_erase(mp, 20); // right == NULL; left != NULL

        // /* After deleting 20, I would get:
        //  *                                      42
        //  *                     /                                            \
        //  *                    23                                            50
        //  *           /                 \                         /                      \
        //  *          18                 30                       46                      80
        //  *      /                   /      \                /       \                /        \
        //  *     12                 28        35            44         48             60         90
        //  *                      /    \     /   \        /   \       /   \
        //  *                     27    29  33    38     43    45    47    49
        //  *
        //  * */

        // ft_erase(mp, 23); // right != NULL; left != NULL

        // /* After deleting 23, I would get:
        //  *                                      42
        //  *                     /                                            \
        //  *                    18                                            50
        //  *           /                 \                         /                      \
        //  *          12                 30                       46                      80
        //  *                          /      \                /       \                /        \
        //  *                        28        35            44         48             60         90
        //  *                      /    \     /   \        /   \       /   \
        //  *                     27    29  33    38     43    45    47    49
        //  *
        //  * */

        // ft_erase(mp, 42); // right != NULL; left != NULL; parent == NULL

        // /* After deleting 42, I would get:
        //  *                                      38
        //  *                     /                                            \
        //  *                    18                                            50
        //  *           /                 \                         /                      \
        //  *          12                 30                       46                      80
        //  *                          /      \                /       \                /        \
        //  *                        28        35            44         48             60         90
        //  *                      /    \     /            /   \       /   \
        //  *                     27    29  33           43    45    47    49
        //  *
        //  * */

        // ft_erase(mp, 38); // right != NULL; left != NULL; parent == NULL

        // /* After deleting 38, I would get:
        //  *                                      35
        //  *                     /                                            \
        //  *                    18                                            50
        //  *           /                 \                         /                      \
        //  *          12                 30                       46                      80
        //  *                          /      \                /       \                /        \
        //  *                        28        33            44         48             60         90
        //  *                      /    \                  /   \       /   \
        //  *                     27    29               43    45    47    49
        //  *
        //  * */

        // ft_erase(mp, 35); // right != NULL; left != NULL; parent == NULL

        // /* After deleting 35, I would get:
        //  *                                      33
        //  *                     /                                            \
        //  *                    18                                            50
        //  *           /                 \                         /                      \
        //  *          12                 30                       46                      80
        //  *                          /                       /       \                /        \
        //  *                        28                      44         48             60         90
        //  *                      /    \                  /   \       /   \
        //  *                     27    29               43    45    47    49
        //  *
        //  * */

        // ft_erase(mp, 33); // right != NULL; left != NULL; parent == NULL

        // /* After deleting 33, I would get:
        //  *                                      30
        //  *                     /                                            \
        //  *                    18                                            50
        //  *           /                 \                         /                      \
        //  *          12                 28                       46                      80
        //  *                          /      \                /       \                /        \
        //  *                        27       29             44         48             60         90
        //  *                                              /   \       /   \
        //  *                                            43    45    47    49
        //  *
        //  * */

        return (0);
}