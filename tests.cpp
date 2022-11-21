#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "time.h"

TEST_CASE("Task A"){
    Time early = {10,30};
    Time late = {13,40};
    CHECK(minutesSinceMidnight(early) == 630);
    CHECK(minutesUntil(early,late) == 190);
}