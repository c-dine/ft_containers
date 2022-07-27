#ifndef MAP_HPP
# define MAP_HPP

# include <functional>
# include <memory>
# include "../utils/pair.hpp"
# include "../utils/rb_tree.hpp"

template<
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Alloc = std::allocator<std::pair<const Key, T> >
> class map {

	public:
		typedef	Key							key_type;
		typedef	T							mapped_type;
		typedef	ft::pair<const Key, T>		value_type;
		typedef	Compare						key_compare;
		typedef	Alloc						allocator_type;
	
	private:
		typedef typename Alloc::value_type								Alloc_value_type;
		typedef typename Alloc::template rebind<value_type>::other		Pair_alloc_type;
		typedef /* _Rb_tree<key_type, value_type, _Select1st<value_type>,
				key_compare, Pair_alloc_type>  */	ft::rb_tree<key_type, value_type, key_compare>		Rep_type;

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
			friend class map<Key, T, Compare, Alloc>;
			protected:
				Compare	_comp;
				value_compare(Compare c) : _comp(c) {}
			public:
				bool operator()(const value_type& x, const value_type& y) const { return (_comp(x._first, y._first)); }
		};

		private:
			Rep_type			*_tree;
			allocator_type		_alloc;


	/** CONSTRUCTORS **/
		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _alloc(alloc) {}
		
		template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type());
			// A FAIRE PLUS TARD
		
		map (const map& x) : _tree(x._tree) {}
		~map() {}

	/** OPERATOR **/
		map& operator= (const map& x) {
			_tree = x._tree;
			return (*this);
		}
	
	/** ITERATORS **/

	/** CAPACITY **/
	bool empty() const {
		if (!size())
			return (true);
		return (false);
	}

	size_type size() const {
		return (_tree.size_tree());
	}

	size_type max_size() const {
		return (_alloc.max_size());
	}
		
};

#endif