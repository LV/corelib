/**
 * @file include/corelib/math.hpp
 * @brief All mathematical functions
 *
 * @author Luis Victoria
 */

#include <concepts>
#include <stdexcept>

template<std::integral T>
constexpr T factorial(T n) {
    if (n < 0) {
        throw std::invalid_argument("factorial() isn't defined for negative integers");
    }

    T result = 1;

    for (T i = n; i > 0; --i) {
        result *= i;
    }

    return result;
}


template<std::integral T>
constexpr T permutation(T n, T k) {
    if (n < 0 || k < 0) {
        throw std::invalid_argument("permutation() isn't defined for negative n or k");
    }

    if (k > n) {
        throw std::invalid_argument("k must not be bigger than n when calculating permutation()");
    }

    T result = 1;
    for (T i = n; i > (n - k); --i) {
        result *= i;
    }

    return result;
}
