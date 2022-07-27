#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft {

template<class T1, class T2>
struct pair
{
	typedef T1	first_type;
	typedef T2	second_type;

	T1	_first;
	T2	_second;

	/** CONSTRUCTORS **/
		pair() : _first(0), _second(0) {}
		pair( const T1& x, const T2& y ) : _first(x), _second(y) {}
		template< class U1, class U2 >
			pair( const pair<U1, U2>& p ) : _first(p._first), _second(p._second) {}

	/** OPERATOR **/
		pair& operator=( const pair& other ) {
			_first = other._first;
			_second = other._second;
			return (*this);
		}

};

template< class T1, class T2 >
	ft::pair<T1,T2> make_pair( T1 t, T2 u ) {
		return (pair<T1, T2>(t, u));
	}

template< class T1, class T2 >
	bool operator==( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ) {
		return (lhs._first == rhs._first);
	}

template< class T1, class T2 >
	bool operator!=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ) {
		return (!(lhs == rhs));
	}

template< class T1, class T2 >
	bool operator<( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ) {
		return (lhs._first < rhs._first);
	}

template< class T1, class T2 >
	bool operator>( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ) {
		return (rhs < lhs);
	}

template< class T1, class T2 >
	bool operator<=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ) {
		return (!(rhs < lhs));
	}

template< class T1, class T2 >
	bool operator>=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ) {
		return (!(lhs < rhs));
	}

}

template< class T1, class T2 >
	std::ostream& operator<<(std::ostream& out, const ft::pair<T1, T2>& tmp)
	{
		out << tmp._first;
		return (out);
	}

#endif