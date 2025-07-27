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

TEST_CASE("binomial_coefficient returns correct values for basic cases") {
    // Test with int
    CHECK(binomial_coefficient(5, 2) == 10);
    CHECK(binomial_coefficient(4, 4) == 1);
    CHECK(binomial_coefficient(10, 0) == 1);
    CHECK(binomial_coefficient(0, 0) == 1);
    CHECK(binomial_coefficient(6, 3) == 20);
    CHECK(binomial_coefficient(8, 2) == 28);
    CHECK(binomial_coefficient(7, 1) == 7);

    // Test with unsigned int
    CHECK(binomial_coefficient(5u, 2u) == 10u);
    CHECK(binomial_coefficient(8u, 3u) == 56u);
    CHECK(binomial_coefficient(9u, 4u) == 126u);

    // Test with long long for larger values
    CHECK(binomial_coefficient(12LL, 5LL) == 792LL);
    CHECK(binomial_coefficient(15LL, 7LL) == 6435LL);
    CHECK(binomial_coefficient(20LL, 10LL) == 184756LL);

    // Test with short
    CHECK(binomial_coefficient(static_cast<short>(6), static_cast<short>(3)) == static_cast<short>(20));
    CHECK(binomial_coefficient(static_cast<short>(7), static_cast<short>(2)) == static_cast<short>(21));
}

TEST_CASE("binomial_coefficient edge cases") {
    // Test n choose 0 and n choose n (small values to avoid overflow)
    CHECK(binomial_coefficient(10, 0) == 1);
    CHECK(binomial_coefficient(10, 10) == 1);
    CHECK(binomial_coefficient(1, 0) == 1);
    CHECK(binomial_coefficient(1, 1) == 1);
    CHECK(binomial_coefficient(0, 0) == 1);

    // Test n choose 1 and n choose (n-1) (avoiding large values)
    CHECK(binomial_coefficient(10, 1) == 10);
    CHECK(binomial_coefficient(10, 9) == 10);
    CHECK(binomial_coefficient(8, 1) == 8);
    CHECK(binomial_coefficient(8, 7) == 8);

    // Test symmetry property: C(n,k) = C(n,n-k) (for small values where implementation works)
    CHECK(binomial_coefficient(10, 3) == binomial_coefficient(10, 7));
    CHECK(binomial_coefficient(12, 4) == binomial_coefficient(12, 8));
    CHECK(binomial_coefficient(8, 2) == binomial_coefficient(8, 6));
}

TEST_CASE("binomial_coefficient mathematical properties") {
    // Pascal's triangle property: C(n,k) = C(n-1,k-1) + C(n-1,k)
    CHECK(binomial_coefficient(5, 2) == binomial_coefficient(4, 1) + binomial_coefficient(4, 2));
    CHECK(binomial_coefficient(6, 3) == binomial_coefficient(5, 2) + binomial_coefficient(5, 3));
    CHECK(binomial_coefficient(8, 3) == binomial_coefficient(7, 2) + binomial_coefficient(7, 3));

    // Sum property: sum of C(n,k) for k=0 to n equals 2^n for small values
    int sum_n3 = binomial_coefficient(3, 0) + binomial_coefficient(3, 1) + binomial_coefficient(3, 2) + binomial_coefficient(3, 3);
    CHECK(sum_n3 == 8); // 2^3

    int sum_n4 = binomial_coefficient(4, 0) + binomial_coefficient(4, 1) + binomial_coefficient(4, 2) + binomial_coefficient(4, 3) + binomial_coefficient(4, 4);
    CHECK(sum_n4 == 16); // 2^4
}

TEST_CASE("binomial_coefficient throws on invalid input") {
    // Negative n
    CHECK_THROWS_AS(binomial_coefficient(-1, 2), std::invalid_argument);
    CHECK_THROWS_AS(binomial_coefficient(-1L, 2L), std::invalid_argument);
    CHECK_THROWS_AS(binomial_coefficient(static_cast<short>(-5), static_cast<short>(2)), std::invalid_argument);

    // Negative k
    CHECK_THROWS_AS(binomial_coefficient(2, -1), std::invalid_argument);
    CHECK_THROWS_AS(binomial_coefficient(2L, -1L), std::invalid_argument);
    CHECK_THROWS_AS(binomial_coefficient(static_cast<short>(5), static_cast<short>(-3)), std::invalid_argument);

    // Both negative
    CHECK_THROWS_AS(binomial_coefficient(-2, -1), std::invalid_argument);
    CHECK_THROWS_AS(binomial_coefficient(-5L, -3L), std::invalid_argument);

    // k > n
    CHECK_THROWS_AS(binomial_coefficient(2, 5), std::invalid_argument);
    CHECK_THROWS_AS(binomial_coefficient(2u, 5u), std::invalid_argument);
    CHECK_THROWS_AS(binomial_coefficient(static_cast<short>(3), static_cast<short>(7)), std::invalid_argument);
    CHECK_THROWS_AS(binomial_coefficient(0, 1), std::invalid_argument);
    CHECK_THROWS_AS(binomial_coefficient(10L, 15L), std::invalid_argument);
}

TEST_CASE("binomial_coefficient specific mathematical values") {
    // Well-known binomial coefficients (avoiding potential overflow)
    CHECK(binomial_coefficient(10, 5) == 252);   // Central binomial coefficient
    CHECK(binomial_coefficient(13, 5) == 1287);  // Another common value
    CHECK(binomial_coefficient(12, 6) == 924);   // Central binomial coefficient for 12

    // Triangular numbers: C(n+1, 2) = n(n+1)/2
    CHECK(binomial_coefficient(6, 2) == 15);  // 5th triangular number
    CHECK(binomial_coefficient(9, 2) == 36);  // 8th triangular number
    CHECK(binomial_coefficient(11, 2) == 55); // 10th triangular number

    // Tetrahedral numbers: C(n+2, 3)
    CHECK(binomial_coefficient(5, 3) == 10);  // 3rd tetrahedral number
    CHECK(binomial_coefficient(6, 3) == 20);  // 4th tetrahedral number
    CHECK(binomial_coefficient(7, 3) == 35);  // 5th tetrahedral number
}

TEST_CASE("binomial_coefficient implementation limitations") {
    // Large k values
    CHECK(binomial_coefficient(100, 100) == 1);    // Should be 1, currently returns 0
    CHECK(binomial_coefficient(50, 49) == 50);     // Should be 50, currently returns 0
    CHECK(binomial_coefficient(25, 24) == 25);     // Should be 25, currently returns wrong value

    // These work correctly because k is small
    CHECK(binomial_coefficient(25, 1) == 25);
    CHECK(binomial_coefficient(50, 1) == 50);
    CHECK(binomial_coefficient(100, 1) == 100);
}
