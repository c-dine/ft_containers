#ifndef NODE_HPP
# define NODE_HPP
# define BLACK 0
# define RED 1
# define FLOATING_END 2
# define FLOATING_BEG 3
# define EMPTY 4

namespace ft {

template <typename key_type, typename value_type, typename key_compare>
	struct s_node 
	{
			s_node								*address;
			ft::pair<key_type, value_type>		*data;
			struct s_node						*parent;
			struct s_node						*left;
			struct s_node						*right;
			int 								color;
			key_compare						comp;

			s_node	*getRoot() const {
				s_node	*tmp = address;
				while (tmp->parent)
					tmp = tmp->parent;
				return (tmp);
			}

			s_node	*getFirst() const {
				s_node	*tmp = getRoot();
				while (tmp->left)
					tmp = tmp->left;
				return (tmp);
			}

			s_node	*getLast() const {
				s_node	*tmp = getRoot();
				while (tmp->right)
					tmp = tmp->right;
				return (tmp);
			}

            s_node    *decrement() const {
				s_node	*tmp = address;

				if (tmp->left && tmp->left->color == FLOATING_BEG)
					return (tmp->left);
				if (tmp->color == FLOATING_END)
					return (tmp->parent);
				while (tmp && tmp->data->first >= data->first) {	
					if (tmp == getFirst())
						break ;				
					if (tmp->left && tmp->left->right && tmp->left->right->data->first < data->first) {
						tmp = tmp->left->right;
						while (tmp->right && tmp->right->data->first < data->first)
							tmp = tmp->right; 
						return (tmp);
					}
					if (tmp->left && tmp->left != address && tmp->left->data->first < data->first)
						return (tmp->left);
					tmp = tmp->parent;
				}
				if (tmp && (tmp->data->first < data->first))
					return (tmp);
				return (NULL);
            }

            s_node    *increment() const {
				s_node	*tmp = address;

				if (tmp->right && tmp->right->color == FLOATING_END)
					return (tmp->right);
				if (tmp->color == FLOATING_BEG)
					return (tmp->parent);
				while (tmp && tmp->data->first <= data->first) {	
					if (tmp == getLast())
						break ;				
					if (tmp->right && tmp->right->left && tmp->right->left->data->first > data->first) {
						tmp = tmp->right->left;
						while (tmp->left && tmp->left->data->first > data->first)
							tmp = tmp->left; 
						return (tmp);
					}
					if (tmp->right && tmp->right != address && tmp->right->data->first > data->first)
						return (tmp->right);
					tmp = tmp->parent;
				}
				if (tmp && (tmp->data->first > data->first))
					return (tmp);
				return (NULL);
            }
	};
}

#endif