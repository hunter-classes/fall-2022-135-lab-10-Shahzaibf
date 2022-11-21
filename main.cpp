/*
Author: Shahzaib Fareed
Course: CSCI-135
Instructor: Zamansky
Assignment: Lab 10
    Lab is an intro to classes and enums
    I will create funcs as told using movie, Time, and TimeSlot classes
*/
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

    Movie movie1 = {"Back to the Future", COMEDY, 116};

    TimeSlot morning = {movie1, {10, 40}};  
    TimeSlot morning2 = {movie1, {9,15}};

    std::cout << getTimeSlot(morning) << "\n";

    std::cout << getTimeSlot(scheduleAfter(morning, movie1)) << "\n";//should start at 11:11

    //should be true
    timeOverlap(morning,morning2) ? std::cout << "OVERLAP\n" : std::cout << "NO OVERLAP\n";
    return 0;
}