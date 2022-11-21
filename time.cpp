#include "time.h"
#include <iostream>

int minutesSinceMidnight(Time time){
    int mins = 0;
    mins = time.h * 60 + time.m;
    return mins;
}

int minutesUntil(Time earlier, Time later){
    return minutesSinceMidnight(later) - minutesSinceMidnight(earlier);
}