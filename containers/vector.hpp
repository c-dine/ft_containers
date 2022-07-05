#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include "../utils/enable_if.hpp"
# include "../utils/is_integral.hpp"
# include <string>
# include <iostream>

namespace ft {

template < class T, class Alloc = std::allocator<T> >
	class vector
{
	public:
		typedef T											value_type;
		typedef Alloc										allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;

		typedef __gnu_cxx::__normal_iterator<pointer, vector>		iterator;
		typedef __gnu_cxx::__normal_iterator<const_pointer, vector>	const_iterator;
		typedef std::reverse_iterator<iterator>						reverse_iterator;
		typedef std::reverse_iterator<const_iterator>				const_reverse_iterator;
		typedef std::ptrdiff_t											difference_type;
		typedef std::size_t												size_type;


	protected:
		allocator_type	_alloc;
		pointer			_start;
		pointer 		_finish;
		pointer 		_end_of_storage;


	public:

	/** CONSTRUCTOR**/
		explicit vector (const allocator_type& alloc = allocator_type()) :
			_alloc(alloc),
			_start(0),
			_finish(0),
			_end_of_storage(0)
		{}

		explicit vector (size_type n, const value_type& val = value_type(),
		                 const allocator_type& alloc = allocator_type()) :
			_alloc(alloc),
			_start(0),
			_finish(0),
			_end_of_storage(0)
		{
			_start = _alloc.allocate(n);
			_finish = _start;
			for (size_type i = 0; i < n; i++)
			{
				_alloc.construct(_finish, val);
				if (i < n - 1)
					_finish++;
			}
			_end_of_storage = _finish;
		}

		template <class InputIterator>
		         vector (InputIterator first, InputIterator last,
		                 const allocator_type& alloc = allocator_type(),
						 typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0) :
			_alloc(alloc),
			_start(0),
			_finish(0),
			_end_of_storage(0)
		{
			_start = _alloc.allocate(last - first);
			_finish = _start;
			for (InputIterator it = first; it != last; it++)
			{
				alloc.construct(_finish, *it);
				if (it < last - 1)
					_finish++;
			}
			_end_of_storage = _finish;
		}

		vector (const vector& x) {
			if (this != &x)
			{
				_start = 0;
				*this = x;
			}
		}

		/** DESTRUCTOR **/

		private:
			void	clear(void) {
				pointer	tmp = _start;
				for (size_type i = 0; i < size(); i++) {
					_alloc.destroy(_start);
					_start++;
				}
				_alloc.deallocate(tmp, capacity());
			}

		public:
		~vector() {
			clear();
		}

		
		/** OPERATOR **/

		reference operator[] (size_type n) {
			return (*(_start + n));
		}

		const reference operator[] (size_type n) const {
			return (*(_start + n));
		}

		vector& operator= (const vector& x) {
			if (this != &x) {
				if (_start)
					clear();
				_start = _alloc.allocate(x.size());
				_finish = _start;
				for (size_type i = 0; i < x.size(); i++)
				{
					_alloc.construct(_finish, x[i]);
					if (i < x.size() - 1)
						_finish++;
				}
				_end_of_storage = _finish;
			}
			return (*this);
		}

		
		/** CAPACITY **/

		size_type size() const {
			return (_finish - _start + 1);
		}

		size_type max_size() const {
			return (_alloc.max_size());
		}

		void resize (size_type n, value_type val = value_type()) {
			if (n < size())
			{
				pointer	tmp = _start + n;
				for (size_type i = n; i < size(); i++)
				{
					_alloc.destroy(tmp);
					tmp++;
				}
				_finish = _start + n - 1;
			}
			if (n > capacity())
			{
				allocator_type	new_alloc;
				size_type		coeff_alloc;
				size_type		new_storage;
				pointer			new_start;
				pointer			new_finish;

				coeff_alloc = 2;
				while (n > coeff_alloc * capacity())
					coeff_alloc++;
				
				new_start = new_alloc.allocate(coeff_alloc * capacity());
				new_storage = coeff_alloc * capacity();
				new_finish = new_start;
				for (size_type i = 0; i < size(); i++){
					new_alloc.construct(new_finish, _start[i]);
					if (i < size() - 1)
						new_finish++;
				}
				clear();
				_alloc = new_alloc;
				_start = new_start;
				_finish = new_finish;
				_end_of_storage = _finish + new_storage;
			}
			if (n > size())
			{
				for (size_type i = 0; i < n - size(); i++) {
					_alloc.construct(_finish + i + 1, val);
				}
				_finish = _start + n - 1;
			}
		}

		size_type capacity() const {
			return (_end_of_storage - _start + 1);
		}

		bool empty() const {
			return (_start == 0 ? true : false);
		}

		void reserve (size_type n) {
			
		}
};


}
#endif