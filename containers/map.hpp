#ifndef MAP_HPP
# define MAP_HPP

# include <functional>
# include <memory>
# include "../utils/pair.hpp"
# include "../utils/rb_tree.hpp"
# include "../iterator/map_iterator.hpp"
# include "../utils/node.hpp"
# include "../utils/enable_if.hpp"
# include "../utils/is_integral.hpp"

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
		typedef typename ft::map_iterator<key_type, mapped_type>				const_iterator;
		typedef typename ft::map_reverse_iterator<key_type, mapped_type>		reverse_iterator;
		typedef typename ft::map_const_reverse_iterator<key_type, mapped_type>	const_reverse_iterator;
		// typedef typename Rep_type::size_type              						size_type;
		// typedef typename Rep_type::difference_type        						difference_type;

		class value_compare
		{   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
		friend class map;
		protected:
		Compare comp;
		value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
		public:
		typedef bool result_type;
		typedef value_type first_argument_type;
		typedef value_type second_argument_type;
		bool operator() (const value_type& x, const value_type& y) const
		{
			return comp(x.first, y.first);
		}
		}

	private:
		Rep_type			_tree;

	public:
		void	print_tree() {
			_tree.printTree();
			std::cout << "__________________\n";
		}
	/** CONSTRUCTORS **/
		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _tree(ft::rb_tree<key_type, mapped_type>(alloc, comp)) {}
		
		template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0) : _tree(ft::rb_tree<key_type, mapped_type>(alloc, comp)) {
				insert(first, last);
			}
		
		map (const map& x) : _tree(x._tree) {}
		~map() {}

	/** OPERATOR **/
		map& operator= (const map& x) {
			_tree = x._tree;
			return (*this);
		}
	
	/** ITERATORS **/
		iterator begin() {
			return (iterator(_tree.getFirst(true)));
		}
		const_iterator begin() const {
			return (const_iterator(_tree.getFirst(true)));
		}
		iterator end() {
			if (empty())
				return (begin());
			return (iterator(_tree.getLast(false)));
		}
		const_iterator end() const {
			if (empty())
				return (begin());
			return (const_iterator(_tree.getLast(false)));
		}

		reverse_iterator rbegin(){
			return (reverse_iterator(_tree.getLast(true)));
		}

		const_reverse_iterator rbegin() const {
			return (const_reverse_iterator(_tree.getLast(true)));
		}

    	reverse_iterator rend() {
			if (size() == 1)
				return (reverse_iterator(_tree.getFirst(true)));
			return (reverse_iterator(_tree.getFirst(false)));
		}

		const_reverse_iterator rend() const {
			if (size() == 1)
				return (const_reverse_iterator(_tree.getFirst(true)));
			return (const_reverse_iterator(_tree.getFirst(false)));
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
		node_type	*tmp = _tree.find_key(val.first);
		if (tmp)
			return (ft::make_pair(iterator(tmp), false));
		return (ft::make_pair(iterator(_tree.insert(val, NULL)), true));
	}

	iterator insert (iterator position, const value_type& val) {
		node_type	*tmp = _tree.find_key(val.first);
		if (tmp)
			return (iterator(tmp));
		return (iterator(_tree.insert(val, &(*position))));
	}

	template <class InputIterator>
		void insert (InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0) {
			node_type	*tmp;
			for (InputIterator it = first; it != last; it++) {
				tmp = _tree.find_key(it->first);
				if (!tmp)
					_tree.insert(*it, NULL);
			}
		}


	void	clear() {
		_tree.clear();
	}

	size_t erase (const key_type& k) {
		_tree.deleteNode(k);
		return (1);
	}

	void erase (iterator position) {
		_tree.deleteNode(position->first);
	}

	void erase (iterator first, iterator last,
				typename ft::enable_if<!ft::is_integral<iterator>::value, iterator>::type* = 0) {
		size_t	size_it = 0;
		for (iterator it = first; it != last; it++)
			size_it++;
		
		iterator	tmp;
		for (size_t i = 0; i < size_it; i++) {
			tmp = first;
			first++;
			_tree.deleteNode(tmp->first);
		}
	}

	void swap (map& x) {
		map			tmp_map;
		iterator	tmp_it;

		tmp_it = x.begin();
		for (size_t i = 0; i < x.size(); i++) {
			tmp_map.insert(*tmp_it);
			tmp_it++;
		}

		x.clear();
		tmp_it = begin();
		for (size_t i = 0; i < size(); i++) {
			x.insert(*tmp_it);
			tmp_it++;
		}

		clear();
		tmp_it = tmp_map.begin();
		for (size_t i = 0; i < tmp_map.size(); i++) {
			insert(*tmp_it);
			tmp_it++;
		}
	}

	/** OPERATIONS **/
	size_t count (const key_type& k) const {
		if (_tree.find_key(k))
			return (1);
		return (0);
	}

    iterator find (const key_type& k) {
		node_type	*tmp = _tree.find_key(k);

		if (tmp)
			return (iterator(tmp));
		return (end());
	}

	const_iterator find (const key_type& k) const {
		node_type	*tmp = _tree.find_key(k);

		if (tmp)
			return (const_iterator(tmp));
		return (end());
	}

	pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
		node_type	*lower = _tree.find_key(k);

		if (lower) {
			node_type	*upper = lower->increment();
			return (ft::make_pair<const_iterator, const_iterator>(const_iterator(lower), const_iterator(upper)));
		}

		lower = _tree.findNextKey(k);
		return (ft::make_pair<const_iterator, const_iterator>(const_iterator(lower), const_iterator(lower)));
	}

	pair<iterator,iterator>             equal_range (const key_type& k) {
		node_type	*lower = _tree.find_key(k);

		if (lower) {
			node_type	*upper = lower->increment();
			return (ft::make_pair<iterator, iterator>(iterator(lower), iterator(upper)));
		}

		lower = _tree.findNextKey(k);
		return (ft::make_pair<iterator, iterator>(iterator(lower), iterator(lower)));
	}

    iterator lower_bound (const key_type& k) {
		node_type	*tmp = _tree.findNextKey(k);
		return (iterator(tmp));
	}

	const_iterator lower_bound (const key_type& k) const {
		node_type	*tmp = _tree.findNextKey(k);
		return (const_iterator(tmp));
	}

	iterator upper_bound (const key_type& k) {
		node_type	*tmp = _tree.findNextKey(k);
		if (tmp->data->first == k)
			return (iterator(tmp->increment()));
		return (iterator(tmp));
	}
	const_iterator upper_bound (const key_type& k) const {
		node_type	*tmp = _tree.findNextKey(k);
		if (tmp->data->first == k)
			return (const_iterator(tmp->increment()));
		return (const_iterator(tmp));
	}

	/** ACCESS **/

	mapped_type& operator[] (const key_type& k) {
		return (_tree.find_key(k)->data->second);
	}
};

template<typename Key, typename Tp, typename Compare, typename Alloc>
	inline bool operator==(const map<Key, Tp, Compare, Alloc>& x,
		const map<Key, Tp, Compare, Alloc>& y)
		{ return x._tree == y._tree; }

template<typename Key, typename Tp, typename Compare, typename Alloc>
	inline bool operator<(const map<Key, Tp, Compare, Alloc>& x,
		const map<Key, Tp, Compare, Alloc>& y)
		{ return x._tree < y._tree; }

template<typename Key, typename Tp, typename Compare, typename Alloc>
	inline bool operator!=(const map<Key, Tp, Compare, Alloc>& x,
		const map<Key, Tp, Compare, Alloc>& y)
		{ return !(x == y); }

template<typename Key, typename Tp, typename Compare, typename Alloc>
	inline bool operator>(const map<Key, Tp, Compare, Alloc>& x,
		const map<Key, Tp, Compare, Alloc>& y)
		{ return y < x; }

template<typename Key, typename Tp, typename Compare, typename Alloc>
	inline bool operator<=(const map<Key, Tp, Compare, Alloc>& x,
		const map<Key, Tp, Compare, Alloc>& y)
		{ return !(y < x); }

template<typename Key, typename Tp, typename Compare, typename Alloc>
	inline bool operator>=(const map<Key, Tp, Compare, Alloc>& x,
		const map<Key, Tp, Compare, Alloc>& y)
		{ return !(x < y); }

template<typename Key, typename Tp, typename Compare, typename Alloc>
	inline void swap(map<Key, Tp, Compare, Alloc>& x,
		map<Key, Tp, Compare, Alloc>& y)
		{ x.swap(y); }

}
#endif