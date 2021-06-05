//
// Created by calindra on 18/05/2021.
//

#ifndef ETAPA_2_UTILS_H
#define ETAPA_2_UTILS_H
#include <string>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

class Utils {
    public:
        static tm * getDateNow();
        static time_t getNowRawtime();
        static string makeDate(int month, int day);
        static bool dateIsValid(time_t dateToCompare);
        static string getStringDate(struct tm * date, string format);
        static string formatDateStringToBRL(string mySqlFormatDate);
        struct InfoFromDbToRequest {
            string nome, email, dataOriginal, novaData;
        };
        struct AllInfos {
            vector<InfoFromDbToRequest> infos;
            bool operationDb;
        };
};


#endif //ETAPA_2_UTILS_H
