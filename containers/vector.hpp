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
		size_type		_nb_obj;
		size_type		_storage_capacity;


	public:

	/** CONSTRUCTOR**/
		explicit vector (const allocator_type& alloc = allocator_type()) :
			_alloc(alloc),
			_start(0),
			_finish(0),
			_end_of_storage(0),
			_nb_obj(0),
			_storage_capacity(0)
		{}

		explicit vector (size_type n, const value_type& val = value_type(),
		                 const allocator_type& alloc = allocator_type()) :
			_alloc(alloc),
			_start(0),
			_finish(0),
			_end_of_storage(0),
			_nb_obj(n),
			_storage_capacity(n)
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
			_end_of_storage(0),
			_nb_obj(last - first),
			_storage_capacity(last - first)
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
			_nb_obj = 0;
			_storage_capacity = 0;
			if (this != &x)
				*this = x;
		}

		/** DESTRUCTOR **/

		private:
			void	clear(void) {
				for (size_type i = 0; i < _nb_obj; i++) {
					_alloc.destroy(_start);
					_start++;
				}
				// _alloc.deallocate(_start, _storage_capacity);
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
				clear();
				_nb_obj = x._nb_obj;
				_storage_capacity = x._nb_obj;
				_start = _alloc.allocate(x._nb_obj);
				_finish = _start;
				for (size_type i = 0; i < _nb_obj; i++)
				{
					_alloc.construct(_finish, x[i]);
					if (i < _nb_obj - 1)
						_finish++;
				}
				_end_of_storage = _finish;
			}
			return (*this);
		}

		
		/** CAPACITY **/

		size_type size() const {
			return (_nb_obj);
		}

		size_type max_size() const {
			return (_alloc.max_size());
		}

		void resize (size_type n, value_type val = value_type()) {
			if (n < _nb_obj)
			{
				pointer	tmp = _start + n;
				for (size_type i = n; i < _nb_obj; i++)
				{
					_alloc.destroy(tmp);
					tmp++;
				}
				_nb_obj = n;
			}
			if (n > _storage_capacity)
			{
				allocator_type	new_alloc;
				size_type		coeff_alloc;
				pointer			new_start;
				pointer			new_finish;

				coeff_alloc = 2;
				while (n > coeff_alloc * _storage_capacity)
					coeff_alloc++;
				
				new_start = new_alloc.allocate(coeff_alloc * _storage_capacity);
				new_finish = new_start;
				for (size_type i = 0; i < _nb_obj; i++){
					new_alloc.construct(new_finish, _start[i]);
					new_finish++;
				}
				clear();
				_storage_capacity *= coeff_alloc;
				_alloc = new_alloc;
				_start = new_start;
				_finish = new_finish;
				_end_of_storage = _finish + (_storage_capacity - _nb_obj);
			}
			if (n > _nb_obj)
			{
				for (size_type i = 0; i < n - _nb_obj; i++)
					_alloc.construct(_finish + 1 + i, val);
				_nb_obj = n;
			}
		}

		size_type capacity() const {
			return (_storage_capacity);
		}

		bool empty() const {
			return (_nb_obj == 0 ? true : false);
		}

		// void reserve (size_type n) {

		// }
};


}
#endif