//
// Created by calindra on 23/05/2021.
//

#include "httpRequests.h"

bool HttpRequests::sendRequest(string body, string url) {
    long response_code;
    CURL *curl = curl_easy_init();
    if (curl) {
        CURLcode res;
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        struct curl_slist *hs = NULL;
        hs = curl_slist_append(hs, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, hs);

        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, body.length());
        curl_easy_setopt(curl, CURLOPT_POST, 1);


        res = curl_easy_perform(curl);
        if (res == CURLE_OK) {
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        }
        curl_easy_cleanup(curl);
    }
    return response_code == 200;
}

bool HttpRequests::rememberAppointment(Utils::InfoFromDbToRequest infoFromDbToRequest) {
    string body = "{\"nome\" : \"" + infoFromDbToRequest.nome + "\", \"email\" : \"" + infoFromDbToRequest.email +
                  "\", \"dataOriginal\" : \"" + infoFromDbToRequest.dataOriginal + "\", \"novaData\" : \"" +
                  infoFromDbToRequest.novaData + "\" }";
    string url = "http://localhost:2021/remember-appointment";
    return sendRequest(body, url);
}

bool HttpRequests::deletedAppointment(Utils::InfoFromDbToRequest infoFromDbToRequest) {
    string body = "{\"nome\" : \"" + infoFromDbToRequest.nome + "\", \"email\" : \"" + infoFromDbToRequest.email +
                  "\", \"dataOriginal\" : \"" + infoFromDbToRequest.dataOriginal + "\", \"novaData\" : \"" +
                  infoFromDbToRequest.novaData + "\" }";
    string url = "http://localhost:2021/deleted-appointment";
    return sendRequest(body, url);
}

bool HttpRequests::changeAppointmentDate(Utils::InfoFromDbToRequest infoFromDbToRequest) {
    string body = "{\"nome\" : \"" + infoFromDbToRequest.nome + "\", \"email\" : \"" + infoFromDbToRequest.email +
                  "\", \"dataOriginal\" : \"" + infoFromDbToRequest.dataOriginal + "\", \"novaData\" : \"" +
                  infoFromDbToRequest.novaData + "\" }";
    string url = "http://localhost:2021/change-appointment-date";
    return sendRequest(body, url);
}




