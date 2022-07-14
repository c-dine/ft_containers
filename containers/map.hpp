#ifndef MAP_HPP
# define MAP_HPP

# include <functional>
# include <memory>
# include "../utils/pair.hpp"

template<
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<std::pair<const Key, T> >
> class map {

	public:
		typedef	Key							key_type;
		typedef	T							mapped_type;
		typedef	ft::pair<const Key, T>		value_type;
		typedef	Compare						key_compare;
		typedef	Alloc						allocator_type;
	
	private:
		typedef typename _Alloc::value_type								Alloc_value_type;
		typedef typename Alloc::template rebind<value_type>::other		Pair_alloc_type;
		typedef _Rb_tree<key_type, value_type, _Select1st<value_type>,
				key_compare, _Pair_alloc_type> 							Rep_type;

		Rep_type	_tree;

	public:
		typedef typename Pair_alloc_type::pointer         pointer;
		typedef typename Pair_alloc_type::const_pointer   const_pointer;
		typedef typename Pair_alloc_type::reference       reference;
		typedef typename Pair_alloc_type::const_reference const_reference;
		typedef typename Rep_type::iterator               iterator;
		typedef typename Rep_type::const_iterator         const_iterator;
		typedef typename Rep_type::size_type              size_type;
		typedef typename Rep_type::difference_type        difference_type;
		typedef typename Rep_type::reverse_iterator       reverse_iterator;
		typedef typename Rep_type::const_reverse_iterator const_reverse_iterator;

		class value_compare : public std::binary_function<value_type, value_type, bool> {
			
		}
};

#endif