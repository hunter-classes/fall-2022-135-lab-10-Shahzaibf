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

Time addMinutes(Time time0, int min){
    int h = time0.h + (min / 60);
    int m = time0.m + (min % 60);
    if (m > 60){
        h += m / 60;
        m = m % 60;
    }
    Time result = {h,m};
    return result;
}