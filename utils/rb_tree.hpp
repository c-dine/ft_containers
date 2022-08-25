#ifndef RB_TREE_HPP
# define RB_TREE_HPP

# include "node.hpp"
# include "pair.hpp"
# include "stdlib.h"
# include "../iterator/map_iterator.hpp"
# include <memory>
# include <stdio.h>
# define BLACK 0
# define RED 1
# define FLOATING_END 2
# define FLOATING_BEG 3
# define EMPTY 4

namespace ft {

template<
	class key_type,
	class mapped_type, 
	class key_compare,
	class allocator_type
>	class rb_tree {

		public:

			typedef	typename allocator_type::value_type									value_type;
			typedef s_node<key_type, mapped_type, value_type, key_compare>				node_type;

			class value_compare : public std::binary_function<mapped_type, mapped_type, bool> {
				protected:
					key_compare	_comp;
				public:
					value_compare(key_compare c) : _comp(c) {}
					bool operator()(const value_type& x, const value_type& y) const { return (_comp(x.first, y.first)); }
					key_compare	getKey() const { return (_comp); }
			};
			
        private:

			value_compare										_comp;
			allocator_type										_alloc_pair;
			
			typedef typename	allocator_type::template rebind<node_type>::other	allocator_type_node;

            node_type  											*_root;
			allocator_type_node									_alloc;
			node_type											*_floating_beg;
			node_type											*_floating_end;

		public:


		/** CONSTRUCTORS **/
			rb_tree(const allocator_type& alloc = allocator_type(), const key_compare& comp = key_compare()) : _comp(value_compare(comp)), _alloc_pair(alloc) {
				_root = _alloc.allocate(1);
				_root->data = _alloc_pair.allocate(1);
				_alloc_pair.construct(_root->data, value_type());
				_root->address = _root;
				_root->parent = NULL;
				_floating_beg = add_floating_end(FLOATING_BEG);
				_floating_end = add_floating_end(FLOATING_END);
				_root->left = _floating_beg;
				_root->right = _floating_end;
				_root->color = EMPTY;
				_root->comp = _comp.getKey();
			}

            rb_tree(value_type element, const allocator_type& alloc = allocator_type(), const key_compare& comp = key_compare()) : _comp(value_compare(comp)), _alloc_pair(alloc) {
                _root = _alloc.allocate(1);
				_root->data = _alloc_pair.allocate(1);
				_alloc_pair.construct(_root->data, element);
				_root->address = _root;
				_root->parent = NULL;
				_floating_beg = add_floating_end(FLOATING_BEG);
				_floating_end = add_floating_end(FLOATING_END);
				_root->left = _floating_beg;
				_root->right = _floating_end;
				_root->color = BLACK;
				_root->comp = _comp.getKey();
            }

			void swap(rb_tree& x) {
				node_type 			*tmp_root = _root;
				value_compare		tmp_comp = _comp;
				allocator_type		tmp_alloc_pair = _alloc_pair;
				allocator_type_node	tmp_alloc = _alloc;
				node_type			*tmp_floating_beg = _floating_beg;
				node_type			*tmp_floating_end = _floating_end;

				_root = x._root;
				_comp = x._comp;
				_alloc_pair = x._alloc_pair;
				_alloc = x._alloc;
				_floating_beg = x._floating_beg;
				_floating_end = x._floating_end;

				x._root = tmp_root;
				x._comp = tmp_comp;
				x._alloc_pair = tmp_alloc_pair;
				x._alloc = tmp_alloc;
				x._floating_beg = tmp_floating_beg;
				x._floating_end = tmp_floating_end;
			}
			
			~rb_tree() {
				free_nodes(_root);
			}

			void	clear() {
				if (_root->color == EMPTY)
					return ;
				delete_floating();

				free_nodes(_root);
				_root = _alloc.allocate(1);
				_root->data = _alloc_pair.allocate(1);
				_alloc_pair.construct(_root->data, value_type());
				_root->address = _root;
				_root->parent = NULL;
				_root->color = EMPTY;
				_root->left = _floating_beg;
				_root->right = _floating_end;
				_root->comp = _comp.getKey();
			}

			void	free_nodes(node_type *node) {
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

		node_type	*add_floating_end(int which) {
			node_type	*tmp;

			tmp = _alloc.allocate(1);
			tmp->data = _alloc_pair.allocate(1);
			_alloc_pair.construct(tmp->data, value_type());
			if (which == FLOATING_BEG)
				tmp->color = FLOATING_BEG;
			else if (which == FLOATING_END)
				tmp->color = FLOATING_END;
			tmp->address = tmp;
			tmp->parent = _root;
			tmp->left = NULL;
			tmp->right = NULL;
			tmp->comp = _comp.getKey();
			return (tmp);
		}

		void	delete_floating() {
			if (_floating_beg && _floating_end) {
				if (_floating_beg->parent)
					_floating_beg->parent->left = NULL;
				_floating_beg->parent = NULL;
				if (_floating_end->parent)
					_floating_end->parent->right = NULL;
				_floating_end->parent = NULL;
			}
		}

		void	insert_floating() {
			node_type	*tmp_beg = getFirst(false);
			node_type	*tmp_end = getLast(false);

			tmp_beg->left = _floating_beg;
			if (_floating_beg)
				_floating_beg->parent = tmp_beg;
			tmp_end->right = _floating_end;
			if (_floating_end)
				_floating_end->parent = tmp_end;
			_alloc_pair.destroy(_floating_beg->data);
			_alloc_pair.destroy(_floating_end->data);
			_alloc_pair.construct(_floating_beg->data, value_type());
			_alloc_pair.construct(_floating_end->data, value_type());
		}

		/** TOOLS **/

		node_type *minimum(node_type *node) {
			while (node->left != NULL) {
				node = node->left;
			}
			return (node);
		}

		void rbTransplant(node_type *u, node_type *v) {
			if (u->parent == NULL)
				_root = v;
			else if (u == u->parent->left)
				u->parent->left = v;
			else
				u->parent->right = v;
			if (v)
				v->parent = u->parent;
		}

		void leftRotate(node_type *x) {
			node_type *y = x->right;
			
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

		void rightRotate(node_type *x) {
			node_type *y = x->left;
		
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

		node_type *insert(value_type key, value_type *hint) {
			node_type *node = _alloc.allocate(1);
		
			node->data = _alloc_pair.allocate(1);
			_alloc_pair.construct(node->data, key);
			node->address = node;
			node->parent = NULL;
			node->left = NULL;
			node->right = NULL;
			node->color = RED;
			node->comp = _comp.getKey();

			delete_floating();
			if (_root->color == EMPTY) {
				_alloc_pair.destroy(_root->data);
				_alloc_pair.deallocate(_root->data, 1);
				_alloc.deallocate(_root->address, 1);
				_root = node;
				node->color = BLACK;
				return (insert_floating(), _root);
			}

			node_type *y = NULL;
			node_type *x = this->_root;


			while (x != NULL) {
				y = x;
				if (_comp(*node->data, *x->data))
					x = x->left;
				else
					x = x->right;
			}
			if (hint)
				x = findNextKey(hint->first);

			node->parent = y;
			if (y == NULL)
				_root = node;
			else if (_comp(*node->data, *y->data))
				y->left = node;
			else
				y->right = node;

			if (node->parent == NULL) {
				node->color = 0;
				return (insert_floating(), node);
			}

			if (node->parent->parent == NULL)
				return (insert_floating(), node);

			insertFix(node);
			return (insert_floating(), node);
		}

		void insertFix(node_type *k) {
			node_type *u;
			
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
			if (size_tree() == 1 && _root->data->first == data) {
				_root->color = EMPTY;
				_alloc_pair.destroy(_root->data);
				_alloc_pair.construct(_root->data, value_type());
			}
			else
	    		deleteNodeHelper(_root, value_type(data, mapped_type()));
  		}

		void deleteNodeHelper(node_type *node, value_type key) {
			node_type	*z = NULL;
			node_type	*x, *y;

			delete_floating();

			while (node != NULL) {
				if (node->data->first == key.first) 
					z = node;
				if (_comp(*node->data, key) || node->data->first == key.first)
					node = node->right;
				else
					node = node->left;
			}


			if (z == NULL)
				return (insert_floating());

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

				if (x && y->parent == z) {
					x->parent = y;
				}
				else {
					rbTransplant(y, y->right);
					y->right = z->right;
					if (y->right)
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
			
			insert_floating();
		}

		void deleteFix(node_type *x) {
			node_type *s;
			
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
					if (s->right && s->right->color == 0) {
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
		node_type	*search(node_type *node, const key_type &k) const {
			node_type	*tmp;

			if (!node || node->color == FLOATING_BEG || node->color == FLOATING_END)
				return (NULL);
			if (node->data->first == k && node->color != EMPTY)
				return (node);
			tmp = search(node->right, k);
			if (tmp)
				return (tmp);
			return (search(node->left, k));
		}

		node_type	*find_key(const key_type& k) const {
			node_type	*tmp;

			tmp = search(_root, k);
			if (tmp)
				return (tmp);
			return (NULL);
		}

		// finds key or the one after
		node_type	*findNextKey(const key_type& k) const {
			node_type	*tmp = getFirst(true);

			while (tmp && _comp(*tmp->data, ft::make_pair(k,mapped_type())) && tmp->color != FLOATING_END)
				tmp = tmp->increment();
			if (!tmp)
				return (_floating_end);
			return (tmp);
		}

		/** MEMBER FUNCTIONS **/
			size_t	size(node_type *node) const {
				if ((_root && _root->color == EMPTY) || 
						(node && (node->color == FLOATING_BEG || node->color == FLOATING_END)) || 
						!node)
					return (0);
				else
					return (size(node->left) + 1 + size(node->right));
			}

			size_t size_tree() const {
				return (size(_root));
			}


			size_t max_size() const {
				return (_alloc_pair.max_size());
			}

			node_type	*getRoot() const {
				return (_root);
			}

			node_type	*getFloatingEnd(int which) const {
				if (which == FLOATING_BEG)
					return (_floating_beg);
				return (_floating_end);
			}

			node_type	*getLast(bool reversed) const {
				node_type	*tmp = _root;

				while (tmp->right)
					tmp = tmp->right;
				if (reversed && tmp->color == FLOATING_END)
					tmp = tmp->parent;
				return (tmp);
			}

			node_type	*getFirst(bool reversed) const {
				node_type	*tmp = _root;

				while (tmp && tmp->left)
					tmp = tmp->left;
				if (tmp && reversed && tmp->color == FLOATING_BEG)
					tmp = tmp->parent;
				return (tmp);
			}

			value_compare	getValueComp() const {
				return (_comp);
			}

			key_compare	getKeyComp() const {
				return (_comp.getKey());
			}
		
			allocator_type get_allocator() const {
				return (_alloc_pair);
			}

			void print_tree_helper(node_type *n, int indent)
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
				delete_floating();
				print_tree_helper(_root, 4);
				insert_floating();
				std::cout << std::endl << "-----------------------"<< std::endl;
			}

    };

}

#endif