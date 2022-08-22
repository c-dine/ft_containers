#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include "../utils/node.hpp"

namespace ft {

	template<typename key_type, typename mapped_type>
		class map_iterator {
			public:
				typedef	ft::pair<key_type, mapped_type>		value_type;
				typedef value_type&							reference;
				typedef value_type*							pointer;

				typedef map_iterator							Self;
				typedef ft::s_node<key_type, mapped_type>		node_type;

			private:
				node_type	*_current;

			public:
			/** CONSTRUCTOR **/
				map_iterator() : _current() {}
				explicit map_iterator(node_type *x) : _current(x) {}
				map_iterator(const map_iterator &x) : _current(x.getNode()) {}
			/** OPERATOR **/
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
					return (_current != x._current);
				}

				Self base() const {
					return (Self(_current));
				}

				node_type	*getNode() const {
					return (_current);
				}
		};

		template<typename key_type, typename mapped_type>
		class map_const_iterator {
			public:
				typedef	ft::pair<key_type, mapped_type>		value_type;
				typedef const value_type&							reference;
				typedef const value_type*							pointer;

				typedef map_const_iterator							Self;
				typedef const ft::s_node<key_type, mapped_type>		node_type;

			private:
				node_type	*_current;

			public:
			/** CONSTRUCTOR **/
				map_const_iterator() : _current() {}
				explicit map_const_iterator(node_type *x) : _current(x) {}
				map_const_iterator(const map_const_iterator &x) : _current(x.getNode()) {}
				template <class InputIterator>
					map_const_iterator(const InputIterator &x) : _current(x.getNode()) {}
			/** OPERATOR **/
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
					return (_current != x._current);
				}

				ft::map_iterator<key_type, mapped_type> base() const {
					return (ft::map_iterator<key_type, mapped_type>(_current));
				}

				node_type	*getNode() const {
					return (_current);
				}
		};

	template<typename key_type, typename mapped_type>
		inline bool
		operator==(const map_iterator<key_type, mapped_type>& x,
					const map_const_iterator<key_type, mapped_type>& y)
		{ return x._current == y._current; }

	template<typename key_type, typename mapped_type>
		inline bool
		operator!=(const map_iterator<key_type, mapped_type>& x,
					const map_const_iterator<key_type, mapped_type>& y)
		{ return x._current != y._current; }


	/** REVERSE ITERATOR **/
		template<typename key_type, typename mapped_type>
		class map_reverse_iterator {
			public:
				typedef	ft::pair<key_type, mapped_type>		value_type;
				typedef value_type&							reference;
				typedef value_type*							pointer;

				typedef map_reverse_iterator					Self;
				typedef ft::s_node<key_type, mapped_type>		node_type;

			private:
				node_type	*_current;

			public:
			/** CONSTRUCTOR **/
				map_reverse_iterator() : _current() {}
				explicit map_reverse_iterator(node_type *x) : _current(x) {}
				map_reverse_iterator(const map_reverse_iterator &x) : _current(x.getNode()) {}
				template <class InputIterator>
					map_reverse_iterator(const InputIterator &x) : _current(x.getNode()) {}
			/** OPERATOR **/
				reference	operator*() const {
					return (*(_current->data));
				}

				pointer		operator->() const {
					if (_current && _current->data)
						return (_current->data);
					return (NULL);
				}

				Self	&operator++() {
					_current = _current->decrement();
					return (*this);
				}

				Self	operator++(int) {
					Self tmp = *this;
					_current = _current->decrement();
					return (tmp);
				}

				Self	&operator--() {
					_current = _current->increment();
					return (*this);
				}

				Self	operator--(int) {
					Self tmp = *this;
					_current = _current->increment();
					return (tmp);
				}

				bool	operator==(const Self &x) const {
					return (_current == x._current);
				}

				bool	operator!=(const Self &x) const {
					return (_current != x._current);
				}

				ft::map_iterator<key_type, mapped_type> base() const {
					return (ft::map_iterator<key_type, mapped_type>(_current));
				}

				node_type	*getNode() const {
					return (_current);
				}
		};

		template<typename key_type, typename mapped_type>
		class map_const_reverse_iterator {
			public:
				typedef	ft::pair<key_type, mapped_type>		value_type;
				typedef const value_type&							reference;
				typedef const value_type*							pointer;

				typedef map_const_reverse_iterator							Self;
				typedef const ft::s_node<key_type, mapped_type>		node_type;

			private:
				node_type	*_current;

			public:
			/** CONSTRUCTOR **/
				map_const_reverse_iterator() : _current() {}
				explicit map_const_reverse_iterator(node_type *x) : _current(x) {}
				map_const_reverse_iterator(const map_const_reverse_iterator &x) : _current(x.getNode()) {}
				template <class InputIterator>
					map_const_reverse_iterator(const InputIterator &x) : _current(x.getNode()) {}
			/** OPERATOR **/
				reference	operator*() const {
					return (*(_current->data));
				}

				pointer		operator->() const {
					if (_current && _current->data)
						return (_current->data);
					return (NULL);
				}

				Self	&operator++() {
					_current = _current->decrement();
					return (*this);
				}

				Self	operator++(int) {
					Self tmp = *this;
					_current = _current->decrement();
					return (tmp);
				}

				Self	&operator--() {
					_current = _current->increment();
					return (*this);
				}

				Self	operator--(int) {
					Self tmp = *this;
					_current = _current->increment();
					return (tmp);
				}

				bool	operator==(const Self &x) const {
					return (_current == x._current);
				}

				bool	operator!=(const Self &x) const {
					return (_current != x._current);
				}

				ft::map_iterator<key_type, mapped_type> base() const {
					return (ft::map_iterator<key_type, mapped_type>(_current));
				}

				node_type	*getNode() const {
					return (_current);
				}
		};

	template<typename key_type, typename mapped_type>
		inline bool
		operator==(const map_reverse_iterator<key_type, mapped_type>& x,
					const map_const_reverse_iterator<key_type, mapped_type>& y)
		{ return x._current == y._current; }

	template<typename key_type, typename mapped_type>
		inline bool
		operator!=(const map_reverse_iterator<key_type, mapped_type>& x,
					const map_const_reverse_iterator<key_type, mapped_type>& y)
		{ return x._current != y._current; }
}
#endif