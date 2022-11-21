#include "time.h"
#include <iostream>

int main(){
    Time early = {5, 30};
    Time later = {11,20};

    std::cout << minutesSinceMidnight(early) << "\n"; // 330
    std::cout << minutesUntil(early, later) << "\n"; // 350

    return 0;
}