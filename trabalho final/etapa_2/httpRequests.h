//
// Created by calindra on 23/05/2021.
//

#ifndef ETAPA_2_HTTPREQUESTS_H
#define ETAPA_2_HTTPREQUESTS_H
#include <curl/curl.h>
#include <string>
#include <iostream>
#include "utils.h"

using namespace std;

class HttpRequests {
    public:
        bool sendRequest(string body, string url);
        bool rememberAppointment(Utils::InfoFromDbToRequest infoFromDbToRequest);
        bool deletedAppointment(Utils::InfoFromDbToRequest infoFromDbToRequest);
        bool changeAppointmentDate(Utils::InfoFromDbToRequest infoFromDbToRequest);


};


#endif //ETAPA_2_HTTPREQUESTS_H
