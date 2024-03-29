#ifndef NODE_HPP
# define NODE_HPP
# define BLACK 0
# define RED 1
# define FLOATING_END 2
# define FLOATING_BEG 3
# define EMPTY 4

namespace ft {

template <typename key_type, typename mapped_type, typename value_type, typename key_compare>
	struct s_node 
	{
			s_node								*address;
			value_type							*data;
			int 								color;
			struct s_node						*parent;
			struct s_node						*left;
			struct s_node						*right;
			key_compare							comp;

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
				while (tmp && (!comp(tmp->data->first, data->first) || tmp->data->first == data->first)) {	
					if (tmp == getFirst())
						break ;
					if (tmp->left && tmp->left->right && comp(tmp->left->right->data->first, data->first)) {
						tmp = tmp->left->right;
						while (tmp->right && comp(tmp->right->data->first, data->first))
							tmp = tmp->right; 
						return (tmp);
					}
					if (tmp->left && tmp->left != address && comp(tmp->left->data->first, data->first))
						return (tmp->left);
					tmp = tmp->parent;
				}
				if (tmp && (comp(tmp->data->first, data->first)))
					return (tmp);
				return (getLast()->parent);
            }

            s_node    *increment() const {
				s_node	*tmp = address;

				if (tmp->right && tmp->right->color == FLOATING_END)
					return (tmp->right);
				if (tmp->color == FLOATING_BEG)
					return (tmp->parent);
				while (tmp && (comp(tmp->data->first, data->first) || tmp->data->first == data->first)) {	
					if (tmp == getLast())
						break ;		
					if (tmp->right && tmp->right->left && !comp(tmp->right->left->data->first, data->first)) {
						tmp = tmp->right->left;
						while (tmp->left && !comp(tmp->left->data->first, data->first))
							tmp = tmp->left; 
						return (tmp);
					}
					if (tmp->right && tmp->right != address && !comp(tmp->right->data->first, data->first))
						return (tmp->right);
					tmp = tmp->parent;
				}
				if (tmp && (!comp(tmp->data->first, data->first)))
					return (tmp);
				return (getFirst()->parent);
            }
	};
}

#endif