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

            void    decrement() {
                if (address && address->left)
                    address = address->left;
                if (address->parent && address->parent->left == address && address->parent->parent && address->parent == address->parent->parent->right)
                    address = address->parent->parent;
                if (address->parent && address->parent->right == address)
                    address = address->parent;
            }

            void    increment() {
                if (address && address->right)
                    address = address->right;
                if (address->parent && address->parent->right == address && address->parent->parent && address->parent == address->parent->parent->left)
                    address = address->parent->parent;
                if (address->parent && address->parent->left == address)
                    address = address->parent;
            }
	};

}

#endif