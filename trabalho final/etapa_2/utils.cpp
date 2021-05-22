//
// Created by calindra on 18/05/2021.
//

#include "utils.h"

tm *Utils::getDateNow() {
    time_t rawtime = getNowRawtime();
    struct tm * timeinfo;
    timeinfo = localtime(&rawtime);

    return timeinfo;
}

string Utils::makeDate(int month, int day) {
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    timeinfo->tm_year = 2021 - 1900;
    timeinfo->tm_mon = month - 1;
    timeinfo->tm_mday = day;

    rawtime = mktime(timeinfo);
    timeinfo = localtime(&rawtime);

    ///Aqui é para verificar se é uma data válida
    if(dateIsValid(rawtime)) {
        //TODO Fazer dar erro
    }

    return getStringDate(timeinfo);
}

string Utils::getStringDate(struct tm *date) {
    char buffer[80];

    strftime(buffer,sizeof(buffer),"%Y-%m-%d",date);
    string dateStr(buffer);
    return dateStr;
}

time_t Utils::getNowRawtime() {
    time_t rawtime;
    time (&rawtime);

    return rawtime;
}

bool Utils::dateIsValid(time_t dateToCompare) {
    return difftime(getNowRawtime(), dateToCompare) > 0;
}
