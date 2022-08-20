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

}

#endif