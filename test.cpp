#include <vector>
#include <string>
#include <map>
#include <iomanip>
#include <iostream>
#include "containers/vector.hpp"
#include "utils/pair.hpp"
#include "containers/map.hpp"
#include "containers_test/srcs/base.hpp"


template<typename _Tp>
    class lolocator : public std::allocator<_Tp>
    {
   public:
      typedef size_t     size_type;
      typedef ptrdiff_t  difference_type;
      typedef _Tp*       pointer;
      typedef const _Tp* const_pointer;
      typedef _Tp&       reference;
      typedef const _Tp& const_reference;
      typedef _Tp        value_type;
      template<typename _Tp1>
        struct rebind
        { typedef lolocator<_Tp1> other; };
      
      lolocator() throw() { }
      lolocator(const lolocator& __a) throw() : std::allocator<_Tp>(__a) { }
      template <class _U>
      lolocator (const lolocator<_U>& __a) throw() : std::allocator<_Tp>(std::allocator<_U>(__a)) {}
      ~lolocator() throw() { }

        pointer allocate (size_type n, std::allocator<void>::const_pointer hint=0)
        {
            throw (lolexception());
            n++;
            hint = NULL;
            return NULL;
        }

        class lolexception : public std::exception
        {
            public:
            lolexception() {};
            const char* what() const throw()
            {
                return "lolocator";
            }
        };
    };

int main() {
	ft::map<int,std::string>	tab;
	tab.insert(ft::make_pair(0,"HELLO"));
	tab.insert(ft::make_pair(1,"HELLO"));

	ft::map<int,std::string,std::less<int>, lolocator<ft::pair<int, std::string> > > tab2(tab.begin(), tab.end(), std::less<int>(), lolocator<ft::pair<int, std::string> >());

}