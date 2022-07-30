#ifndef MAP_HPP
# define MAP_HPP

# include <functional>
# include <memory>
# include "../utils/pair.hpp"
# include "../utils/rb_tree.hpp"
# include "../iterator/map_iterator.hpp"
# include "../utils/node.hpp"

namespace ft {

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
		typedef ft::s_node<key_type, mapped_type>		node_type;
	
	private:
		typedef typename Alloc::value_type								Alloc_value_type;
		typedef typename Alloc::template rebind<value_type>::other		Pair_alloc_type;
		typedef	ft::rb_tree<key_type, mapped_type>						Rep_type;

	public:
		typedef typename Pair_alloc_type::pointer         						pointer;
		typedef typename Pair_alloc_type::const_pointer   						const_pointer;
		typedef typename Pair_alloc_type::reference       						reference;
		typedef typename Pair_alloc_type::const_reference 						const_reference;
		typedef typename ft::map_iterator<key_type, mapped_type>				iterator;
		typedef typename ft::map_const_iterator<key_type, mapped_type>				const_iterator;
		// typedef typename Rep_type::size_type              						size_type;
		// typedef typename Rep_type::difference_type        						difference_type;
		// typedef typename Rep_type::reverse_iterator       						reverse_iterator;
		// typedef typename Rep_type::const_reverse_iterator 						const_reverse_iterator;

	private:
		Rep_type			_tree;

	public:
	/** CONSTRUCTORS **/
		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {
			_tree = ft::rb_tree<key_type, mapped_type>(alloc, comp);
		}
		
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
		iterator begin() {
			return (iterator(_tree.getFirst()));
		}
		const_iterator begin() const {
			return (const_iterator(_tree.getFirst()));
		}
		iterator end() {
			if (empty())
				return (begin());
			return (iterator(_tree.getLast()));
		}
		const_iterator end() const {
			if (empty())
				return (begin());
			return (const_iterator(_tree.getLast()));
		}

	/** CAPACITY **/
	bool empty() const {
		if (!size())
			return (true);
		return (false);
	}

	size_t size() const {
		return (_tree.size_tree());
	}

	size_t max_size() const {
		return (_tree.max_size());
	}

	/** MODIFIERS **/
	ft::pair<iterator,bool> insert (const value_type& val) {
		node_type	*tmp = _tree.find_key(val._first);
		if (tmp)
			return (ft::make_pair(iterator(tmp), false));
		return (ft::make_pair(_tree.insert(val), true));
	}

	iterator insert (iterator position, const value_type& val);

	template <class InputIterator>
		void insert (InputIterator first, InputIterator last);

		
};

}
#endif