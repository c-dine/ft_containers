#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator_traits.hpp"
# include "iterator_base.hpp"

namespace ft {

template<typename T>
	class reverse_iterator  /* : public ft::iterator<typename iterator_traits<_Iterator>::iterator_category,
											typename iterator_traits<_Iterator>::value_type,
											typename iterator_traits<_Iterator>::difference_type,
											typename iterator_traits<_Iterator>::pointer,
											typename iterator_traits<_Iterator>::reference> */
{
		protected:
			typedef ft::iterator_traits<T>							traits_type;

		public:
			typedef T											iterator_type;
			typedef typename traits_type::iterator_category		iterator_category;
			typedef typename traits_type::value_type			value_type;
			typedef typename traits_type::difference_type		difference_type;
			typedef typename traits_type::pointer				pointer;
			typedef typename traits_type::reference				reference;

		protected:
			T	_current;

		public:

		/** CONSTRUCTORS **/
		reverse_iterator( void ) : _current(0) {}
		reverse_iterator(const reverse_iterator<pointer> &copy) : _current(copy.base()) {std::cout << "HEEEELP\n";}
		reverse_iterator(const T &copy) : _current(copy) {}
		template<typename _Iter>
			reverse_iterator(const reverse_iterator<_Iter> &copy) : _current(copy.base()) {}
		
		/** MEMBER FUNCTIONS **/
		iterator_type	base() const {
			return (_current);
		}

		/** OPERATOR **/
		reference	operator*() const {
			T tmp = _current;
			return (*--tmp);
		}

		pointer	operator->() const {
			return (&(operator*()));
		}

		reverse_iterator	&operator++() {
			--_current;
			return (*this);
		}

		reverse_iterator	operator++(int) {
			reverse_iterator	tmp = *this;
			--_current;
			return (tmp);
		}

		reverse_iterator	&operator--() {
			++_current;
			return (*this);
		}

		reverse_iterator	operator--(int) {
			reverse_iterator	tmp = *this;
			++_current;
			return (tmp);
		}

		reverse_iterator	operator+(difference_type n) const {
			return (reverse_iterator(_current - n));
		}

		reverse_iterator	&operator+=(difference_type n) {
			_current -= n;
			return (*this);
		}

		reverse_iterator	operator-(difference_type n) const {
			return (reverse_iterator(_current + n));
		}

		reverse_iterator	&operator-=(difference_type n) {
			_current += n;
			return (*this);
		}

		reference	operator[](difference_type n) const {
			return (*(*this + n));
		}

		// operator reverse_iterator<const T> () const {
		// 	return (reverse_iterator<const T>(this->_current)); 
		// }
};

/** COMPARISON OPERATORS **/
	template<typename _Iterator>
		inline bool
		operator==(const reverse_iterator<_Iterator>& left,
				const reverse_iterator<_Iterator>& right)
		{ return left.base() == right.base(); 
		}

	template<typename _Iterator>
		inline bool
		operator<(const reverse_iterator<_Iterator>& left,
				const reverse_iterator<_Iterator>& right)
		{ return right.base() < left.base(); }

	template<typename _Iterator>
		inline bool
		operator!=(const reverse_iterator<_Iterator>& left,
				const reverse_iterator<_Iterator>& right)
		{ return !(left == right); }

	template<typename _Iterator>
		inline bool
		operator>(const reverse_iterator<_Iterator>& left,
				const reverse_iterator<_Iterator>& right)
		{ return right < left; }

	template<typename _Iterator>
		inline bool
		operator<=(const reverse_iterator<_Iterator>& left,
				const reverse_iterator<_Iterator>& right)
		{ return !(right < left); }

	template<typename _Iterator>
		inline bool
		operator>=(const reverse_iterator<_Iterator>& left,
				const reverse_iterator<_Iterator>& right)
		{ return !(left < right); }

	template<typename _Iterator>
		inline typename reverse_iterator<_Iterator>::difference_type
		operator-(const reverse_iterator<_Iterator>& left,
				const reverse_iterator<_Iterator>& right)
		{ return right.base() - left.base(); }

	template<typename _Iterator>
		inline reverse_iterator<_Iterator>
		operator+(typename reverse_iterator<_Iterator>::difference_type n,
				const reverse_iterator<_Iterator>& left)
		{ return reverse_iterator<_Iterator>(left.base() - n); }

	template<typename _IteratorL, typename _IteratorR>
		inline bool
		operator==(const reverse_iterator<_IteratorL>& left,
			const reverse_iterator<_IteratorR>& right)
		{ return left.base() == right.base(); }

	template<typename _IteratorL, typename _IteratorR>
		inline bool
		operator<(const reverse_iterator<_IteratorL>& left,
			const reverse_iterator<_IteratorR>& right)
		{ return right.base() < left.base(); }

	template<typename _IteratorL, typename _IteratorR>
		inline bool
		operator!=(const reverse_iterator<_IteratorL>& left,
			const reverse_iterator<_IteratorR>& right)
		{ return !(left == right); }

	template<typename _IteratorL, typename _IteratorR>
		inline bool
		operator>(const reverse_iterator<_IteratorL>& left,
			const reverse_iterator<_IteratorR>& right)
		{ return right < left; }

	template<typename _IteratorL, typename _IteratorR>
		inline bool
		operator<=(const reverse_iterator<_IteratorL>& left,
			const reverse_iterator<_IteratorR>& right)
		{ return !(right < left); }

	template<typename _IteratorL, typename _IteratorR>
		inline bool
		operator>=(const reverse_iterator<_IteratorL>& left,
			const reverse_iterator<_IteratorR>& right)
		{ return !(left < right); }

	template<typename _IteratorL, typename _IteratorR>
		inline typename reverse_iterator<_IteratorL>::difference_type
		operator-(const reverse_iterator<_IteratorL>& left,
		const reverse_iterator<_IteratorR>& right)
		{ return right.base() - left.base(); }


}

#endif