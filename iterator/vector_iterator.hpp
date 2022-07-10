#ifndef VECTR_ITERATOR_HPP
# define VECTR_ITERATOR_HPP

namespace ft {

template<typename Iterator, typename Container>
	class normal_iterator {

		protected:
			Iterator	_current;
			typedef iterator_traits<Iterator>        traits_type;

		public:
			typedef Iterator									iterator_type;
			typedef typename traits_type::iterator_category		iterator_category;
			typedef typename traits_type::value_type			value_type;
			typedef typename traits_type::difference_type		difference_type;
			typedef typename traits_type::reference				reference;
			typedef typename traits_type::pointer				pointer;

		/** CONSTRUTORS **/
			explicit normal_iterator(const Iterator& i) : _current(i) { }
			template<typename Iter>
				normal_iterator(const normal_iterator<Iter,
					typename enable_if<
					(std::are_same<Iter, typename Container::pointer>::value),
					_Container>::type>& i)
				: _current(i.base()) { }
		
		/** OPERATORS **/
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
	}


}

#endif