#include "containers/vector.hpp"
#include "utils/is_integral.hpp"
#include "utils/enable_if.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <containers/stack.hpp>


#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

using namespace NAMESPACE;

int main()
{
        vector<int>                     test(3, 3);

        std::cout << "self assignation test\n";
        vector<vector<int> >    self_assign;
        vector<vector<int> >    *ptr = &self_assign;
        vector<vector<int> >    *ptr2 = &self_assign;

        self_assign.assign(4, test);
        *ptr = *ptr2;

        std::cout << std::boolalpha << (*ptr == *ptr2) << '\n';
//      self_assign = self_assign; //compiler doesn't like it!



        vector<vector<int> > JOHN;
        vector<vector<int> > BOB(5, test);
        std::cout << "BOB(5, test(test, 5)) : \n";
        for (size_t i = 0; i < BOB.size(); i++)
        {
                for (size_t j = 0; j < BOB[i].size(); j++)
                        std::cout << BOB[i][j] << ' ';
                std::cout << '\n';
        }
        vector<vector<int> > MIKE(BOB);

        // CTORs
        std::cout << "\nCTORS\n";
        std::cout << "Empty is empty ? " << std::boolalpha << JOHN.empty() << '\n';
        std::cout << "BOB is empty? " << BOB.empty() << '\n';

        std::cout << "Size of JOHN " << JOHN.size() << std::endl;
        std::cout << "Size of BOB " << BOB.size() << std::endl;
        std::cout << "Size of MIKE " << MIKE.size() << std::endl;

        // RESIZE
        size_t  bob_resize = 2;
        std::cout << "\nRESIZE\n";
        BOB.resize(bob_resize);
        std::cout << "Size of JOHN " << JOHN.size() << std::endl;
        if (JOHN.capacity() >= JOHN.size())
                std::cout << "Capacity of JOHN is sufficient\n";
        else
                std::cerr << "THERE IS A PROBLEM ON LINE 53\n";
        std::cout << "Size of BOB " << BOB.size() << std::endl;
        if (BOB.capacity() >= bob_resize)
                std::cout << "Capacity of BOB is sufficient\n";
        else
                std::cerr << "THERE IS A PROBLEM ON LINE 58\n";
        std::cout << "Size of MIKE " << MIKE.size() << std::endl;
        if (MIKE.capacity() >= MIKE.size())
                std::cout << "Capacity of MIKE is sufficient\n";
        else
                std::cerr << "THERE IS A PROBLEM ON LINE 63\n";

        size_t  mike_resize = 9;
        bob_resize = 0;

        BOB.resize(bob_resize);
        std::cout << "BOB is empty now ? " << BOB.empty() << '\n';
        MIKE.resize(mike_resize, test);
        std::cout << "Size of JOHN " << JOHN.size() << std::endl;
        if (JOHN.capacity() >= JOHN.size())
                std::cout << "Capacity of JOHN is sufficient\n";
        else
                std::cerr << "THERE IS A PROBLEM ON LINE 86\n";
        std::cout << "Size of BOB " << BOB.size() << std::endl;
        if (BOB.capacity() >= bob_resize)
                std::cout << "Capacity of BOB is sufficient\n";
        else
                std::cerr << "THERE IS A PROBLEM ON LINE 91\n";
        std::cout << "Size of MIKE " << MIKE.size() << std::endl;
        if (MIKE.capacity() >= mike_resize)
                std::cout << "Capacity of MIKE is sufficient\n";
        else
                std::cerr << "THERE IS A PROBLEM ON LINE 96\n";
        for (size_t i = 0; i < MIKE.size(); i++)
        {
                for (size_t j = 0; j < MIKE[i].size(); j++)
                {
                        std::cout << MIKE[i][j] << ' ';
                }
        std::cout << std::endl;
        }
        // RESERVE
        std::cout << "\nRESERVE\n";

        size_t  john_reserve = 0;
        size_t  bob_reserve = 3;
        size_t  mike_reserve = 4;

        JOHN.reserve(john_reserve);
        BOB.reserve(bob_reserve);
        MIKE.reserve(mike_reserve);
        std::cout << "Size of JOHN " << JOHN.size() << std::endl;
        if (JOHN.capacity() >= john_reserve)
                std::cout << "Capacity of JOHN is sufficient\n";
        else
                std::cerr << "THERE IS A PROBLEM ON LINE 120\n";
        std::cout << "Size of BOB " << BOB.size() << std::endl;
        if (BOB.capacity() >= bob_reserve)
                std::cout << "Capacity of BOB is sufficient\n";
        else
                std::cerr << "THERE IS A PROBLEM ON LINE 125\n";
        std::cout << "Size of MIKE " << MIKE.size() << std::endl;
        if (MIKE.capacity() >= mike_reserve)
                std::cout << "Capacity of MIKE is sufficient\n";
        else
                std::cerr << "THERE IS A PROBLEM ON LINE 130\n";
        for (size_t i = 0; i < MIKE.size(); i++)
        {
                for (size_t j = 0; j < MIKE[i].size(); j++)
                        std::cout << MIKE[i][j] << ' ';
        std::cout << std::endl;
        }

        //AT
        std::cout << "\nAT\n";
        try
        {
                std::cout << MIKE.at(2).front() << '\n';
                std::cout << MIKE.at(87).back() << '\n';
        }
        catch (std::out_of_range& oor)
        {
                (void)oor;
                std::cout << "OOR error caught\n";
        }

        // FRONT / BACK
        std::cout << "\nFRONT / BACK\n";
        std::cout << "front() of MIKE : " << MIKE.front().front() << '\n';
        std::cout << "back() of MIKE : " << MIKE.back().back() << '\n';

        //ASSIGN
        std::cout << "\nASSIGN\n";
        test.assign(3, 17);
        BOB.assign(3, test);

        //ASSIGN RANGE
        std::cout << "\nASSIGN RANGE\n";
        vector<vector<int> >    assign_range;
        assign_range.assign(8, test);
        assign_range.assign(BOB.begin() + 1, BOB.end() - 2);

        //EMPTY
        std::cout << "\nEMPTY\n";
        std::cout << "BOB is empty ? " << BOB.empty() << '\n';
        std::cout << "BOB at(1) : " << BOB.at(1).front() << '\n';

        //PUSH/POP_BACK
        std::cout << "\nPUSH/POP_BACK\n";
        test.assign(2, 42);
        BOB.push_back(test);
        std::cout << "last elem of BOB : " << BOB.back().back() << '\n';
        BOB.pop_back();
        std::cout << "last elem of BOB : " << BOB.back().back() << '\n';

        //INSERT
        std::cout << "\nINSERT\n";
        vector<vector<int> >    insert_in_me;
        for (int i = 0; i < 15; i++)
        {
                vector<int>     j(2, i);
                insert_in_me.push_back(j);
        }
        for (size_t i = 0; i < insert_in_me.size(); i++)
        {
                for (size_t j = 0; j < insert_in_me.at(i).size(); j++)
                        std::cout << insert_in_me.at(i).at(j) << ' ';
                std::cout << '\n';
        }

        vector<vector<int> >::iterator  tmp;
        test.assign(23, 19);
        tmp = insert_in_me.begin() + 4;
        insert_in_me.insert(tmp, 8, test);
        for (size_t i = 0; i < insert_in_me.size(); i++)
        {
                for (size_t j = 0; j < insert_in_me.at(i).size(); j++)
                        std::cout << insert_in_me.at(i).at(j) << ' ';
                std::cout << '\n';
        }

        vector<vector<int> >::const_iterator const_it(insert_in_me.begin());
        std::cout << "Const it.front() : " << std::endl;
        std::cout << (*const_it).front() << '\n';


        //INSERT
        std::cout << "\nINSERT\n";
        vector<vector<int> >    std_insert_in_me;
        for (int i = 0; i < 15; i++)
                std_insert_in_me.push_back(test);
        for (size_t i = 0; i < std_insert_in_me.size(); i++)
                std::cout << std_insert_in_me.at(i).front() << ' ';
        std::cout << '\n';

        vector<vector<int> >::iterator  std_tmp;
        std_tmp = std_insert_in_me.begin() + 4;
        std_insert_in_me.insert(std_tmp, 8, test);
        for (size_t i = 0; i < std_insert_in_me.size(); i++)
                std::cout << std_insert_in_me.at(i).back() << ' ';
        std::cout << '\n';


        //INSERT RANGE
        std::cout << "\nINSERT RANGE\n";
        vector<vector<int> >    insert_bis;
        for (int i = 0; i < 7; i++)
        {
                vector<int>     j(2, i * 3);
                insert_bis.push_back(j);
        }
        for (size_t i = 0; i < insert_bis.size(); i++)
                std::cout << insert_bis[i].back() << ' ';
        std::cout << '\n';

        insert_bis.insert(insert_bis.begin() + 5, insert_in_me.begin(), insert_in_me.end());
        for (size_t i = 0; i < insert_bis.size(); i++)
                std::cout << insert_bis[i].back() << ' ';
        std::cout << '\n';


        //ERASE
        std::cout << "\nERASE\n";
        vector<vector<int> >    erase_in_me;
        for (int i = 0; i < 15; i++)
        {
                vector<int>     j(1, i);
                erase_in_me.push_back(j);
        }
        for (size_t i = 0; i < erase_in_me.size(); i++)
                std::cout << erase_in_me.at(i).front() << ' ';
        std::cout << '\n';

        erase_in_me.erase(erase_in_me.begin() + 7);
        for (size_t i = 0; i < erase_in_me.size(); i++)
                std::cout << erase_in_me.at(i).front() << ' ';
        std::cout << '\n';
        erase_in_me.erase(erase_in_me.begin() + 2, erase_in_me.begin() + 6);
        for (size_t i = 0; i < erase_in_me.size(); i++)
                std::cout << erase_in_me.at(i).front() << ' ';
        std::cout << '\n';

        // //SWAP
        // std::cout << "\nSWAP\n";
        // john_reserve = 4;
        // JOHN.reserve(john_reserve);
        // BOB.swap(MIKE);
        // std::cout << "Size of JOHN " << JOHN.size() << std::endl;
        // if (JOHN.capacity() >= JOHN.size())
        //         std::cout << "Capacity of JOHN is sufficient\n";
        // else
        //         std::cerr << "THERE IS A PROBLEM ON LINE 272\n";
        // std::cout << "Size of BOB " << BOB.size() << std::endl;
        // if (BOB.capacity() >= BOB.size())
        //         std::cout << "Capacity of BOB is sufficient\n";
        // else
        //         std::cerr << "THERE IS A PROBLEM ON LINE 277\n";
        // std::cout << "Size of MIKE " << MIKE.size() << std::endl;
        // if (MIKE.capacity() >= MIKE.size())
        //         std::cout << "Capacity of MIKE is sufficient\n";
        // else
        //         std::cerr << "THERE IS A PROBLEM ON LINE 282\n";
        // for (size_t i = 0; i < MIKE.size(); i++)
        // {
        //         for (size_t j = 0; j < MIKE[i].size(); j++)
        //                 std::cout << MIKE[i][j] << ' ';
        // std::cout << std::endl;
        // }

        // MIKE.swap(JOHN);
        // std::cout << "Size of JOHN " << JOHN.size() << std::endl;
        // if (JOHN.capacity() >= JOHN.size())
        //         std::cout << "Capacity of JOHN is sufficient\n";
        // else
        //         std::cerr << "THERE IS A PROBLEM ON LINE 298\n";
        // std::cout << "Size of BOB " << BOB.size() << std::endl;
        // if (BOB.capacity() >= BOB.size())
        //         std::cout << "Capacity of BOB is sufficient\n";
        // else
        //         std::cerr << "THERE IS A PROBLEM ON LINE 303\n";
        // std::cout << "Size of MIKE " << MIKE.size() << std::endl;
        // if (MIKE.capacity() >= MIKE.size())
        //         std::cout << "Capacity of MIKE is sufficient\n";
        // else
        //         std::cerr << "THERE IS A PROBLEM ON LINE 308\n";
        // for (size_t i = 0; i < MIKE.size(); i++)
        // {
        //         for (size_t j = 0; j < MIKE[i].size(); j++)
        //                 std::cout << MIKE[i][j] << ' ';
        // std::cout << std::endl;
        // }

        // //CLEAR
        // std::cout << "\nCLEAR\n";
        // JOHN.clear();
        // MIKE.clear();
        // std::cout << "Size of JOHN " << JOHN.size() << std::endl;
        // if (JOHN.capacity() >= JOHN.size())
        //         std::cout << "Capacity of JOHN is sufficient\n";
        // else
        //         std::cerr << "THERE IS A PROBLEM ON LINE 327\n";
        // std::cout << "Size of BOB " << BOB.size() << std::endl;
        // if (BOB.capacity() >= BOB.size())
        //         std::cout << "Capacity of BOB is sufficient\n";
        // else
        //         std::cerr << "THERE IS A PROBLEM ON LINE 332\n";
        // std::cout << "Size of MIKE " << MIKE.size() << std::endl;
        // if (MIKE.capacity() >= MIKE.size())
        //         std::cout << "Capacity of MIKE is sufficient\n";
        // else
        //         std::cerr << "THERE IS A PROBLEM ON LINE 337\n";
        // for (size_t i = 0; i < MIKE.size(); i++)
        // {
        //         for (size_t j = 0; j < MIKE[i].size(); j++)
        //                 std::cout << MIKE[i][j] << ' ';
        // std::cout << std::endl;
        // }

        // //NON MEMBER Functions
        // std::cout << "\nNON MEMBER functions\n";
        // swap(BOB, MIKE);
        // std::cout << "Size of JOHN " << JOHN.size() << std::endl;
        // if (JOHN.capacity() >= JOHN.size())
        //         std::cout << "Capacity of JOHN is sufficient\n";
        // else
        //         std::cerr << "THERE IS A PROBLEM ON LINE 355\n";
        // std::cout << "Size of BOB " << BOB.size() << std::endl;
        // if (BOB.capacity() >= BOB.size())
        //         std::cout << "Capacity of BOB is sufficient\n";
        // else
        //         std::cerr << "THERE IS A PROBLEM ON LINE 360\n";
        // std::cout << "Size of MIKE " << MIKE.size() << std::endl;
        // if (MIKE.capacity() >= MIKE.size())
        //         std::cout << "Capacity of MIKE is sufficient\n";
        // else
        //         std::cerr << "THERE IS A PROBLEM ON LINE 365\n";
        // for (size_t i = 0; i < MIKE.size(); i++)
        // {
        //         for (size_t j = 0; j < MIKE[i].size(); j++)
        //                 std::cout << MIKE[i][j] << ' ';
        // std::cout << std::endl;
        // }

        // //RELATIONAL OPERATORS
        // std::cout << "\nRELATIONAL OPERATORS\n";
        // vector<vector<int> > MIKE_2(MIKE);
        // std::cout << "MIKE and BOB are equal ? " << (MIKE == BOB) << '\n';
        // std::cout << "MIKE and MIKE_2 are equal ? " << (MIKE == MIKE_2) << '\n';

        // std::cout << "\nReal Vector\n";
        // vector<vector<int> > real;
        // real.assign(5, test);
        // for (vector<vector<int> >::iterator it = real.begin(); it != real.end(); it++)
        //         std::cout << (*it).front() << " ";
        // std::cout << '\n';

        // std::cout << std::endl;
        return (0);
}








// int	main() {
// 	{
// 		// ft::vector<int>		tab(1, 0);

// 		// for (int i = 0; i < 5; i++)
// 		// 	tab.push_back(i);
// 		// std::cout << "\ntab contains:";
// 		// for (unsigned i=0; i<tab.size(); ++i)
// 		// 	std::cout << ' ' << tab[i];

// 		// tab.erase(tab.begin());
		
// 		// std::cout << "\ntab contains:";
// 		// for (unsigned i=0; i<tab.size(); ++i)
// 		// 	std::cout << ' ' << tab[i];
// 	}
// 	{
// 		// ft::vector<int>		tab;
// 		// ft::vector<int>		tab1(10, 9);
		
// 		// for (int i = 0; i < 0; i++)
// 		// 	tab.push_back(i);
// 		// std::cout << "tab contains:";
// 		// for (unsigned i=0; i< tab.size(); ++i)
// 		// 	std::cout << ' ' << tab[i];

// 		// // tab.insert(tab.begin(), 3);
// 		// // tab.insert(tab.begin(), 4, 3);
// 		// tab.insert(tab.begin(), tab1.begin(), tab1.end());

// 		// std::cout << "\ntab contains:";
// 		// for (unsigned i=0; i<tab.size(); ++i)
// 		// 	std::cout << ' ' << tab[i];
// 		// std::cout << "\nSIZE: " << tab.size() << " ; CAPACITY: " << tab.capacity() << std::endl;
// 	}
// 	{
// 		// ft::vector<int> foo(3, 15);
// 		// ft::vector<int> bar(5, 42);
		
// 		// // ft::vector<int>::const_iterator it_foo = foo.begin();
// 		// // ft::vector<int>::const_iterator it_bar = bar.begin();

// 		// std::cout << "foo: " << foo.size() << "\tbar: " << bar.size() << "\n";
// 		// foo.swap(bar);
// 		// std::cout << "foo: " << foo.size() << "\tbar: " << bar.size() << "\n";
// 	}
// 	{
// 		ft::vector<int>	tab(2,2);

// 		tab = ft::vector<int>();
// 		std::cout << tab.size() << std::endl;
// 	}
// 	return 0;
// }






// #include <iostream>
// #include <string>
// #include <deque>
// #if 1 //CREATE A REAL STL EXAMPLE
// 	#include <map>
// 	#include <stack>
// 	#include <vector>
// 	namespace ft = std;
// #else
// 	#include <map.hpp>
// 	#include <stack.hpp>
// 	#include <vector.hpp>
// #endif

// #include <stdlib.h>

// #define MAX_RAM 4294967296
// #define BUFFER_SIZE 4096
// struct Buffer
// {
// 	int idx;
// 	char buff[BUFFER_SIZE];
// };


// #define COUNT (MAX_RAM / (int)sizeof(Buffer))

// template<typename T>
// class MutantStack : public ft::stack<T>
// {
// public:
// 	MutantStack() {}
// 	MutantStack(const MutantStack<T>& src) { *this = src; }
// 	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
// 	{
// 		this->c = rhs.c;
// 		return *this;
// 	}
// 	~MutantStack() {}

// 	typedef typename ft::stack<T>::container_type::iterator iterator;

// 	iterator begin() { return this->c.begin(); }
// 	iterator end() { return this->c.end(); }
// };

// int main(int argc, char** argv) {
// 	if (argc != 2)
// 	{
// 		std::cerr << "Usage: ./test seed" << std::endl;
// 		std::cerr << "Provide a seed please" << std::endl;
// 		std::cerr << "Count value:" << COUNT << std::endl;
// 		return 1;
// 	}
// 	const int seed = atoi(argv[1]);
// 	srand(seed);

// 	ft::vector<std::string> vector_str;
// 	ft::vector<int> vector_int;
// 	ft::stack<int> stack_int;
// 	ft::vector<Buffer> vector_buffer;
// 	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
// 	ft::map<int, int> map_int;

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		vector_buffer.push_back(Buffer());
// 	}

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		const int idx = rand() % COUNT;
// 		vector_buffer[idx].idx = 5;
// 	}
// 	ft::vector<Buffer>().swap(vector_buffer);

// 	try
// 	{
// 		for (int i = 0; i < COUNT; i++)
// 		{
// 			const int idx = rand() % COUNT;
// 			vector_buffer.at(idx);
// 			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
// 		}
// 	}
// 	catch(const std::exception& e)
// 	{
// 		//NORMAL ! :P
// 	}
	
// 	for (int i = 0; i < COUNT; ++i)
// 	{
// 		map_int.insert(ft::make_pair(rand(), rand()));
// 	}

// 	int sum = 0;
// 	for (int i = 0; i < 10000; i++)
// 	{
// 		int access = rand();
// 		sum += map_int[access];
// 	}
// 	std::cout << "should be constant with the same seed: " << sum << std::endl;

// 	{
// 		ft::map<int, int> copy = map_int;
// 	}
// 	MutantStack<char> iterable_stack;
// 	for (char letter = 'a'; letter <= 'z'; letter++)
// 		iterable_stack.push(letter);
// 	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
// 	{
// 		std::cout << *it;
// 	}
// 	std::cout << std::endl;
// 	return (0);
// }
