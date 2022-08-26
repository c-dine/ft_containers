#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include "iterator_traits.hpp"
# include "iterator_base.hpp"
# include "reverse_iterator.hpp"


namespace ft {

	template<typename T>
		class normal_iterator {
			
			protected:
				typedef	ft::iterator_traits<T*>	traits_type;

			public:
				typedef T											iterator_type;
				typedef typename traits_type::iterator_category		iterator_category;
				typedef typename traits_type::value_type			value_type;
				typedef typename traits_type::difference_type		difference_type;
				typedef typename traits_type::reference				reference;
				typedef typename traits_type::pointer				pointer;

			protected:
				pointer	_current;

			public:
			
			/*****************/
			/** CONSTRUTORS **/
			/*****************/
				
				normal_iterator( void ) : _current(0) {}
				normal_iterator(pointer	p) : _current(p) {}
				normal_iterator(const normal_iterator &copy) : _current(copy._current) {}
				template<typename _Iter>
					normal_iterator(const normal_iterator<_Iter> &copy) : _current(copy.base()) {}
				~normal_iterator( void ) {}
			

			/***************/
			/** OPERATORS **/
			/***************/
			
				reference	operator*() const {
					return (*_current);
				}
				
				pointer	operator->() const {
					return (_current);
				}

				normal_iterator& operator++() {
					++_current;
					return (*this);
				}

				normal_iterator operator++(int) {
					return (normal_iterator(_current++));
				}

				normal_iterator& operator--() {
					--_current;
					return (*this);
				}

				normal_iterator operator--(int) {
					return (normal_iterator(_current--));
				}

				reference operator[](const difference_type& n) const {
					return (_current[n]);
				}

				normal_iterator& operator+=(const difference_type& n) {
					_current += n; 
					return (*this);
				}

				normal_iterator operator+(const difference_type& n) const {
					return (normal_iterator(_current + n));
				}

				normal_iterator& operator-=(const difference_type& n) {
					_current -= n; 
					return (*this);
				}

				normal_iterator operator-(const difference_type& n) const {
					return (normal_iterator(_current - n));
				}

				pointer	base() const {
					return (_current);
				}

				operator normal_iterator<const T> () const {
					return (normal_iterator<const T>(this->_current)); 
				}
	};
	template<typename It_left, typename It_right>
		inline bool	operator==(const normal_iterator<It_left>& lhs,
							const normal_iterator<It_right>& rhs)
		{ return (lhs.base() == rhs.base()); }

	template<typename _Iterator>
		inline bool	operator==(const normal_iterator<_Iterator>& lhs,
							const normal_iterator<_Iterator>& rhs)
		{ return (lhs.base() == rhs.base()); }

	template<typename It_left, typename It_right>
		inline bool	operator!=(const normal_iterator<It_left>& lhs,
							const normal_iterator<It_right>& rhs)
		{ return (lhs.base() != rhs.base()); }

	template<typename _Iterator>
		inline bool	operator!=(const normal_iterator<_Iterator>& lhs,
							const normal_iterator<_Iterator>& rhs)
		{ return (lhs.base() != rhs.base()); }

	template<typename It_left, typename It_right>
		inline bool	operator<(const normal_iterator<It_left>& lhs,
							const normal_iterator<It_right>& rhs)
		{ return (lhs.base() < rhs.base()); }

	template<typename _Iterator>
		inline bool	operator<(const normal_iterator<_Iterator>& lhs,
							const normal_iterator<_Iterator>& rhs)
		{ return (lhs.base() < rhs.base()); }

	template<typename It_left, typename It_right>
		inline bool	operator>(const normal_iterator<It_left>& lhs,
							const normal_iterator<It_right>& rhs)
		{ return (lhs.base() > rhs.base()); }

	template<typename _Iterator>
		inline bool	operator>(const normal_iterator<_Iterator>& lhs,
							const normal_iterator<_Iterator>& rhs)
		{ return (lhs.base() > rhs.base()); }

	template<typename It_left, typename It_right>
		inline bool	operator<=(const normal_iterator<It_left>& lhs,
							const normal_iterator<It_right>& rhs)
		{ return (lhs.base() <= rhs.base()); }

	template<typename _Iterator>
		inline bool	operator<=(const normal_iterator<_Iterator>& lhs,
							const normal_iterator<_Iterator>& rhs)
		{ return (lhs.base() <= rhs.base()); }

	template<typename It_left, typename It_right>
		inline bool	operator>=(const normal_iterator<It_left>& lhs,
							const normal_iterator<It_right>& rhs)
		{ return (lhs.base() >= rhs.base()); }

	template<typename _Iterator>
		inline bool	operator>=(const normal_iterator<_Iterator>& lhs,
							const normal_iterator<_Iterator>& rhs)
		{ return (lhs.base() >= rhs.base()); }

	template<typename It_left, typename It_right>
		inline typename normal_iterator<It_left>::difference_type
			operator-(const normal_iterator<It_left>& lhs,
			const normal_iterator<It_right>& rhs)
		{ return (lhs.base() - rhs.base()); }

	template<typename _Iterator>
		inline typename normal_iterator<_Iterator>::difference_type
			operator-(const normal_iterator<_Iterator>& lhs,
			const normal_iterator<_Iterator>& rhs)
	{ return (lhs.base() - rhs.base()); }

	template<typename _Iterator>
		inline normal_iterator<_Iterator>
			operator+(typename normal_iterator<_Iterator>::difference_type
			n, const normal_iterator<_Iterator>& i)
	{ return (normal_iterator<_Iterator>(i.base() + n)); }

}

#endif