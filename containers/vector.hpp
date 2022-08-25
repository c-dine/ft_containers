#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include "../utils/equal.hpp"
# include "../utils/lexicographical_compare.hpp"
# include "../utils/enable_if.hpp"
# include "../utils/is_integral.hpp"
# include "../iterator/vector_iterator.hpp"
# include "../iterator/reverse_iterator.hpp"
# include <string>
# include <iostream>
# include <exception>

namespace ft {

template < class T, class Alloc = std::allocator<T> >
	class vector
{
	public:
		typedef T													value_type;
		typedef Alloc												allocator_type;
		typedef typename allocator_type::reference					reference;
		typedef typename allocator_type::const_reference			const_reference;
		typedef typename allocator_type::pointer					pointer;
		typedef typename allocator_type::const_pointer				const_pointer;

		typedef ft::normal_iterator<T>								iterator;
		typedef ft::normal_iterator<const T>						const_iterator;
		typedef ft::reverse_iterator<iterator>						reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;
		typedef std::ptrdiff_t										difference_type;
		typedef std::size_t											size_type;


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
			_start = _alloc.allocate(distance_it(first, last));
			_finish = _start;
			for (InputIterator it = first; it != last; it++)
			{
				_alloc.construct(_finish, *it);
				if (1 < distance_it(it, last))
					_finish++;
			}
			_end_of_storage = _finish;
		}

		vector (const vector& x)  :
			_start(0),
			_finish(0),
			_end_of_storage(0)
		{
			if (this != &x && x.size())
			{
				_start = 0;
				*this = x;
			}
		}

		/** DESTRUCTOR **/
		~vector() {
			if (size())
				clear();
			_alloc.deallocate(_start, capacity());
		}

		
		/** OPERATOR **/

		vector& operator= (const vector& x) {
			if (this != &x) {
				if (_start) {
					clear();
					_alloc.deallocate(_start, capacity());
				}
				_start = _alloc.allocate(x.size());
				_finish = _start;
				for (size_type i = 0; i < x.size(); i++)
				{
					_alloc.construct(_finish, x[i]);
					if (i < x.size() - 1)
						_finish++;
				}
				if (!x.size())
					_finish = 0;
				_end_of_storage = _finish;
			}
			return (*this);
		}

		/** ITERATORS **/
		iterator begin() {
			return (iterator(_start));
		}
		const_iterator begin() const {
			return (const_iterator(_start));
		}

		iterator end() {
			if (size() == 0)
				return (iterator(_start));
			return (iterator(_finish) + 1);
		}
		const_iterator end() const {
			if (size() == 0)
				return (const_iterator(_start));
			return (const_iterator(_finish) + 1);
		}
		reverse_iterator rbegin() {
			return (reverse_iterator(end()));
		}
		const_reverse_iterator rbegin() const {
			return (const_reverse_iterator(end()));
		}
		reverse_iterator rend() {
			return (reverse_iterator(begin()));
		}
		const_reverse_iterator rend() const {
			return (const_reverse_iterator(begin()));
		}

		/** CAPACITY **/

		size_type size() const {
			if (!_finish)
				return (0);
			return (_finish - _start + 1);
		}

		size_type max_size() const {
			return (_alloc.max_size());
		}

	private:
		template <class InputIterator>
			size_type	distance_it(InputIterator first, InputIterator last)
			{
				size_type	distance = 0;

				for (InputIterator it = first; it != last; it++)
					distance++;
				return (distance);
			}
		void	reallocate(size_type n, bool exact_size)
		{
			allocator_type	new_alloc;
			size_type		coeff_alloc;
			size_type		new_storage;
			pointer			new_start;
			pointer			new_finish;

			if (capacity() == 0 && !exact_size)
				new_storage = n;
			else if (!exact_size) {
				coeff_alloc = 2;
				while (n > coeff_alloc * capacity()) 
					coeff_alloc++;
				new_storage = coeff_alloc * capacity();
			}
			if (exact_size)
				new_storage = n;
			new_start = new_alloc.allocate(new_storage);
			new_finish = new_start;
			for (size_type i = 0; i < size(); i++){
				new_alloc.construct(new_finish, _start[i]);
				if (i < size() - 1)
					new_finish++;
			}
			if (size() == 0)
				new_finish = 0;
			clear();
			_finish = new_finish;
			_alloc.deallocate(_start, capacity());
			_alloc = new_alloc;
			_start = new_start;
			_end_of_storage = _start + new_storage - 1;
		}

	public:
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
			if (n >= capacity()) {
				if (capacity() != 0 && n < size() * 2 && size() != 0) 
					reserve(size() * 2);
				else
					reserve(n);
			}
			if (n > size())
			{
				size_t	size_ = size();
				for (size_type i = 0; i < n - size_; i++)
					push_back(val);
			}
		}

		size_type capacity() const {
			if (!_start)
				return (0);
			return (_end_of_storage - _start + 1);
		}

		bool empty() const {
			return (size() == 0 ? true : false);
		}

		void reserve (size_type n) {
			if (n > max_size())
				throw std::length_error("vector::reserve");
			if (n > capacity()) 
				reallocate(n, 1);			
		}

	/** ELEMENT ACCESS **/

		reference operator[] (size_type n) {
			return (*(_start + n));
		}

		const_reference operator[] (size_type n) const {
			return (*(_start + n));
		}

		reference at (size_type n) {
			if (n < 0 || n >= size())
				throw std::out_of_range("vector::at");
			return (*(_start + n));
		}

		const_reference at (size_type n) const {
			if (n < 0 || n >= size())
				throw std::out_of_range("vector::at");
			return (*(_start + n));
		}

    	reference front() {
			return (*(_start));
		}

		const_reference front() const {
			return (*(_start));
		}

    	reference back() {
			return (*(_finish));
		}
		const_reference back() const {
			return (*(_finish));
		}

	/** MODIFIERS **/
		template <class InputIterator>
			void assign (InputIterator first, InputIterator last,
						 typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0) {
				size_type	distance_it_ = distance_it(first, last);

				if (distance_it_ > capacity())
					reallocate(distance_it_, 1);
				
				clear();
				pointer	tmp = _start;
				for (size_type i = 0; i < distance_it_; i++)
					_alloc.construct(tmp++, *(first++));
				_finish = _start + distance_it_ - 1;
			}

		void assign (size_type n, const value_type& val) {
			if (n > capacity())
				reallocate(n, 1);
			clear();
			pointer	tmp = _start;
			for (size_type i = 0; i < n; i++)
				_alloc.construct(tmp++, val);
			_finish = _start + n - 1;
		}

		void push_back (const value_type& val) {
			if (size() + 1 > capacity())
				reallocate(size() + 1, 0);
			if (_finish) {
				_alloc.construct(_finish + 1, val);
				_finish++;
			}
			else {
				_alloc.construct(_start, val);
				_finish = _start;
			}
		}

		void pop_back() {
			_alloc.destroy(_finish);
			if (_finish)
				_finish--;
			else if (size() == 1)
				_finish = 0;
		}

		iterator	insert (iterator position, const value_type& val) {
			if (size() + 1 >  capacity()) {
				size_type	position_iterator = static_cast<size_type>(position - begin()); 
				reserve(size() + 1);
				position = begin() + position_iterator;
			}
			if (size() == 0) {
				_alloc.construct(_start, val);
				_finish = _start;
				return (position);
			}
			pointer	tmp = _finish + 1;
			for (iterator it = iterator(_finish); it != position - 1; it--) {
				if (tmp == _finish + 1)
					_alloc.construct(tmp, *it);
				else
					*tmp = *it;
				tmp--;
			}
			if (position == end())
				_alloc.construct(tmp, *_finish);
			*position = val;
			_finish++;
			return (position);
		}

		void		insert (iterator position, size_type n, const value_type& val) {
			if (size() + n > capacity()) {
				size_type	position_iterator = static_cast<size_type>(position - begin());
				reserve(size() + n);
				position = begin() + position_iterator;
			}
			for (size_type i = 0; i < n; i++)
				insert(position, val);
		}

		template <class InputIterator>
    		void	insert (iterator position, InputIterator first, InputIterator last,
						 typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0) {
				size_type	position_iterator = static_cast<size_type>(position - begin());

				if (size() + distance_it(first, last) > capacity())
					reserve(size() + distance_it(first, last));
				position = begin() + position_iterator;
				InputIterator	tmp = last;
				tmp--;
				for (size_type i = 0; i < distance_it(first, last); i++) {
					insert(position, *tmp);
					tmp--;
				}
		}

		iterator erase (iterator position) {
			for (iterator it = position; it != iterator(_finish); it++)
				*it = *(it + 1);
			_alloc.destroy(_finish);
			if (size() == 1)
				_finish = 0;
			else
				_finish--;
			if (position == iterator(_finish))
				return (iterator(_finish));
			return (position);
		}

		iterator erase (iterator first, iterator last) {
			iterator	tmp = first;
			for (iterator it = last; it != iterator(_finish + 1); it++) {
				*tmp = *it;
				tmp++;
			}
			for (iterator it = tmp; it != iterator(_finish + 1); it++) {
				_alloc.destroy(it.base());
			}
			if (size() == distance_it(first, last))
				_finish = 0;
			else
				_finish -= distance_it(first, last);
			return (first);
		}

		void swap (vector& x) {
			pointer	tmp;

			tmp = x._start;
			x._start = _start;
			_start = tmp;

			tmp = x._finish;
			x._finish = _finish;
			_finish = tmp;

			tmp = x._end_of_storage;
			x._end_of_storage = _end_of_storage;
			_end_of_storage = tmp;
		}

		void	clear() {
			pointer	tmp = _start;

			for (size_type i = 0; i < size(); i++) {
				_alloc.destroy(tmp);
				tmp++;
			}
			_finish = 0;
		}

	/** ALLOCATOR **/
		allocator_type get_allocator() const {
			return (_alloc);
		}
};

template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {
		x.swap(y);
	}

template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (!(lhs == rhs));
	}

template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (!(rhs < lhs));
	}

template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (rhs < lhs);
	}

template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (!(lhs < rhs));
	}
}
#endif