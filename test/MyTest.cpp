#include "catch.hpp"

SCENARIO("I want to assert that true equals true") {
    GIVEN("the value of my variable equals true") {
        bool myVar = true;

        WHEN("asserting the variable value equals true") {
            THEN("my test passes") {
                REQUIRE(myVar == true);
            }
        }
    }
}