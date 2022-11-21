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

TEST_CASE("Task C"){
    Movie movie2 = {"Black Panther", ACTION, 134};

    TimeSlot daytime = {movie2, {12, 15}}; 
    TimeSlot evening = {movie2, {16, 45}}; 
    CHECK(getTimeSlot(daytime) == "Black Panther ACTION (134 min) [starts at 12:15, ends by 14:29]");
    CHECK(getTimeSlot(evening) == "Black Panther ACTION (134 min) [starts at 16:45, ends by 18:59]");
}

TEST_CASE("Task D"){
    Movie movie2 = {"Black Panther", ACTION, 134};

    TimeSlot daytime = {movie2, {12, 15}}; 
    TimeSlot evening = {movie2, {16, 45}}; 
    CHECK(getTimeSlot(scheduleAfter(daytime,movie2)) == "Black Panther ACTION (134 min) [starts at 14:29, ends by 16:43]");
    CHECK(getTimeSlot(scheduleAfter(evening,movie2)) == "Black Panther ACTION (134 min) [starts at 18:59, ends by 21:13]");
}