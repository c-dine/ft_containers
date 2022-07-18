#ifndef RB_TREE_HPP
# define RB_TREE_HPP

# include "pair.hpp"
# include "stdlib.h"
# include <stdio.h>
# define RED 1
# define BLACK 0

namespace ft {

template<class key_type, class value_type, class Compare>
    class rb_tree {
        private:
			typedef struct s_node 
			{
					ft::pair<key_type, value_type>		data;
					struct s_node						*parent;
					struct s_node						*left;
					struct s_node						*right;
					bool								color; 
			}               t_node;
			
            t_node  *_root;
			Compare	_comp;

		/** FIX OPERATIONS **/

			void	left_rotate(t_node *x_node) {
				if (x_node->right) {
					t_node	*y_node = x_node->right;
					if (y_node->left) {
						y_node->left->parent = x_node;
						x_node->right = y_node->left;
					}

					if (x_node->parent == NULL)
						_root = y_node;
					else if (x_node == x_node->parent->left)
						x_node->parent->left = y_node;
					else
						x_node->parent->right = y_node;
					x_node->parent = y_node;
					y_node->left = x_node;
				}
			}

			// A CORRIGER ?
			void	right_rotate(t_node *y_node) {
				if (y_node->left) {
					t_node	*x_node = y_node->left;
					if (x_node->right)
						x_node->right->parent = y_node;
					
					if (y_node->parent == NULL)
						_root = x_node;
					else if (y_node == y_node->parent->right)
						y_node->parent->right = x_node;
					else
						y_node->parent->left = x_node;
					y_node->parent = x_node;
				}
			}

			void	left_right_rotate(t_node *x_node) {
				left_rotate(x_node);
				right_rotate(x_node->parent->parent);
			}

			void	right_left_rotate(t_node *x_node) {
				right_rotate(x_node);
				left_rotate(x_node->parent->parent);
			}

			// transplant x with y
			void	transplant(t_node *x, t_node *y) {
				y->parent = x->parent;
				if (x == x->parent->left)
					x->parent->left = y;
				else
					x->parent->right = y;
				x->parent = NULL;
			}

			void	insert_fix(t_node *new_node) {
				while (new_node->parent->color == RED) {
					t_node	*p = new_node->parent;
					t_node	*gp = p->parent;

					if (p == gp->left && gp->right) {
						if (gp->right->color == RED) {
							gp->left->color = BLACK;
							gp->right->color = BLACK;
							gp->color = RED;
							new_node = gp;
						}
						else if (new_node == p->right) {
							new_node = p;
							left_rotate(new_node);
						}
						else {
							p->color = BLACK;
							gp->color = RED;
							right_rotate(gp);
						}
					}
					else if (gp->left){
						if (gp->left->color == RED) {
							gp->left->color = BLACK;
							gp->right->color = BLACK;
							gp->color = RED;
							new_node = gp;
						}
						else if (new_node == p->left) {
							new_node = p;
							right_rotate(new_node);
						}
						else {
							p->color = BLACK;
							gp->color = RED;
							left_rotate(gp);
						}
					}
					// else if (gp->right)
					// 	left_rotate(new_node->parent);
					// else
					// 	right_rotate(new_node->parent);
					if (new_node == _root)
						break ;
				}
				_root->color = BLACK;
			}

			void	delete_fix(t_node *x) {
				t_node	*w;

				while (x != _root && x->color == BLACK) {
					if (x == x->parent->left) {
						w = x->parent->right;

						if (w->color == RED) {
							x->parent->right->color = BLACK;
							x->parent->color = RED;
							left_rotate(x->parent);
							w = x->parent->right;	
						}
						else if (w->left->color == BLACK && w->right->color == BLACK) {
							w->color = RED;
							x = x->parent;
						}
						else if (w->right == BLACK) {
							w->left = BLACK;
							x->color = RED;
							right_rotate(w);
							w = x->parent->right;
						}
						else {
							w->color = x->parent->color;
							x->parent->parent->color = BLACK;
							w->right = BLACK;
							left_rotate(x->parent);
							_root = x;
						}
					}
					else {
						w = x->parent->left;

						if (w->color == RED) {
							x->parent->left->color = BLACK;
							x->parent->color = RED;
							right_rotate(x->parent);
							w = x->parent->left;	
						}
						else if (w->right->color == BLACK && w->left->color == BLACK) {
							w->color = RED;
							x = x->parent;
						}
						else if (w->left == BLACK) {
							w->right = BLACK;
							x->color = RED;
							left_rotate(w);
							w = x->parent->left;
						}
						else {
							w->color = x->parent->color;
							x->parent->parent->color = BLACK;
							w->left = BLACK;
							right_rotate(x->parent);
							_root = x;
						}
					}
					x->color = BLACK;
				}
			}

        public:

		/** CONSTRUCTORS **/
			rb_tree(/*  Compare comp  */) {
				_root = NULL;
				// _comp = comp;
			}

            rb_tree(ft::pair<key_type, value_type> element/* , Compare comp */) {
                _root = new t_node;
                _root->data = element;
				_root->parent = NULL;
				_root->left = NULL;
				_root->right = NULL;
				_root->color = BLACK;
				// _comp = comp;
            }

		/** OPERATION ALGORITHMS **/

			void	insert_node(ft::pair<key_type, value_type> element) {
				t_node	*new_node = new t_node;
	
				if (_root == NULL) {
					new_node->color = BLACK;
					new_node->data = element;
					new_node->parent = NULL;
					new_node->left = NULL;
					new_node->right = NULL;
				}
				else {
					t_node	*tmp = _root;
					t_node	*tmp_parent;
					while (tmp) {
						tmp_parent = tmp;
						if (element > tmp->data)
							tmp = tmp->right;
						else
							tmp = tmp->left;
					}
					new_node->data = element;
					new_node->parent = tmp_parent;
					new_node->left = NULL;
					new_node->right = NULL;
					new_node->color = RED;
					if (element > tmp_parent->data)
						tmp_parent->right = new_node;
					else
						tmp_parent->left = new_node;

					left_rotate(new_node->parent);
					insert_fix(new_node);
				}
				// std::cout << "New element (" << new_node->data << "): parent-> " << new_node->parent->data;
				// if (!new_node->parent)
				// 	std::cout << std::endl;
				// else if (new_node->parent->left == new_node)
				// 	std::cout << " LEFT\n";
				// else
				// 	std::cout << " RIGHT\n";
			}

			void	delete_node(t_node node) {
				bool	originalColor = node->color;
				t_node	*x;
				t_node	*y;

				if (!node->left) {
					x = node->right;
					transplant(node, x);
				}
				else if (!node->right) {
					x = node->left;
					transplant(node, x);
				}
				else {
					y = node->right;
					while (y->left)
						y = y->left;
					originalColor = y->color;
					x = y->right;
					if (y == node->left || y == node->right)
						x->parent = y;
					else
						transplant(y, y->right);
					y->color = originalColor;
				}
				if (originalColor == BLACK)
					delete_fix(x);
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