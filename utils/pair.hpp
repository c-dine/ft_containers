#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft {

template<class T1, class T2>
struct pair
{
	
	pair();
	pair( const T1& x, const T2& y );
	template< class U1, class U2 >
		pair( const pair<U1, U2>& p );
	pair( const pair& p ) = default;
		
};
}

#endif