/*
Author: Shahzaib Fareed
Course: CSCI-135
Instructor: Zamansky
Assignment: Lab 10
    Header file.
    As given by the lab.
*/
#pragma once
#include <string>

class Time { 
public:
    int h;
    int m;
};
int minutesSinceMidnight(Time time);
int minutesUntil(Time earlier, Time later);
Time addMinutes(Time time0, int min);

enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};
class Movie { 
public: 
    std::string title;
    Genre genre;     // only one genre per movie
    int duration;    // in minutes
};

class TimeSlot { 
public: 
    Movie movie;     // what movie
    Time startTime;  // when it starts
};
std::string printMovie(Movie mv);
std::string getTimeSlot(TimeSlot ts);
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie);
bool timeOverlap(TimeSlot ts1, TimeSlot ts2);