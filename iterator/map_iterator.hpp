#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include "../utils/rb_tree.hpp"

namespace ft {

	template<typename value_type, typename key_type>
		class map_iterator {
			public:
				typedef value_type&						reference;
				typedef value_type*						pointer;

				typedef map_iterator									Self;
				typedef ft::rb_tree<key_type, value_type>::t_node*		Link_type;

			private:
				Link_type	_current;

			public:
			/** CONSTRUCTOR **/
				map_iterator() : _current() {}
				explicit map_iterator(Link_type x) : _current(x) {}
				map_iterator(const iterator &x) : _current(x._current) {}
			/** OPERATOR **/
				reference	operator*() const {
					return (_current->data->_second);
				}

				pointer		operator->() const {
					return (&(_current->data->_second));
				}

				Self	&operator++() {
					_current = increment(_current);
					return (*this);
				}

				Self	operator++(int) {
					Self tmp = *this;
					_current = increment(_current);
					return (tmp);
				}

				Self	&operator--() {
					_current = decrement(_current);
					return (*this);
				}

				Self	operator--(int) {
					Self tmp = *this;
					_current = decrement(_current);
					return (tmp);
				}

				bool	operator==(const Self &x) const {
					return (_current == x._current);
				}

				bool	operator!=(const Self &x) const {
					return (_current != x._current);
				}

				Link_type	decrement(Link_type node) {
					if (node && node->left)
						return (node->left);
					if (node->parent && node->parent->left == node && node->parent->parent && node->parent == node->parent->parent->right)
						return (node->parent->parent);
					if (node->parent && node->parent->right == node)
						return (node->parent);
					return (node); // ??
				}

				Link_type	increment(Link_type node) {
					if (node && node->right)
						return (node->right);
					if (node->parent && node->parent->right == node && node->parent->parent && node->parent == node->parent->parent->left)
						return (node->parent->parent);
					if (node->parent && node->parent->left == node)
						return (node->parent);
					return (node); // ??
				}
		};
	// FAIRE CONST QD CA MARCHERA

	// template<typename key_type, typename value_type>
	// 	inline bool
	// 	operator==(const map_iterator<key_type, value_type>& __x,
	// 				const map_const_iterator<key_type, value_type>& __y)
	// 	{ return __x._M_node == __y._M_node; }

	// template<typename key_type, typename value_type>
	// 	inline bool
	// 	operator!=(const map_iterator<key_type, value_type>& __x,
	// 				const map_const_iterator<key_type, value_type>& __y)
	// 	{ return __x._M_node != __y._M_node; }

	// template<typename value_type, key_type>
	// 	class map_const_iterator {
	// 		public:
	// 			typedef value_type&						reference;
	// 			typedef value_type*						pointer;

	// 			typedef bidirectional_iterator_tag 		iterator_category;
	// 			typedef ptrdiff_t                  		difference_type;

	// 			typedef map_const_iterator					Self;
	// 			typedef ft::rb_tree<key_type, value_type>::t_node*							Link_type;

	// 		private:
	// 			Link_type	_current;
			
	// 		public:
	// 		/** CONSTRUCTOR **/
	// 			map_const_iterator() : _current() {}
	// 			explicit map_const_iterator(Link_type x) : _current(x) {}
	// 			map_const_iterator(const iterator &x) : _current(x._current) {}
	// 		/** OPERATOR **/
	// 			reference	operator*() const {
	// 				return (_current->data->_second);
	// 			}

	// 			pointer		operator->() const {
	// 				return (&(_current->data->_second));
	// 			}

	// 			Self	&operator++() {
	// 				_current = increment(_current);
	// 				return (*this);
	// 			}

	// 			Self	operator++(int) {
	// 				Self tmp = *this;
	// 				_current = increment(_current);
	// 				return (tmp);
	// 			}

	// 			Self	&operator--() {
	// 				_current = decrement(_current);
	// 				return (*this);
	// 			}

	// 			Self	operator--(int) {
	// 				Self tmp = *this;
	// 				_current = decrement(_current);
	// 				return (tmp);
	// 			}

	// 			bool	operator==(const Self &x) const {
	// 				return (_current == x._current);
	// 			}

	// 			bool	operator!=(const Self &x) const {
	// 				return (_current != x._current);
	// 			}
	// 	}
}
#endif