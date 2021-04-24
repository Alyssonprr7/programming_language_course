//
// Created by calindra on 23/04/2021.
//

#ifndef LABORATORIO5_CLOCK_H
#define LABORATORIO5_CLOCK_H
#include <time.h>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Clock {
    private:
        time_t times;
        struct tm *infoHour;
        int hours;
        int minutes;
        int seconds;
        enum TimeType {HOUR, MINUTES, SECONDS};
        int checkMinutesAndSeconds(int number, TimeType type);

    public:
        Clock();
        Clock(int hours, int minutes, int seconds);
        int getHours();
        int getMinutes();
        int getSeconds();
        void setHours(int newHours);
        void setMinutes(int newMinutes);
        void setSeconds(int newSeconds);
        void printTimes();
        void resetHour();
        void resetHour(int hours, int minutes, int seconds);



};


#endif //LABORATORIO5_CLOCK_H
