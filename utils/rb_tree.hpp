#ifndef RB_TREE_HPP
# define RB_TREE_HPP

# include "pair.hpp"
# include "stdlib.h"
// # include "../iterator/map_iterator.hpp"
# include <memory>
# include <stdio.h>
# define RED 1
# define BLACK 0

namespace ft {

template <typename key_type, typename value_type>
	struct s_node 
	{
			s_node								*address;
			ft::pair<key_type, value_type>		*data;
			struct s_node						*parent;
			struct s_node						*left;
			struct s_node						*right;
			bool								color; 
	};


template<
	class key_type,
	class value_type, 
	class key_compare = std::less<key_type>,
	class allocator_type = std::allocator<ft::pair<key_type, value_type> >
>	class rb_tree {

		public:
			class value_compare : public std::binary_function<value_type, value_type, bool> {
				protected:
					key_compare	_comp;
				public:
					value_compare(key_compare c) : _comp(c) {}
					bool operator()(const value_type& x, const value_type& y) const { return (_comp(x, y)); }
			};
			
		// typedef typename s_node<key_type, value_type>	s_node<key_type, value_type>;
        private:

            s_node<key_type, value_type>  											*_root;
			value_compare										_comp;
			std::allocator<s_node<key_type, value_type> >								_alloc;
			allocator_type										_alloc_pair;

		public:


		/** CONSTRUCTORS **/
			rb_tree(const allocator_type& alloc = allocator_type(), const key_compare& comp = key_compare()) : _comp(value_compare(comp)), _alloc_pair(alloc) {
				_root = NULL;
			}

            rb_tree(ft::pair<key_type, value_type> *element, const allocator_type& alloc = allocator_type(), const key_compare& comp = key_compare()) : _comp(comp), _alloc_pair(alloc) {
                _root = _alloc.allocate(1);
				_root->address = _root;
                _root->data = element;
				_root->parent = NULL;
				_root->left = NULL;
				_root->right = NULL;
				_root->color = BLACK;
            }

			~rb_tree() {
				free_nodes(_root);
			}

			void	free_nodes(s_node<key_type, value_type> *node) {
				if (node && node->left)
					free_nodes(node->left);
				if (node && node->right)
					free_nodes(node->right);
				if (node && node->data) {
					_alloc_pair.destroy(node->data);
					_alloc_pair.deallocate(node->data, 1);
				}
				if (node) 
					_alloc.deallocate(node->address, 1);
			}

		/** TOOLS **/

		s_node<key_type, value_type> *minimum(s_node<key_type, value_type> *node) {
			while (node->left != NULL) {
				node = node->left;
			}
			return (node);
		}

		void rbTransplant(s_node<key_type, value_type> *u, s_node<key_type, value_type> *v) {
			if (u->parent == NULL)
				_root = v;
			else if (u == u->parent->left)
				u->parent->left = v;
			else
				u->parent->right = v;
			if (v)
				v->parent = u->parent;
		}

		void leftRotate(s_node<key_type, value_type> *x) {
			s_node<key_type, value_type> *y = x->right;
			
			x->right = y->left;
			if (y->left != NULL)
				y->left->parent = x;
			y->parent = x->parent;
			if (x->parent == NULL)
				this->_root = y;
			else if (x == x->parent->left)
				x->parent->left = y;
			else
				x->parent->right = y;
			y->left = x;
			x->parent = y;
		}

		void rightRotate(s_node<key_type, value_type> *x) {
			s_node<key_type, value_type> *y = x->left;
		
			x->left = y->right;
			if (y->right != NULL)
				y->right->parent = x;
			y->parent = x->parent;
			if (x->parent == NULL)
				this->_root = y;
			else if (x == x->parent->right)
				x->parent->right = y;
			else
				x->parent->left = y;
			y->right = x;
			x->parent = y;
		}

		/** INSERT **/

		void insert(ft::pair<key_type, value_type> key) {
			s_node<key_type, value_type> *node = _alloc.allocate(1);
		
			node->data = _alloc_pair.allocate(1);
			_alloc_pair.construct(node->data, key);
			node->address = node;
			node->parent = NULL;
			node->left = NULL;
			node->right = NULL;
			node->color = 1;

			if (!_root) {
				_root = node;
				return;
			}

			s_node<key_type, value_type> *y = NULL;
			s_node<key_type, value_type> *x = this->_root;

			while (x != NULL) {
				y = x;
				if (_comp(node->data->_first, x->data->_first))
					x = x->left;
				else
					x = x->right;
			}

			node->parent = y;
			if (y == NULL)
				_root = node;
			else if (_comp(node->data->_first, y->data->_first))
				y->left = node;
			else
				y->right = node;

			if (node->parent == NULL) {
				node->color = 0;
				return;
			}

			if (node->parent->parent == NULL)
				return;

			insertFix(node);
		}

		void insertFix(s_node<key_type, value_type> *k) {
			s_node<key_type, value_type> *u;
			
			while (k->parent->color == 1) {
				if (k->parent == k->parent->parent->right) {
					u = k->parent->parent->left;
					if (u && u->color == 1) {
						u->color = 0;
						k->parent->color = 0;
						k->parent->parent->color = 1;
						k = k->parent->parent;
					} 
					else {
						if (k == k->parent->left) {
							k = k->parent;
							rightRotate(k);
						}
						k->parent->color = 0;
						k->parent->parent->color = 1;
						leftRotate(k->parent->parent);
					}
				}
				else {
					u = k->parent->parent->right;

					if (u && u->color == 1) {
						u->color = 0;
						k->parent->color = 0;
						k->parent->parent->color = 1;
						k = k->parent->parent;
					} 
					else {
						if (k == k->parent->right) {
							k = k->parent;
							leftRotate(k);
						}
						k->parent->color = 0;
						k->parent->parent->color = 1;
						rightRotate(k->parent->parent);
					}
				}
				if (k == _root) {
					break;
				}
			}
			_root->color = 0;
		}

		/** DELETE **/
  
  		void deleteNode(key_type data) {
    		deleteNodeHelper(_root, ft::pair<key_type, value_type>(data, 0));
  		}

		void deleteNodeHelper(s_node<key_type, value_type> *node, ft::pair<key_type, value_type> key) {
			s_node<key_type, value_type> *z = NULL;
			s_node<key_type, value_type> *x, *y;
			while (node != NULL) {
				if (*(node->data) == key)
					z = node;
				if (_comp(node->data->_first, key._first) || node->data->_first == key._first)
					node = node->right;
				else
					node = node->left;
			}

			if (z == NULL) {
				std::cout << "Key not found in the tree." << std::endl;
				return;
			}

			y = z;
			int y_original_color = y->color;
			if (z->left == NULL) {
				x = z->right;
				rbTransplant(z, z->right);
			} 
			else if (z->right == NULL) {
				x = z->left;
				rbTransplant(z, z->left);
			}
			else {
				y = minimum(z->right);
				y_original_color = y->color;
				x = y->right;
				if (y->parent == z) {
					x->parent = y;
				}
				else {
					rbTransplant(y, y->right);
					y->right = z->right;
					y->right->parent = y;
				}

				rbTransplant(z, y);
				y->left = z->left;
				y->left->parent = y;
				y->color = z->color;
			}
			_alloc_pair.destroy(z->data);
			_alloc_pair.deallocate(z->data, 1);
			_alloc.deallocate(z->address, 1);
			if (y_original_color == 0)
				deleteFix(x);
		}

		void deleteFix(s_node<key_type, value_type> *x) {
			s_node<key_type, value_type> *s;
			
			while (x && x != _root && x->color == 0) {
				if (x == x->parent->left) {
					s = x->parent->right;
					if (s->color == 1) {
					s->color = 0;
					x->parent->color = 1;
					leftRotate(x->parent);
					s = x->parent->right;
					}

					if (s->left->color == 0 && s->right->color == 0) {
					s->color = 1;
					x = x->parent;
					} else {
					if (s->right->color == 0) {
						s->left->color = 0;
						s->color = 1;
						rightRotate(s);
						s = x->parent->right;
					}

					s->color = x->parent->color;
					x->parent->color = 0;
					s->right->color = 0;
					leftRotate(x->parent);
					x = _root;
					}
				} else {
					s = x->parent->left;
					if (s->color == 1) {
					s->color = 0;
					x->parent->color = 1;
					rightRotate(x->parent);
					s = x->parent->left;
					}

					if (s->right->color == 0 && s->right->color == 0) {
					s->color = 1;
					x = x->parent;
					} else {
					if (s->left->color == 0) {
						s->right->color = 0;
						s->color = 1;
						leftRotate(s);
						s = x->parent->left;
					}

					s->color = x->parent->color;
					x->parent->color = 0;
					s->left->color = 0;
					rightRotate(x->parent);
					x = _root;
					}
				}
			}
			if (x)
				x->color = 0;
		}

		/** FIND **/
		s_node<key_type, value_type>	*search(s_node<key_type, value_type> *node, const key_type &k) {
			if (!node)
				return (NULL);
			if (node->data->_first == k)
				return (node);
			if (node && node->right)
				search(node->right, k);
			if (node && node->left)
				search(node->left, k);
		}

		ft::pair<key_type, value_type>	&find_key(const key_type& k) {
			s_node<key_type, value_type>	*tmp;

			tmp = search(_root, k);
			if (tmp)
				return (tmp->data);
			return (NULL);
		}

		/** MEMBER FUNCTIONS **/
			size_t	size(s_node<key_type, value_type> *node) {
				if (!node)
					return (0);
				else
					return (size(node->left) + 1 + size(node->right));
			}

			size_t size_tree() {
				return (size(_root));
			}

			void print_tree_helper(s_node<key_type, value_type> *n, int indent)
			{
				int i;
				if (n == NULL)
				{
					fputs("<empty tree>", stdout);
					return;
				}

				if (n->right != NULL)
					print_tree_helper(n->right, indent + 4);
				for(i = 0; i < indent; i++)
					fputs(" ", stdout);
				
				if (n->color == BLACK)
					std::cout << "\033[1;30m(" << *n->data << ")\033[0m\n";
				else
					std::cout << "\033[1;31m(" << *n->data << ")\033[0m\n";

				if (n->left != NULL)
					print_tree_helper(n->left, indent + 4);
			}
			
			void printTree()
			{
				print_tree_helper(_root, 4);
			}

    };

}

#endif