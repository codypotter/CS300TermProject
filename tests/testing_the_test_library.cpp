//
//
//      COMPILE THIS FILE WITH THE COMMAND: cl -EHsc testing_the_test_library.cpp
//      (or if you use Linux/Mac, g++ -std=c+11 -Wall testing_the_test_library.cpp)
//
//

#define CATCH_CONFIG_MAIN
#include "../include/catch.hpp"

int Factorial(int number) {
    //this line fails the unit test
    return number <= 1 ? number : Factorial(number - 1) * number;

    //this line will pass the unit test
    //return number <= 1 ? 1 : Factorial(number - 1) * number;
}

TEST_CASE("Factorial of 0 is 1 (fail)", "[single-file]") {
    REQUIRE( Factorial(0)  == 1 );
}

TEST_CASE("Factorial of 1 and higher are computed (pass)", "[single-file]"){
    REQUIRE( Factorial(1) == 1 );
    REQUIRE( Factorial(2) == 2 );
    REQUIRE( Factorial(3) == 6 );
    REQUIRE( Factorial(10) == 3628800 );
}

