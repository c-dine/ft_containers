#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include "../utils/node.hpp"

namespace ft {
	
	template<typename key_type, typename mapped_type, typename value_type_, typename value_compare>
		class map_const_iterator;

	template<typename key_type, typename mapped_type, typename value_type_, typename value_compare>
		class map_iterator {
			public:
				typedef	value_type_								value_type;
				typedef value_type_&							reference;
				typedef value_type_*							pointer;
				typedef std::bidirectional_iterator_tag		iterator_category;
				typedef std::ptrdiff_t						difference_type;

				typedef map_iterator<key_type, mapped_type, value_type_, value_compare>			Self;
				typedef map_const_iterator<key_type, mapped_type, value_type_, value_compare>	const_iterator;
				typedef ft::s_node<key_type, mapped_type, value_type_, value_compare>		node_type;

			private:
				node_type	*_current;

			public:

			/******************/
			/** CONSTRUCTORS **/
			/******************/

				map_iterator() : _current() {}
				explicit map_iterator(node_type *x) : _current(x) {}
			
			
			/**************/
			/** OPERATOR **/
			/**************/
			
				reference	operator*() const {
					return (*(_current->data));
				}

				pointer		operator->() const {
					if (_current && _current->data)
						return (_current->data);
					return (NULL);
				}

				Self	&operator++() {
					_current = _current->increment();
					return (*this);
				}

				Self	operator++(int) {
					Self tmp = *this;
					_current = _current->increment();
					return (tmp);
				}

				Self	&operator--() {
					_current = _current->decrement();
					return (*this);
				}

				Self	operator--(int) {
					Self tmp = *this;
					_current = _current->decrement();
					return (tmp);
				}

				bool	operator==(const Self &x) const {
					return (_current == x._current);
				}

				bool	operator!=(const Self &x) const {
					return (_current->data != x._current->data);
				}

				Self base() const {
					return (Self(_current));
				}

				node_type	*getNode() const {
					return (_current);
				}
		};

		template<typename key_type, typename mapped_type, typename value_type_, typename value_compare>
		class map_const_iterator {
			public:
				typedef	const value_type_							value_type;
				typedef const value_type_&							reference;
				typedef const value_type_*							pointer;
				typedef std::bidirectional_iterator_tag				iterator_category;
				typedef std::ptrdiff_t								difference_type;

				typedef map_iterator<key_type, mapped_type, value_type_, value_compare>				iterator;
				typedef map_const_iterator<key_type, mapped_type, value_type_, value_compare>		Self;
				typedef const ft::s_node<key_type, mapped_type, value_type_, value_compare>		node_type;

			private:
				node_type	*_current;

			public:

			/******************/
			/** CONSTRUCTORS **/
			/******************/
				map_const_iterator() : _current() {}
				explicit map_const_iterator(node_type *x) : _current(x) {}
				map_const_iterator(const Self &x) : _current(x.getNode()) {}
				map_const_iterator(const iterator &x) : _current(x.getNode()) {}
			
			
			/**************/
			/** OPERATOR **/
			/**************/
			
				reference	operator*() const {
					return (*(_current->data));
				}

				pointer		operator->() const {
					if (_current && _current->data)
						return (_current->data);
					return (NULL);
				}

				Self	&operator++() {
					_current = _current->increment();
					return (*this);
				}

				Self	operator++(int) {
					Self tmp = *this;
					_current = _current->increment();
					return (tmp);
				}

				Self	&operator--() {
					_current = _current->decrement();
					return (*this);
				}

				Self	operator--(int) {
					Self tmp = *this;
					_current = _current->decrement();
					return (tmp);
				}

				bool	operator==(const Self &x) const {
					return (_current->data == x._current->data);
				}

				bool	operator!=(const Self &x) const {
					return (_current->data != x._current->data);
				}

				node_type	*getNode() const {
					return (_current);
				}

				Self base() const {
					return (Self(_current));
				}				
		};

	template<typename key_type, typename mapped_type, typename value_type_, typename value_compare>
		inline bool
		operator==(const map_iterator<key_type, mapped_type, value_type_, value_compare>& x,
					const map_const_iterator<key_type, mapped_type, value_type_, value_compare>& y)
		{ return x.getNode() == y.getNode(); }

	template<typename key_type, typename mapped_type, typename value_type_, typename value_compare>
		inline bool
		operator!=(const map_iterator<key_type, mapped_type, value_type_, value_compare>& x,
					const map_const_iterator<key_type, mapped_type, value_type_, value_compare>& y)
		{ return x.getNode() != y.getNode(); }
}
#endif