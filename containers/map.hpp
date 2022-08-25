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
# include "../utils/lexicographical_compare.hpp"
# include "../iterator/reverse_iterator.hpp"

namespace ft {

template<
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Alloc = std::allocator<ft::pair<const Key, T> >
> class map {

	public:
		typedef	typename Alloc::value_type												value_type;
		typedef	Key													key_type;
		typedef	T													mapped_type;
		typedef	Compare												key_compare;
		typedef	Alloc												allocator_type;
		typedef ft::s_node<const key_type, mapped_type, key_compare>		node_type;
	
	private:
		typedef typename Alloc::template rebind<value_type>::other						Pair_alloc_type;
		typedef	ft::rb_tree<const key_type, mapped_type, key_compare, allocator_type>			Rep_type;

	public:
		typedef typename Pair_alloc_type::pointer         										pointer;
		typedef typename Pair_alloc_type::const_pointer   										const_pointer;
		typedef typename Pair_alloc_type::reference       										reference;
		typedef typename Pair_alloc_type::const_reference 										const_reference;
		typedef typename ft::map_iterator<const key_type, mapped_type, key_compare>					iterator;
		typedef typename ft::map_const_iterator<const key_type, mapped_type, key_compare>				const_iterator;
		typedef typename ft::reverse_iterator<iterator>											reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator>									const_reverse_iterator;
		typedef	typename Rep_type::value_compare												value_compare;
		// typedef typename Rep_type::size_type              						size_type;
		// typedef typename Rep_type::difference_type        						difference_type;


	private:
		Rep_type			*_tree;

	public:
		void	print_tree() {
			_tree->printTree();
			std::cout << "__________________\n";
		}
	/** CONSTRUCTORS **/
		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {
			_tree = new ft::rb_tree<const key_type, mapped_type, key_compare, allocator_type>(alloc, comp);
		}
		
		template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0) {
				_tree = new ft::rb_tree<const key_type, mapped_type, key_compare, allocator_type>(alloc, comp);
				insert(first, last);
			}
		
		map (const map& x) {
			_tree = new Rep_type;
			*this = x;
		}

		~map() {
			delete _tree;
		}

	/** OPERATOR **/
		map& operator= (const map& x) {
			if (size())
				clear();
			insert(x.begin(), x.end());
			return (*this);
		}
	
	/** ITERATORS **/
		iterator begin() {
			if (empty())
				return (iterator(_tree->getFloatingEnd(FLOATING_END)));
			return (iterator(_tree->getFirst(true)));
		}
		const_iterator begin() const {
			if (empty())
				return (const_iterator(_tree->getFloatingEnd(FLOATING_END)));
			return (const_iterator(_tree->getFirst(true)));
		}
		iterator end() {
			return (iterator(_tree->getFloatingEnd(FLOATING_END)));
		}
		const_iterator end() const {
			return (const_iterator(_tree->getFloatingEnd(FLOATING_END)));
		}

		reverse_iterator rbegin(){
			return (reverse_iterator(iterator(_tree->getLast(false))));
		}

		const_reverse_iterator rbegin() const {
			return (const_reverse_iterator(const_iterator(_tree->getLast(false))));
		}

    	reverse_iterator rend() {
			return (reverse_iterator(iterator(_tree->getFirst(true))));
		}

		const_reverse_iterator rend() const {
			return (const_reverse_iterator(const_iterator(_tree->getFirst(true))));
		}

	/** CAPACITY **/
	bool empty() const {
		if (!size())
			return (true);
		return (false);
	}

	size_t size() const {
		return (_tree->size_tree());
	}

	size_t max_size() const {
		return (_tree->max_size());
	}

	/** MODIFIERS **/
	ft::pair<iterator,bool> insert (const value_type& val) {
		node_type	*tmp = _tree->find_key(val.first);

		if (tmp)
			return (ft::make_pair(iterator(tmp), false));
		return (ft::make_pair(iterator(_tree->insert(val, NULL)), true));
	}

	iterator insert (iterator position, const value_type& val) {
		node_type	*tmp = _tree->find_key(val.first);
		if (tmp)
			return (iterator(tmp));

		if (position->first < val.first)
			return (iterator(_tree->insert(val, &(*position))));

		return (iterator(_tree->insert(val, NULL)));
	}

	template <class InputIterator>
		void insert (InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0) {
			node_type	*tmp;

			for (InputIterator it = first; it != last; it++) {
				tmp = _tree->find_key(it->first);
				if (!tmp || tmp->color == EMPTY)
					_tree->insert(*it, NULL);
			}
		}


	void	clear() {
		_tree->clear();
	}

	size_t erase (const key_type& k) {
		if (!_tree->find_key(k))
			return (0);
		_tree->deleteNode(k);
		return (1);
	}

	void erase (iterator position) {
		_tree->deleteNode(position->first);
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
			_tree->deleteNode(tmp->first);
		}
	}

	void swap (map& x) {
		Rep_type	*tmp;

		tmp = _tree;
		_tree = x._tree;
		x._tree = tmp;
	}

	/** OPERATIONS **/
	size_t count (const key_type& k) const {
		if (_tree->find_key(k))
			return (1);
		return (0);
	}

    iterator find (const key_type& k) {
		node_type	*tmp = _tree->find_key(k);

		if (tmp)
			return (iterator(tmp));
		return (end());
	}

	const_iterator find (const key_type& k) const {
		node_type	*tmp = _tree->find_key(k);

		if (tmp)
			return (const_iterator(tmp));
		return (end());
	}

	pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
		node_type	*lower = _tree->find_key(k);

		if (lower) {
			node_type	*upper = lower->increment();
			return (ft::make_pair<const_iterator, const_iterator>(const_iterator(lower), const_iterator(upper)));
		}

		lower = _tree->findNextKey(k);
		return (ft::make_pair<const_iterator, const_iterator>(const_iterator(lower), const_iterator(lower)));
	}

	pair<iterator,iterator>             equal_range (const key_type& k) {
		node_type	*lower = _tree->find_key(k);

		if (lower) {
			node_type	*upper = lower->increment();
			return (ft::make_pair<iterator, iterator>(iterator(lower), iterator(upper)));
		}

		lower = _tree->findNextKey(k);
		return (ft::make_pair<iterator, iterator>(iterator(lower), iterator(lower)));
	}

    iterator lower_bound (const key_type& k) {
		node_type	*tmp = _tree->findNextKey(k);
		return (iterator(tmp));
	}

	const_iterator lower_bound (const key_type& k) const {
		node_type	*tmp = _tree->findNextKey(k);
		return (const_iterator(tmp));
	}

	iterator upper_bound (const key_type& k) {
		node_type	*tmp = _tree->findNextKey(k);
		if (tmp->data->first == k)
			return (iterator(tmp->increment()));
		return (iterator(tmp));
	}
	const_iterator upper_bound (const key_type& k) const {
		node_type	*tmp = _tree->findNextKey(k);
		if (tmp->data->first == k)
			return (const_iterator(tmp->increment()));
		return (const_iterator(tmp));
	}

	/** OBSERVERS **/

	key_compare key_comp() const {
		return (_tree->getKeyComp());
	}

	value_compare value_comp() const {
		return (_tree->getValueComp());
	}

	/** ACCESS **/

	mapped_type& operator[] (const key_type& k) {
		node_type	*tmp = _tree->find_key(k);

		if (tmp)
			return (tmp->data->second);
		return (insert(ft::make_pair(k, mapped_type())).first->second);
	}

	Rep_type	getTree() const {
		return (_tree);
	}

	allocator_type get_allocator() const {
		return(_tree->get_allocator());
	}
};

template<typename Key, typename Tp, typename Compare, typename Alloc>
	inline bool operator==(const map<Key, Tp, Compare, Alloc>& x,
		const map<Key, Tp, Compare, Alloc>& y)
		{ 
			if (x.size() != y.size())
				return (false);

			ft::map_const_iterator<const Key, Tp, Compare>	x_it = x.begin();
			for (ft::map_const_iterator<const Key, Tp, Compare> y_it = y.begin(); y_it != y.end(); y_it++) {
				if (*x_it != *y_it || x_it == x.end())
					return (false);
				x_it++;
			}
			return (true);
		}

template<typename Key, typename Tp, typename Compare, typename Alloc>
	inline bool operator<(const map<Key, Tp, Compare, Alloc>& x,
		const map<Key, Tp, Compare, Alloc>& y)
		{ return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()); }

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