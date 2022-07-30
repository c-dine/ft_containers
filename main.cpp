#include "containers/vector.hpp"
#include "utils/is_integral.hpp"
#include "utils/enable_if.hpp"
#include "utils/pair.hpp"
#include "utils/rb_tree.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iterator>
#include <containers/stack.hpp>
#include <containers/map.hpp>


#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

using namespace NAMESPACE;

int	main() {
	{
		// ft::vector<int>		tab(1, 0);

		// for (int i = 0; i < 5; i++)
		// 	tab.push_back(i);
		// std::cout << "\ntab contains:";
		// for (unsigned i=0; i<tab.size(); ++i)
		// 	std::cout << ' ' << tab[i];

		// tab.erase(tab.begin());
		
		// std::cout << "\ntab contains:";
		// for (unsigned i=0; i<tab.size(); ++i)
		// 	std::cout << ' ' << tab[i];
	}
	{
		// ft::vector<int>		tab;
		// ft::vector<int>		tab1(10, 9);
		
		// for (int i = 0; i < 0; i++)
		// 	tab.push_back(i);
		// std::cout << "tab contains:";
		// for (unsigned i=0; i< tab.size(); ++i)
		// 	std::cout << ' ' << tab[i];

		// // tab.insert(tab.begin(), 3);
		// // tab.insert(tab.begin(), 4, 3);
		// tab.insert(tab.begin(), tab1.begin(), tab1.end());

		// std::cout << "\ntab contains:";
		// for (unsigned i=0; i<tab.size(); ++i)
		// 	std::cout << ' ' << tab[i];
		// std::cout << "\nSIZE: " << tab.size() << " ; CAPACITY: " << tab.capacity() << std::endl;
	}
	{
		// ft::vector<int> foo(3, 15);
		// ft::vector<int> bar(5, 42);
		
		// // ft::vector<int>::const_iterator it_foo = foo.begin();
		// // ft::vector<int>::const_iterator it_bar = bar.begin();

		// std::cout << "foo: " << foo.size() << "\tbar: " << bar.size() << "\n";
		// foo.swap(bar);
		// std::cout << "foo: " << foo.size() << "\tbar: " << bar.size() << "\n";
	}
	{
		// ft::vector<int>		tab(2,2);
		// std::vector<int>	tab2(2,2);

		// std::cout << tab.capacity() << std::endl;
		// std::cout << tab2.capacity() << std::endl << std::endl;

		// tab.push_back(3);
		// tab2.push_back(3);

		// std::cout << "FT PUSH_BACK:\t\t" << tab.capacity() << std::endl;
		// std::cout << "STD PUSH_BACK:\t\t" << tab2.capacity() << std::endl << std::endl;

		// tab.insert(tab.begin(), 15, 3);
		// tab2.insert(tab2.begin(), 15, 3);

		// std::cout << "FT INSERT:\t\t" << tab.capacity() << std::endl;
		// std::cout << "STD INSERT:\t\t" << tab2.capacity() << std::endl << std::endl;

		// tab.resize(547);
		// tab2.resize(547);
		// std::cout << "FT INSERT:\t\t" << tab.capacity() << std::endl;
		// std::cout << "STD INSERT:\t\t" << tab2.capacity() << std::endl << std::endl;
		// tab.resize(900);
		// tab2.resize(900);
		// std::cout << "FT INSERT:\t\t" << tab.capacity() << std::endl;
		// std::cout << "STD INSERT:\t\t" << tab2.capacity() << std::endl << std::endl;
		// tab.resize(1200);
		// tab2.resize(1200);

		// std::cout << "FT RESIZE:\t\t" << tab.capacity() << std::endl;
		// std::cout << "STD RESIZE:\t\t" << tab2.capacity() << std::endl << std::endl;

		// tab.reserve(650);
		// tab2.reserve(650);

		// std::cout << "FT RESERVE:\t\t" << tab.capacity() << std::endl;
		// std::cout << "STD RESERVE:\t\t" << tab2.capacity() << std::endl << std::endl;

		// tab.assign(2000, 5);
		// tab2.assign(2000, 5);

		// std::cout << "FT ASSIGN:\t\t" << tab.capacity() << std::endl;
		// std::cout << "STD ASSIGN:\t\t" << tab2.capacity() << std::endl << std::endl;
	}
	{
		// RB TREE TESTS
		// ft::pair<int, int>	el(30, 45);
		// ft::rb_tree<int, int>	tree;

		// tree.insert(ft::pair<int, int>(35, 34));
		// tree.insert(ft::pair<int, int>(44, 23));
		// tree.insert(ft::pair<int, int>(10,24));
		// tree.insert(ft::pair<int, int>(13,14));
		// tree.insert(ft::pair<int, int>(61,34));
		// tree.printTree();
		// tree.deleteNode(10);
		// tree.deleteNode(44);
		// tree.deleteNode(13);
		// std::cout << "\n___________________________________________\n\n";
		// tree.printTree();
	}
	{
		ft::map<int, int>	tab;
		std::map<int, int>	tab1;

		tab.insert(ft::make_pair(50,3));
		tab.insert(ft::make_pair(100,3));
		tab.insert(ft::make_pair(0,3));
		tab.insert(ft::make_pair(20,3));
		tab.insert(ft::make_pair(70,3));
		tab.insert(ft::make_pair(2,3));
		tab.insert(ft::make_pair(3,3));
		tab.insert(ft::make_pair(4,3));
		tab.insert(ft::make_pair(5,3));
		std::cout << *tab.begin() << std::endl;
	}
	return 0;
}






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
