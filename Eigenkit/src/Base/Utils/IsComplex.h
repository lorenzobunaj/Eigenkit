#include <complex>

namespace ek
{
    template<typename T>
    struct is_complex_t : public std::false_type {};

    template<typename T>
    struct is_complex_t<std::complex<T>> : public std::true_type {};

    template<typename T>
    constexpr bool isComplex() 
    { 
        return is_complex_t<T>::value;
    }
}