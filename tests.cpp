#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "time.h"

TEST_CASE("Task A"){
    Time early = {10,30};
    Time late = {13,40};
    CHECK(minutesSinceMidnight(early) == 630);
    CHECK(minutesUntil(early,late) == 190);
}

TEST_CASE("Task B"){
    Time altered = addMinutes({10, 30}, 60);
    Time time0 = {11, 30};
    CHECK((altered.h == time0.h && altered.m == time0.m));
    altered = addMinutes({8, 10}, 75);
    time0 = {9,25};
    CHECK((altered.h == time0.h && altered.m == time0.m));
}