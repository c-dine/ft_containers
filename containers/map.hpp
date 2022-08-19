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
		typedef typename ft::map_const_iterator<key_type, mapped_type>			const_iterator;
		typedef typename ft::map_reverse_iterator<key_type, mapped_type>		reverse_iterator;
		typedef typename ft::map_const_reverse_iterator<key_type, mapped_type>	const_reverse_iterator;
		// typedef typename Rep_type::size_type              						size_type;
		// typedef typename Rep_type::difference_type        						difference_type;

	private:
		Rep_type			_tree;

	public:
		void	print_tree() {
			_tree.printTree();
			std::cout << "__________________\n";
		}
	/** CONSTRUCTORS **/
		explicit map (/* const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type() */) {
			// _tree = ft::rb_tree<key_type, mapped_type>(alloc, comp);
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
		return (ft::make_pair(_tree.insert(val), true));
	}

	iterator insert (iterator position, const value_type& val);

	template <class InputIterator>
		void insert (InputIterator first, InputIterator last);

	void	clear() {
		_tree.clear();
	}

	size_t erase (const key_type& k) {
		_tree.deleteNode(k);
		return (1);
	}

	void erase (iterator position);

	void erase (iterator first, iterator last);
};

}
#endif