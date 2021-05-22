//
// Created by calindra on 18/05/2021.
//

#ifndef ETAPA_2_UTILS_H
#define ETAPA_2_UTILS_H
#include <string>
#include <ctime>
#include <iomanip>
#include <iostream>

using namespace std;

class Utils {
    public:
        static tm * getDateNow();
        static time_t getNowRawtime();
        static string makeDate(int month, int day);
        static bool dateIsValid(time_t dateToCompare);
        static string getStringDate(struct tm * date);

    private:


};


#endif //ETAPA_2_UTILS_H
