/**
 * @file include/corelib/math.hpp
 * @brief All mathematical functions
 *
 * @author Luis Victoria
 */

#include <concepts>
#include <stdexcept>

template<std::integral T>
T factorial(T n) {
    if (n < 0) {
        throw std::invalid_argument("factorial() isn't defined for negative integers");
    }

    T result = 1;

    for (T i = n; i > 0; --i) {
        result *= i;
    }

    return result;
}
