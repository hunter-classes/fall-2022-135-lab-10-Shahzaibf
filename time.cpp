#include "time.h"
#include <iostream>
#include <string>

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

std::string printMovie(Movie mv){
    std::string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    return mv.title + " " + g + " (" + std::to_string(mv.duration) + " min)";
}

std::string getTimeSlot(TimeSlot ts){ 
    std::string result = printMovie(ts.movie);
    Time ending = addMinutes(ts.startTime, ts.movie.duration);
    std::string end = std::to_string(ending.h) + ":" + std::to_string(ending.m);
    result += " [starts at " + std::to_string(ts.startTime.h) + ":" + std::to_string(ts.startTime.m) + ", ends by " + end + "]";
    return result;
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){ 
    Time ending = addMinutes(ts.startTime,ts.movie.duration);
    TimeSlot Newmovie = {nextMovie, ending};
    return Newmovie;
}

bool timeOverlap(TimeSlot ts1, TimeSlot ts2){
    bool result = false;
    Time ts1showing = {ts1.startTime.h, ts1.startTime.m};
    Time ts2showing = {ts2.startTime.h, ts2.startTime.m};
    int ts1mins = minutesSinceMidnight(ts1showing);
    int ts2mins = minutesSinceMidnight(ts2showing);
    Time early;
    int duration; 
    if (ts1mins > ts2mins){
        early = ts2showing;
        duration = ts2.movie.duration;
    } else {
        early = ts1showing;
        duration = ts1.movie.duration;
    }
    int remaining = minutesUntil(ts1showing, ts2showing);
    if (duration > remaining){
        result = true;
    }
    return result;
}