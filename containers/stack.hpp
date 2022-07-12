#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft {

template<typename T, typename Container = ft::vector<T> >
	class stack
	{
		public:
			typedef typename Container::value_type				Container_value_type;
			typedef typename Container::value_type				value_type;
			typedef typename Container::reference				reference;
			typedef typename Container::const_reference			const_reference;
			typedef typename Container::size_type				size_type;
			typedef          Container							container_type;

		template<typename T_, typename Container_>
		  friend bool
		  operator==(const stack<T_, Container_>&, const stack<T_, Container_>&);

		template<typename T_, typename Container_>
		  friend bool
		  operator<(const stack<T_, Container_>&, const stack<T_, Container_>&);

		protected:
			Container	_c;

		public:
		/** CONSTRUCTORS **/
			explicit	stack(const container_type& ctnr = container_type()) : _c(ctnr) {}

		/** MEMBER FUNCTIONS **/
			bool	empty() const {
				return (_c.empty());
			}

			size_type	size() const {
				return (_c.size());
			}

			reference	top() {
				return (_c.back());
			}

			const_reference	top() const {
				return (_c.back());
			}

			void push (const value_type& val) {
				_c.push_back(val);
			}

			void	pop() {
				_c.pop_back();
			}
};
/** COMPARISON OPERATOR **/
	template<typename T, typename Container>
		inline bool
		operator==(const stack<T, Container>& left, const stack<T, Container>& right)
		{ return left._c == right._c; }

	template<typename T, typename Container>
		inline bool
		operator<(const stack<T, Container>& left, const stack<T, Container>& right)
		{ return left._c < right._c; }

	template<typename T, typename Container>
		inline bool
		operator!=(const stack<T, Container>& left, const stack<T, Container>& right)
		{ return !(left == right); }

	template<typename T, typename Container>
		inline bool
		operator>(const stack<T, Container>& left, const stack<T, Container>& right)
		{ return right < left; }

	template<typename T, typename Container>
		inline bool
		operator<=(const stack<T, Container>& left, const stack<T, Container>& right)
		{ return !(right < left); }

	template<typename T, typename Container>
		inline bool
		operator>=(const stack<T, Container>& left, const stack<T, Container>& right)
		{ return !(left < right); }

}

#endif