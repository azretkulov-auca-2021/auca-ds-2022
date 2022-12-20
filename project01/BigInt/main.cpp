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

TEST_CASE("constructor with an integer")
{
    ostringstream sout;
    SUBCASE("322")
    {
        BigInt x(322);
        sout << x;
        REQUIRE(sout.str() == "322");
    }

    SUBCASE("-404")
    {
        BigInt x(-404);
        sout << x;
        REQUIRE(sout.str() == "-404");
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
    SUBCASE(" 123")
    {
        REQUIRE_THROWS_AS(BigInt(" 123"), runtime_error);
        REQUIRE_THROWS_WITH(BigInt(" 123"), "Incorrect format of BigInteger");
    }
    SUBCASE("123-123")
    {
        REQUIRE_THROWS_AS(BigInt("123-123"), runtime_error);
        REQUIRE_THROWS_WITH(BigInt("123-123"), "Incorrect format of BigInteger");
    }
    SUBCASE("hello")
    {
        REQUIRE_THROWS_AS(BigInt("hello"), runtime_error);
        REQUIRE_THROWS_WITH(BigInt("hello"), "Incorrect format of BigInteger");
    }

    SUBCASE("empty string")
    {
        REQUIRE_THROWS_AS(BigInt(""), runtime_error);
    }
}

TEST_CASE("Addition")
{
    ostringstream sout;

    SUBCASE("positive + positive, test #1")
    {
        BigInt x("193");
        BigInt y("59");
        sout << x + y;
        REQUIRE(sout.str() == "252");
    }

    SUBCASE("positive + positive, test #2")
    {
        BigInt x("999");
        BigInt y("1");
        sout << x + y;
        REQUIRE(sout.str() == "1000");
    }

    // SUBCASE("positive + positive, test #3")
    // {
    //     for (int x = 0; x <= 1000; ++x)
    //     {
    //         for (int y = 0; y <= 1000; ++y)
    //         {
    //             BigInt a(to_string(x));
    //             BigInt b(to_string(y));
    //             sout << a + b;
    //             REQUIRE(sout.str() == to_string(x + y));
    //             sout.str("");
    //         }
    //     }
    // }

    SUBCASE("positive + negative")
    {
        // TODO
    }
    SUBCASE("negative + positive")
    {
        // TODO
    }
    SUBCASE("negative + negative")
    {
        // TODO
    }
}

TEST_CASE("operators of comparing ")
{
    SUBCASE(" == operator")
    {
        BigInt x(5);
        BigInt y("5");
        REQUIRE(x == y);
    }

    SUBCASE(" != operator")
    {
        BigInt x(5);
        BigInt y("-4");
        REQUIRE(x != y);
    }

    SUBCASE(" < operator")
    {
        BigInt x(4);
        BigInt y("5");
        REQUIRE(x < y);
    }

    SUBCASE(" > operator")
    {
        BigInt x(5);
        BigInt y("-4");
        REQUIRE(x > y);
    }

    SUBCASE(" >= operator")
    {
        BigInt x(5);
        BigInt y("4");
        REQUIRE(x >= y);

        BigInt a("5");
        BigInt b(5);
        REQUIRE(a >= b);
    }

    SUBCASE(" <= operator")
    {
        BigInt x("4");
        BigInt y(5);
        REQUIRE(x <= y);

        BigInt a("4");
        BigInt b(4);
        REQUIRE(a <= b);
    }
}

TEST_CASE("input operator")
{
    ostringstream sout;

    // SUBCASE("correct input #1")
    // {
    //     istringstream sinp("123");
    //     BigInt x;
    //     sinp >> x;
    //     REQUIRE(sinp.eof());
    //     REQUIRE(x == 123);
    // }

     SUBCASE("correct input #2")
    {
        istringstream sinp("    123");
        BigInt x;
        sinp >> x;
        REQUIRE(sinp.good());
        REQUIRE(x == 123);
    }

     SUBCASE("correct input #3")
    {
        istringstream sinp("123u123");
        BigInt x;
        sinp >> x;
        REQUIRE(sinp.good());
        REQUIRE(x == 123);
        char ch;
        sinp >> ch;
        REQUIRE(ch == 'u');
    }

     SUBCASE("correct input #4")
    {
        istringstream sinp("    -123");
        BigInt x;
        sinp >> x;
        REQUIRE(sinp.eof());
        REQUIRE(x == -123);
    }

     SUBCASE("correct input #5")
    {
        istringstream sinp("   +123");
        BigInt x;
        sinp >> x;
        REQUIRE(sinp.eof());
        REQUIRE(x == 123);
    }

     SUBCASE("incorrect input #1")
    {
        istringstream sinp("+ 123");
        BigInt x;
        sinp >> x;
        REQUIRE(sinp.fail());
        REQUIRE(x == 0);
    }

    SUBCASE("incorrect input #2")
    {
        istringstream sinp("++123");
        BigInt x;
        sinp >> x;
        REQUIRE(sinp.fail());
        REQUIRE(x == 0);
    }

    SUBCASE("incorrect input #3")
    {
        istringstream sinp("hello");
        BigInt x;
        char ch;
        sinp >> x; 
        REQUIRE(sinp.fail());
        REQUIRE(x == 0);
        sinp.clear();
        sinp >> ch;
        REQUIRE(ch == 'h');
    }    
    SUBCASE("incorrect input #4")
    {
        istringstream sinp("");
        BigInt x;
        sinp >> x;
        REQUIRE(sinp.fail());
        REQUIRE(sinp.eof());
        REQUIRE(x == 0);
    }
}