#ifndef RB_TREE_HPP
# define RB_TREE_HPP

# include "pair.hpp"
# include "stdlib.h"
# include <memory>
# include <stdio.h>
# define RED 1
# define BLACK 0

namespace ft {

template<class key_type, class value_type, class key_compare>
    class rb_tree {
        private:
			typedef struct s_node 
			{
					s_node								*address;
					ft::pair<key_type, value_type>		data;
					struct s_node						*parent;
					struct s_node						*left;
					struct s_node						*right;
					bool								color; 
			}               t_node;
			
            t_node  				*_root;
			key_compare				_comp;
			std::allocator<t_node>	_alloc;

        public:

		/** CONSTRUCTORS **/
			rb_tree(const std::allocator<t_node>& alloc = std::allocator<t_node>()) : _alloc(alloc) {
				_root = NULL;
			}

            rb_tree(ft::pair<key_type, value_type> *element, const std::allocator<t_node>& alloc = std::allocator<t_node>()) : _alloc(alloc) {
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

			void	free_nodes(t_node *node) {
				if (node && node->left)
					free_nodes(node->left);
				if (node && node->right)
					free_nodes(node->right);
				if (node)
					_alloc.deallocate(node->address, 1);

			}

		/** TOOLS **/

		t_node *minimum(t_node *node) {
			while (node->left != NULL) {
				node = node->left;
			}
			return (node);
		}

		void rbTransplant(t_node *u, t_node *v) {
			if (u->parent == NULL)
				_root = v;
			else if (u == u->parent->left)
				u->parent->left = v;
			else
				u->parent->right = v;
			if (v)
				v->parent = u->parent;
		}

		void leftRotate(t_node *x) {
			t_node *y = x->right;
			
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

		void rightRotate(t_node *x) {
			t_node *y = x->left;
		
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
			t_node *node = _alloc.allocate(1);
		
			node->address = node;
			node->parent = NULL;
			node->data = key;
			node->left = NULL;
			node->right = NULL;
			node->color = 1;

			if (!_root) {
				_root = node;
				return;
			}

			t_node *y = NULL;
			t_node *x = this->_root;

			while (x != NULL) {
				y = x;
				if (node->data < x->data)
					x = x->left;
				else
					x = x->right;
			}

			node->parent = y;
			if (y == NULL)
				_root = node;
			else if (node->data < y->data)
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

		void insertFix(t_node *k) {
			t_node *u;
			
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

		void deleteNodeHelper(t_node *node, ft::pair<key_type, value_type> key) {
			t_node *z = NULL;
			t_node *x, *y;
			while (node != NULL) {
				if (node->data == key)
					z = node;
				if (node->data <= key)
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
			_alloc.deallocate(z->address, 1);
			if (y_original_color == 0)
				deleteFix(x);
		}

		void deleteFix(t_node *x) {
			t_node *s;
			
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

		/** MEMBER FUNCTIONS **/
			size_t	size(t_node *node) {
				if (!node)
					return (0);
				else
					return (size(node->left) + 1 + size(node->right));
			}

			size_t size_tree() {
				return (size(_root));
			}

			void print_tree_helper(t_node *n, int indent)
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
					std::cout << "\033[1;30m(" << n->data << ")\033[0m\n";
				else
					std::cout << "\033[1;31m(" << n->data << ")\033[0m\n";

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