#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

namespace ft {

// remove const
template<typename>
struct remove_cv;

// struct de base qui contient valeurs
template<typename _Tp, bool _Val>
	struct integral_constant
	{
		static constexpr _Tp					value = _Val;
		typedef _Tp								value_type;
	};

// template par defaut (false)
template<typename>
struct is_integral_helper : public integral_constant<bool, false> {};

// template de spe pour chaque type
struct is_integral_helper<bool> : public integral_constant<bool, true> {};
struct is_integral_helper<char> : public integral_constant<char, true> {};
struct is_integral_helper<signed char> : public integral_constant<signed char, true> {};
struct is_integral_helper<unsigned char> : public integral_constant<unsigned char, true> {};
#ifdef _GLIBCXX_USE_WCHAR_T
	struct is_integral_helper<wchar_t> : public integral_constant<wchar_t, true> {};
#endif
struct is_integral_helper<char16_t> : public integral_constant<char16_t, true> {};
struct is_integral_helper<char32_t> : public integral_constant<char32_t, true> {};
struct is_integral_helper<short> : public integral_constant<short, true> {};
struct is_integral_helper<unsigned short> : public integral_constant<unsigned short, true> {};
struct is_integral_helper<int> : public integral_constant<int, true> {};
struct is_integral_helper<unsigned int> : public integral_constant<unsigned int, true> {};
struct is_integral_helper<long> : public integral_constant<long, true> {};
struct is_integral_helper<unsigned long> : public integral_constant<unsigned long, true> {};
struct is_integral_helper<long long> : public integral_constant<long long, true> {};
struct is_integral_helper<unsigned long long> : public integral_constant<unsigned long long, true> {};

// is_integral
template<typename _Tp>
	struct is_integral : public integral_helper<_Tp> {};
	
}

#endif