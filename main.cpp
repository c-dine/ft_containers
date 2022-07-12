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
        vector<std::string> JOHN;
        vector<std::string> BOB(5, "Hello");
        std::cout << "BOB(5, 8) : ";
        for (size_t i = 0; i < BOB.size(); i++)
                std::cout << BOB[i] << ' ';
        std::cout << '\n';
        vector<std::string> MIKE(BOB);

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
        MIKE.resize(mike_resize, "juste some random std::string");
        /*
        std::cout << "Size of JOHN " << JOHN.size() << std::endl;
        std::cout << "Capacity of JOHN " << JOHN.capacity() << std::endl;
        std::cout << "Size of BOB " << BOB.size() << std::endl;
        std::cout << "Capacity of BOB " << BOB.capacity() << std::endl;
        std::cout << "Size of MIKE " << MIKE.size() << std::endl;
        std::cout << "Capacity of MIKE " << MIKE.capacity() << std::endl;
        */
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
                std::cout << MIKE[i] << ' ';
        std::cout << std::endl;

        // RESERVE
        std::cout << "\nRESERVE\n";

        size_t  john_reserve = 5;
        size_t  bob_reserve = 3;
        size_t  mike_reserve = 83;

        JOHN.reserve(john_reserve);
        BOB.reserve(bob_reserve);
        MIKE.reserve(mike_reserve);
        /*
        std::cout << "Size of JOHN " << JOHN.size() << std::endl;
        std::cout << "Capacity of JOHN " << JOHN.capacity() << std::endl;
        std::cout << "Size of BOB " << BOB.size() << std::endl;
        std::cout << "Capacity of BOB " << BOB.capacity() << std::endl;
        std::cout << "Size of MIKE " << MIKE.size() << std::endl;
        std::cout << "Capacity of MIKE " << MIKE.capacity() << std::endl;
        */
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
                std::cout << MIKE[i] << ' ';
        std::cout << std::endl;

        //AT
        std::cout << "\nAT\n";
        try
        {
                std::cout << MIKE.at(2) << '\n';
                std::cout << MIKE.at(87) << '\n';
        }
        catch (std::out_of_range& oor)
        {
                (void)oor;
                std::cout << "OOR error caught\n";
        }

        // FRONT / BACK
        std::cout << "\nFRONT / BACK\n";
        std::cout << "front() of MIKE : " << MIKE.front() << '\n';
        std::cout << "back() of MIKE : " << MIKE.back() << '\n';

        //ASSIGN
        std::cout << "\nASSIGN\n";
        BOB.assign(42, "James BOND");

        //ASSIGN RANGE
        std::cout << "\nASSIGN RANGE\n";
        vector<std::string>  assign_range;
        assign_range.assign(8, "Covfefe");
        assign_range.assign(BOB.begin() + 1, BOB.end() - 2);

        //EMPTY
        std::cout << "\nEMPTY\n";
        std::cout << "BOB is empty ? " << BOB.empty() << '\n';
        std::cout << "BOB at(41) : " << BOB.at(41) << '\n';

        //PUSH/POP_BACK
        std::cout << "\nPUSH/POP_BACK\n";
        BOB.push_back("My name is Bond");
        std::cout << "last elem of BOB : " << BOB.back() << '\n';
        BOB.pop_back();
        std::cout << "last elem of BOB : " << BOB.back() << '\n';

        //INSERT
        std::cout << "\nINSERT\n";
        vector<std::string>  insert_in_me;
        for (size_t i = 0; i < 15; i++)
                insert_in_me.push_back(std::to_string(i) + " I love hbaudet\n");
        std::cout << "after push_back, before at\n";
        for (size_t i = 0; i < insert_in_me.size(); i++)
                std::cout << insert_in_me.at(i) << ' ';
        std::cout << '\n';

        vector<std::string>::iterator        tmp;
        tmp = insert_in_me.begin() + 4;
        insert_in_me.insert(tmp, 8, "Norminet");
        for (size_t i = 0; i < insert_in_me.size(); i++)
                std::cout << insert_in_me.at(i) << ' ';
        std::cout << '\n';

        vector<std::string>::const_iterator const_it(insert_in_me.begin());
        std::cout << "Const it : " << std::endl;
        std::cout << *const_it << '\n';
//      *const_it = 89; // Does not compile because it's a const_iterator


//         //INSERT
//         std::cout << "\nINSERT\n";
//         vector<std::string>  std_insert_in_me;
//         for (size_t i = 0; i < 15; i++)
//                 std_insert_in_me.push_back(std::to_string(i) + " 42 ");
//         for (size_t i = 0; i < std_insert_in_me.size(); i++)
//                 std::cout << std_insert_in_me.at(i) << ' ';
//         std::cout << '\n';

//         vector<std::string>::iterator        std_tmp;
//         std_tmp = std_insert_in_me.begin() + 4;
//         std_insert_in_me.insert(std_tmp, 8, "Why are you reading this!?");
//         for (size_t i = 0; i < std_insert_in_me.size(); i++)
//                 std::cout << std_insert_in_me.at(i) << ' ';
//         std::cout << '\n';


//         //INSERT RANGE
//         std::cout << "\nINSERT RANGE\n";
//         vector<std::string>  insert_bis;
//         for (size_t i = 0; i < 7; i++)
//                 insert_bis.push_back(std::to_string(3 * i));
//         for (size_t i = 0; i < insert_bis.size(); i++)
//                 std::cout << insert_bis[i] << ' ';
//         std::cout << '\n';

//         insert_bis.insert(insert_bis.begin() + 5, insert_in_me.begin(), insert_in_me.end());
//         for (size_t i = 0; i < insert_bis.size(); i++)
//                 std::cout << insert_bis[i] << ' ';
//         std::cout << '\n';


//         //ERASE
//         std::cout << "\nERASE\n";
//         vector<std::string>  erase_in_me;
//         for (size_t i = 0; i < 15; i++)
//                 erase_in_me.push_back(std::to_string(2 * i));
//         for (size_t i = 0; i < erase_in_me.size(); i++)
//         {
// //              if (erase_in_me[i] < 10)
// //                      std::cout << ' ';
//                 std::cout << erase_in_me.at(i) << ' ';
//         }
//         std::cout << '\n';

//         erase_in_me.erase(erase_in_me.begin() + 7);
//         for (size_t i = 0; i < erase_in_me.size(); i++)
//         {
// //              if (erase_in_me[i] < 10)
// //                      std::cout << ' ';
//                 std::cout << erase_in_me.at(i) << ' ';
//         }
//         std::cout << '\n';

//         erase_in_me.erase(erase_in_me.begin() + 2, erase_in_me.begin() + 6);
//         for (size_t i = 0; i < erase_in_me.size(); i++)
//         {
// //              if (erase_in_me[i] < 10)
// //                      std::cout << ' ';
//                 std::cout << erase_in_me.at(i) << ' ';
//         }
//         std::cout << '\n';

//         //SWAP
//         std::cout << "\nSWAP\n";
//         BOB.swap(MIKE);
//         /*
//         std::cout << "Size of BOB " << BOB.size() << std::endl;
//         std::cout << "Capacity of BOB " << BOB.capacity() << std::endl;
//         std::cout << "Size of MIKE " << MIKE.size() << std::endl;
//         std::cout << "Capacity of MIKE " << MIKE.capacity() << std::endl;
//         */
//         std::cout << "Size of JOHN " << JOHN.size() << std::endl;
//         if (JOHN.capacity() >= JOHN.size())
//                 std::cout << "Capacity of JOHN is sufficient\n";
//         else
//                 std::cerr << "THERE IS A PROBLEM ON LINE 272\n";
//         std::cout << "Size of BOB " << BOB.size() << std::endl;
//         if (BOB.capacity() >= BOB.size())
//                 std::cout << "Capacity of BOB is sufficient\n";
//         else
//                 std::cerr << "THERE IS A PROBLEM ON LINE 277\n";
//         std::cout << "Size of MIKE " << MIKE.size() << std::endl;
//         if (MIKE.capacity() >= MIKE.size())
//                 std::cout << "Capacity of MIKE is sufficient\n";
//         else
//                 std::cerr << "THERE IS A PROBLEM ON LINE 282\n";
//         for (size_t i = 0; i < MIKE.size(); i++)
//                 std::cout << MIKE[i] << ' ';
//         std::cout << std::endl;

//         MIKE.swap(JOHN);
//         /*
//         std::cout << "Size of JOHN " << JOHN.size() << std::endl;
//         std::cout << "Capacity of JOHN " << JOHN.capacity() << std::endl;
//         std::cout << "Size of MIKE " << MIKE.size() << std::endl;
//         std::cout << "Capacity of MIKE " << MIKE.capacity() << std::endl;
//         */
//         std::cout << "Size of JOHN " << JOHN.size() << std::endl;
//         if (JOHN.capacity() >= JOHN.size())
//                 std::cout << "Capacity of JOHN is sufficient\n";
//         else
//                 std::cerr << "THERE IS A PROBLEM ON LINE 298\n";
//         std::cout << "Size of BOB " << BOB.size() << std::endl;
//         if (BOB.capacity() >= BOB.size())
//                 std::cout << "Capacity of BOB is sufficient\n";
//         else
//                 std::cerr << "THERE IS A PROBLEM ON LINE 303\n";
//         std::cout << "Size of MIKE " << MIKE.size() << std::endl;
//         if (MIKE.capacity() >= MIKE.size())
//                 std::cout << "Capacity of MIKE is sufficient\n";
//         else
//                 std::cerr << "THERE IS A PROBLEM ON LINE 308\n";
//         for (size_t i = 0; i < MIKE.size(); i++)
//                 std::cout << MIKE[i] << ' ';
//         std::cout << std::endl;

//         //CLEAR
//         std::cout << "\nCLEAR\n";
//         JOHN.clear();
//         MIKE.clear();
//         /*
//         std::cout << "Size of JOHN " << JOHN.size() << std::endl;
//         std::cout << "Capacity of JOHN " << JOHN.capacity() << std::endl;
//         std::cout << "Size of MIKE " << MIKE.size() << std::endl;
//         std::cout << "Capacity of MIKE " << MIKE.capacity() << std::endl;
//         */
//         std::cout << "Size of JOHN " << JOHN.size() << std::endl;
//         if (JOHN.capacity() >= JOHN.size())
//                 std::cout << "Capacity of JOHN is sufficient\n";
//         else
//                 std::cerr << "THERE IS A PROBLEM ON LINE 327\n";
//         std::cout << "Size of BOB " << BOB.size() << std::endl;
//         if (BOB.capacity() >= BOB.size())
//                 std::cout << "Capacity of BOB is sufficient\n";
//         else
//                 std::cerr << "THERE IS A PROBLEM ON LINE 332\n";
//         std::cout << "Size of MIKE " << MIKE.size() << std::endl;
//         if (MIKE.capacity() >= MIKE.size())
//                 std::cout << "Capacity of MIKE is sufficient\n";
//         else
//                 std::cerr << "THERE IS A PROBLEM ON LINE 337\n";
//         for (size_t i = 0; i < MIKE.size(); i++)
//                 std::cout << MIKE[i] << ' ';
//         std::cout << std::endl;

//         //NON MEMBER Functions
//         std::cout << "\nNON MEMBER functions\n";
//         swap(BOB, MIKE);
//         /*
//         std::cout << "Size of BOB " << BOB.size() << std::endl;
//         std::cout << "Capacity of BOB " << BOB.capacity() << std::endl;
//         std::cout << "Size of MIKE " << MIKE.size() << std::endl;
//         std::cout << "Capacity of MIKE " << MIKE.capacity() << std::endl;
//         */
//         std::cout << "Size of JOHN " << JOHN.size() << std::endl;
//         if (JOHN.capacity() >= JOHN.size())
//                 std::cout << "Capacity of JOHN is sufficient\n";
//         else
//                 std::cerr << "THERE IS A PROBLEM ON LINE 355\n";
//         std::cout << "Size of BOB " << BOB.size() << std::endl;
//         if (BOB.capacity() >= BOB.size())
//                 std::cout << "Capacity of BOB is sufficient\n";
//         else
//                 std::cerr << "THERE IS A PROBLEM ON LINE 360\n";
//         std::cout << "Size of MIKE " << MIKE.size() << std::endl;
//         if (MIKE.capacity() >= MIKE.size())
//                 std::cout << "Capacity of MIKE is sufficient\n";
//         else
//                 std::cerr << "THERE IS A PROBLEM ON LINE 365\n";
//         for (size_t i = 0; i < MIKE.size(); i++)
//                 std::cout << MIKE[i] << ' ';
//         std::cout << std::endl;

//         //RELATIONAL OPERATORS
//         std::cout << "\nRELATIONAL OPERATORS\n";
//         vector<std::string> MIKE_2(MIKE);
//         std::cout << "MIKE and BOB are equal ? " << (MIKE == BOB) << '\n';
//         std::cout << "MIKE and MIKE_2 are equal ? " << (MIKE == MIKE_2) << '\n';

//         vector<std::string> real;
//         real.assign(5, "foo");
//         for (vector<std::string>::iterator it = real.begin(); it != real.end(); it++)
//                 std::cout << *it << " ";
//         std::cout << '\n';

//         std::cout << std::endl;
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
