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

    ///Poderia trazer uma complexidade maior para essa parte do código, mas preferi
    ///Deixar uma solução simples para uma POC
    if(dateIsValid(rawtime)) {
        cout << "A data inserida foi inválida, nova data: 10/10/2021" <<endl;
        cout << "Caso a data não seja ideal, edite-a através do menu." <<endl;
        return "2021-10-10";
    }

    return getStringDate(timeinfo, "%Y-%m-%d");
}

string Utils::getStringDate(struct tm *date, string format) {
    char buffer[80];

    strftime(buffer,sizeof(buffer),format.c_str(),date);
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

string Utils::formatDateStringToBRL(string mySqlFormatDate) {
    string year = mySqlFormatDate.substr(0,4);
    string month = mySqlFormatDate.substr(5,2);
    string day = mySqlFormatDate.substr(8,2);
    return day+"/"+month+"/"+year;
}
