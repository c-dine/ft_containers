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
    class Alloc = std::allocator<ft::pair<const Key, T> >
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
		typedef	ft::rb_tree<key_type, value_type, key_compare, allocator_type>		Rep_type;

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

		private:
			Rep_type			*_tree;


	/** CONSTRUCTORS **/
		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _comp(comp) {}
		
		template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()) : _comp(comp);
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

	// ou alloc du tree ?
	size_type max_size() const {
		return (_alloc.max_size());
	}

	/** ELEMENT ACCESS **/
	reference operator[] (const key_type& k) {
		return (*(_start + n));
	}

	/** MODIFIERS **/
	pair<iterator,bool> insert (const value_type& val);

	iterator insert (iterator position, const value_type& val);

	template <class InputIterator>
		void insert (InputIterator first, InputIterator last);

		
};

#endif