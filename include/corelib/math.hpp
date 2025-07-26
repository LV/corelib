#pragma once

/**
 * @file include/corelib/math.hpp
 * @brief All mathematical functions
 *
 * @author Luis Victoria
 */

#include <concepts>
#include <stdexcept>

/**
 * @brief Calculates the factorial of a non-negative integer n.
 * @tparam T An integral type.
 * @param n The value for which to calculate n!
 * @return The factorial of n.
 * @throws std::invalid_argument if n is negative.
 */
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


/**
 * @brief Calculates the number of permutations nPk = n! / (n-k)!
 * @tparam T An integral type.
 * @param n The total number of items.
 * @param k Number of items to arrange.
 * @return The number of ordered permutations.
 * @throws std::invalid_argument if n or k is negative or if k > n.
 */
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
