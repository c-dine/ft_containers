#ifndef NODE_HPP
# define NODE_HPP

namespace ft {

template <typename key_type, typename value_type>
	struct s_node 
	{
			s_node								*address;
			ft::pair<key_type, value_type>		*data;
			struct s_node						*parent;
			struct s_node						*left;
			struct s_node						*right;
			int 								color;

            s_node    *decrement() const {
                if (address && address->left)
                    return (address->left);
                else if (address->parent && address->parent->left == address && address->parent->parent && address->parent == address->parent->parent->right)
                    return (address->parent->parent);
                else if (address->parent && address->parent->right == address)
                    return (address->parent);
				return (NULL);
            }

            s_node    *increment() const {
                if (address && address->right)
                    return (address->right);
                else if (address->parent && address->parent->right == address && address->parent->parent && address->parent == address->parent->parent->left)
                    return (address->parent->parent);
                else if (address->parent && address->parent->left == address)
                    return (address->parent);
				return (NULL);
            }
	};


// }
//             s_node    *decrement() const {
// 				s_node	*tmp = address;

// 				while (tmp->data->first >= data->first && tmp->color != FLOATING_BEG) {
// 					if (tmp->left && tmp->left != address && tmp->left->right)
// 						return (tmp->left->right);
// 					if (tmp->left && tmp->left != address)
// 						return (tmp->left);
// 					if (tmp->parent)
// 						tmp = tmp->parent;
// 					else
// 						break ;
// 				}
// 				if (tmp->data->first < data->first && tmp->color != FLOATING_BEG)
// 					return (tmp);
// 				return (NULL);
//             }

//             s_node    *increment() const {
// 				s_node	*tmp = address;

// 				while (tmp->data->first <= data->first && tmp->color != FLOATING_END) {
// 					if (tmp->right && tmp->right->left && tmp->right->left != address && tmp->right->left->data->first > data->first)
// 						return (tmp->right->left);
// 					if (tmp->right && tmp->right != address && tmp->right->data->first > data->first)
// 						return (tmp->right);
// 					if (tmp->parent)
// 						tmp = tmp->parent;
// 					else
// 						break ;
// 				}
// 				if (tmp->data->first > data->first && tmp->color != FLOATING_END)
// 					return (tmp);
// 				return (NULL);
//             }
#endif