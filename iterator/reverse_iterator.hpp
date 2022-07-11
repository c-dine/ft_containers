#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator_traits.hpp"
# include "iterator_base.hpp"

namespace ft {

template<typename T>
	class reverse_iterator /* : public ft::iterator<typename iterator_traits<_Iterator>::iterator_category,
											typename iterator_traits<_Iterator>::value_type,
											typename iterator_traits<_Iterator>::difference_type,
											typename iterator_traits<_Iterator>::pointer,
											typename iterator_traits<_Iterator>::reference> */
{
		protected:
			typedef iterator_traits<T*>							traits_type;

		public:
			typedef T											iterator_type;
			typedef typename traits_type::iterator_category		iterator_category;
			typedef typename traits_type::value_type			value_type;
			typedef typename traits_type::difference_type		difference_type;
			typedef typename traits_type::pointer				pointer;
			typedef typename traits_type::reference				reference;

		protected:
			pointer	_current;

		public:

		/** CONSTRUCTORS **/
		reverse_iterator( void ) _current(0) {}
		reverse_iterator(pointer p) : _current(p) {}
		reverse_iterator(const reverse_iterator &copy) : _current(copy._current) {}
		template<typename _Iter>
			reverse_iterator(const reverse_iterator<_Iter> &copy) : _current(copy.base()) {}
		
};

}

#endif