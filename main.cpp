#include "time.h"
#include <iostream>

int main(){
    Time early = {5, 30};
    Time later = {11,20};
    Time time0 = {2,30};

    std::cout << minutesSinceMidnight(early) << "\n"; // 330
    std::cout << minutesUntil(early, later) << "\n"; // 350

    time0 = addMinutes(time0, 35);
    std::cout << time0.h << " " << time0.m << "\n"; // {3,05}
    return 0;
}