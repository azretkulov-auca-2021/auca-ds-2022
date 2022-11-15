#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest/doctest.h"

#include <sstream>
#include <string>

#include "BigInt.hpp"

using namespace std;

TEST_CASE("Default constructor") 
{
    BigInt x;
    ostringstream sout;
    sout << x;
    REQUIRE(sout.str() == "0");

    vector<BigInt> v(5);
    for (const auto &e : v)
    {
        ostringstream sout2;
        sout2 << e;
        REQUIRE(sout2.str() == "0");
    }
}

TEST_CASE("constructor with a string")
{
    ostringstream sout;
    SUBCASE("positive number")
    {
        BigInt x("123456789123456789");
        sout << x;
        REQUIRE(sout.str() == "123456789123456789");
    }

     SUBCASE("positive number")
    {
        BigInt x("+123456789123456789");
        sout << x;
        REQUIRE(sout.str() == "123456789123456789");
    }

    SUBCASE("negative number")
    {
        BigInt x("-123");
        sout << x;
        REQUIRE(sout.str() == "-123");
    }

    SUBCASE("empty string")
    {
        REQUIRE_THROWS_AS(BigInt(""), runtime_error);
    }

    // a lot of other special cases
    // 123xyz123
    // 123 123
    // hello
    // "  -123  "
    // "- 123"
}