#include "calc_c.h"
#include <catch2/catch.hpp>

TEST_CASE("Integration 1", "[Calculator C]") {
    calculator_t* c = calculator_create(4);
    calculator_add(c, 6);
    calculator_mul(c, 5);
    calculator_div(c, 2);
    calculator_sub(c, 5);
    CHECK(calculator_result(c) == Approx(20));
    calculator_destroy(c);
}