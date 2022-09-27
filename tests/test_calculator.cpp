#include "calc.hpp"

#include <catch2/catch.hpp>

TEST_CASE("Calculator calculations", "[Calculator]") {
    SECTION("Add") {
        Calculator::Calculator c{0};
        REQUIRE(c.add(4).result() == 4);
        REQUIRE(c.add(6).result() == 10);
    }
    SECTION("Sub") {
        Calculator::Calculator c{0};
        REQUIRE(c.sub(4).result() == -4);
        REQUIRE(c.sub(6).result() == -10);
    }
    SECTION("Mul") {
        Calculator::Calculator c{5};
        REQUIRE(c.mul(1.5).result() == 7.5);
        REQUIRE(c.mul(2).result() == 15);
    }
    SECTION("Div") {
        Calculator::Calculator c{10};
        REQUIRE(c.div(2).result() == 5);
        REQUIRE(c.div(2).result() == 2.5);
    }
    SECTION("Div-by-zero") {
        Calculator::Calculator c{0};
        REQUIRE_THROWS_WITH(c.div(0).result(), "Division by zero");
    }
}