#ifndef RB_TREE_HPP
# define RB_TREE_HPP

# include "pair.hpp"


namespace ft {

template<class T1, class T2>
    class rb_tree {
        private:
            typedef struct s_node {
                    ft::pair<T1, T2>    data;
                    t_node              *parent;
                    t_node              *left;
                    t_node              *right;
                    int                 color; // 1: red 0: black
            }               t_node;

            t_node  *_root;
        public:
            rb_tree() {
                _root = new t_node;
                _root.data
            }
    };

}

#endif