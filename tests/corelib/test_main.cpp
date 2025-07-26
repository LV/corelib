#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include "corelib/math.hpp"

TEST_CASE("factorial returns correct values for positive integers") {
    CHECK(factorial(0) == 1);
    CHECK(factorial(1) == 1);
    CHECK(factorial(5) == 120);
    CHECK(factorial(10) == 3628800);
}

TEST_CASE("factorial throws on negative input") {
    // Negative input
    CHECK_THROWS_AS(factorial(-1), std::invalid_argument);
}

TEST_CASE("permutation returns correct values") {
    CHECK(permutation(5, 2) == 20);
    CHECK(permutation(4, 4) == 24);
    CHECK(permutation(10, 0) == 1);
    CHECK(permutation(0, 0) == 1);
}

TEST_CASE("permutation throws on invalid input") {
    // Negative n
    CHECK_THROWS_AS(permutation(-1, 2), std::invalid_argument);

    // Negative k
    CHECK_THROWS_AS(permutation(2, -1), std::invalid_argument);

    // k > n
    CHECK_THROWS_AS(permutation(2, 5), std::invalid_argument);
}
