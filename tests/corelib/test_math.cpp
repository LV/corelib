#include <doctest/doctest.h>
#include "corelib/math.hpp"

TEST_CASE("factorial returns correct values for positive integers") {
    // Test with int
    CHECK(factorial(0) == 1);
    CHECK(factorial(1) == 1);
    CHECK(factorial(5) == 120);
    CHECK(factorial(10) == 3628800);

    // Test with unsigned int
    CHECK(factorial(0u) == 1u);
    CHECK(factorial(5u) == 120u);

    // Test with long long for larger values
    CHECK(factorial(15LL) == 1307674368000LL);

    // Test with short
    CHECK(factorial(static_cast<short>(7)) == static_cast<short>(5040));
}

TEST_CASE("factorial throws on negative input") {
    // Test with different signed integral types
    CHECK_THROWS_AS(factorial(-1), std::invalid_argument);
    CHECK_THROWS_AS(factorial(-5L), std::invalid_argument);
    CHECK_THROWS_AS(factorial(static_cast<short>(-2)), std::invalid_argument);
}

TEST_CASE("permutation returns correct values") {
    // Test with int
    CHECK(permutation(5, 2) == 20);
    CHECK(permutation(4, 4) == 24);
    CHECK(permutation(10, 0) == 1);
    CHECK(permutation(0, 0) == 1);

    // Test with unsigned int
    CHECK(permutation(5u, 2u) == 20u);
    CHECK(permutation(8u, 3u) == 336u);

    // Test with long long
    CHECK(permutation(12LL, 5LL) == 95040LL);

    // Test with short
    CHECK(permutation(static_cast<short>(6), static_cast<short>(3)) == static_cast<short>(120));
}

TEST_CASE("permutation throws on invalid input") {
    // Negative n
    CHECK_THROWS_AS(permutation(-1, 2), std::invalid_argument);
    CHECK_THROWS_AS(permutation(-1L, 2L), std::invalid_argument);

    // Negative k
    CHECK_THROWS_AS(permutation(2, -1), std::invalid_argument);
    CHECK_THROWS_AS(permutation(2L, -1L), std::invalid_argument);

    // k > n
    CHECK_THROWS_AS(permutation(2, 5), std::invalid_argument);
    CHECK_THROWS_AS(permutation(2u, 5u), std::invalid_argument);
    CHECK_THROWS_AS(permutation(static_cast<short>(3), static_cast<short>(7)), std::invalid_argument);
}
