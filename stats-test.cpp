#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "stats.h"
#include <math.h>
#include <cmath>

TEST_CASE("reports average, minimum and maximum") {
    auto computedStats = Statistics::ComputeStatistics({1.5, 8.9, 3.2, 4.5});
    float epsilon = 0.001;
    REQUIRE(std::abs(computedStats.average - 4.525) < epsilon);
    REQUIRE(std::abs(computedStats.max - 8.9) < epsilon);
    REQUIRE(std::abs(computedStats.min - 1.5) < epsilon);
}

TEST_CASE("average, minimum and maximum is NaN for empty array") {
    auto computedStats = Statistics::ComputeStatistics({});
    //All fields of computedStats (average, max, min) must be
    //NAN (not-a-number), as defined in math.h
    //Design the REQUIRE statement here.
    REQUIRE(isnan(computedStats.average));
    REQUIRE(isnan(computedStats.max));
    REQUIRE(isnan(computedStats.min));    
}

TEST_CASE("reports average, minimum and maximum for array having few NaN values") {
    auto computedStats = Statistics::ComputeStatistics({1.5, 8.9, NAN, 3.2, NAN, 4.5});
    float epsilon = 0.001;
    REQUIRE(std::abs(computedStats.average - 4.525) < epsilon);
    REQUIRE(std::abs(computedStats.max - 8.9) < epsilon);
    REQUIRE(std::abs(computedStats.min - 1.5) < epsilon);
}
