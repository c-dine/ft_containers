#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>

namespace ft {

template < class T, class Alloc = std::allocator<T> >
	class vector
{
	private:
		typedef Alloc	_allocator_type;
		pointer	_start;
		pointer _finish;
		pointer _end_of_storage;

	public:
		typedef T											value_type;
		typedef Alloc										allocator_type;
		typedef typename _allocator_type::reference			reference;
		typedef typename _allocator_type::const_reference	const_reference;
		typedef typename _allocator_type::pointer			pointer;
		typedef typename _allocator_type::const_pointer		const_pointer;

		typedef __gnu_cxx::__normal_iterator<pointer, vector>		iterator;
		typedef __gnu_cxx::__normal_iterator<const_pointer, vector>	const_iterator;
		typedef std::reverse_iterator<iterator>						reverse_iterator;
		typedef std::reverse_iterator<const_iterator>				const_reverse_iterator;
		typedef ptrdiff_t											difference_type;
		typedef size_t												size_type;

	/** CONSTRUCTOR/DESTRUCTORS **/
		explicit vector (const allocator_type& alloc = allocator_type()) :
			_allocator_type(alloc),
			_start(0),
			_finish(0),
			_end_of_storage(0)
		{}

		explicit vector (size_type n, const value_type& val = value_type(),
		                 const allocator_type& alloc = allocator_type()) :
			_allocator_type(alloc),
			_start(0),
			_finish(0),
			_end_of_storage(0)
		{
			this->_start = 
		}

		template <class InputIterator>
		         vector (InputIterator first, InputIterator last,
		                 const allocator_type& alloc = allocator_type());
		vector (const vector& x);
}


}
#endif