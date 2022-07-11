#ifndef ITERATOR_BASE_HPP
# define ITERATOR_BASE_HPP

namespace ft {

template <class Category, class T, class Distance = std::ptrdiff_t,
          class Pointer = T*, class Reference = T&>
  class iterator {
    public:
		typedef Category  iterator_category;
		typedef T         value_type;
		typedef Distance  difference_type;
		typedef Pointer   pointer;
		typedef Reference reference;
  };

}
#endif