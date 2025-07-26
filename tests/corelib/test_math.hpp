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
    CHECK_THROWS_AS(factorial(-1), std::invalid_argument);
}
