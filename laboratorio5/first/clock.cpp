//
// Created by calindra on 23/04/2021.
//

#include "clock.h"

Clock::Clock() {
    resetHour();
}

int Clock::getHours() {
    return hours;
}

int Clock::getMinutes() {
    return minutes;
}

int Clock::getSeconds() {
    return seconds;
}

void Clock::setHours(int newHours) {
    hours = checkMinutesAndSeconds(newHours, HOUR);
}

void Clock::setMinutes(int newMinutes) {
    minutes = checkMinutesAndSeconds(newMinutes, MINUTES);

}

void Clock::setSeconds(int newSeconds) {
    seconds = checkMinutesAndSeconds(newSeconds, SECONDS);
}

void Clock::resetHour() {
    times = time(nullptr);
    infoHour = localtime(&times);
    hours = infoHour->tm_hour;
    minutes = infoHour->tm_min;
    seconds = infoHour->tm_sec;
}

void Clock::resetHour(int hours, int minutes, int seconds) {
    setHours(hours);
    setMinutes(minutes);
    setSeconds(seconds);
}

Clock::Clock(int hours, int minutes, int seconds) {
    resetHour(hours, minutes, seconds);
}

void Clock::printTimes() {
    cout << setfill('0') << setw(2) << getHours()
        << ":" << setw(2) << getMinutes()
            << ":" << setw(2) << getSeconds() << endl;
}

int Clock::checkMinutesAndSeconds(int number, TimeType type) {
    int parameter;
    if(type == HOUR){
        parameter = 24;
    }else {
        parameter = 60;
    }
    if (number > parameter || number < -parameter){
        number = 0;
    }

    if (number < 0){
        number = abs(number);
    }

    return number;
}



