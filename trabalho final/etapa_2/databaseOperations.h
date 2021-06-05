//
// Created by calindra on 18/05/2021.
//

#ifndef ETAPA_2_DATABASEOPERATIONS_H
#define ETAPA_2_DATABASEOPERATIONS_H

#include <cstdlib>
#include <iostream>

#include "mysql_driver.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <iomanip>
#include "utils.h"
#include <vector>
#include <iomanip>

using namespace std;

class DatabaseOperations {
    public:
        DatabaseOperations();
        void getAllAppointmentsFromNow();
        void getAllDoctor();
        void getAllPacients();
        bool doctorHaveAppointmentByDate(int crm, string dateString);
        bool pacientHaveAppointmentByDate(int cpf, string dateString);
        bool createPacient(int cpf, string name, int idade, string email);
        bool createAppointment(int cpf, int crm, string dateString);
        pair<int, int> getDoctorAndPatientByAppointmentId(int appointmentId);
        Utils::AllInfos updateAppointmentDate(int appointmentId, string newDateString);
        void activeFks(bool active);
        Utils::AllInfos  deleteAppointment(int appointmentId);
        Utils::AllInfos getEmailsFromTomorrowAppointments();


    private:
        sql::mysql::MySQL_Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        sql::ResultSet *res;
};


#endif //ETAPA_2_DATABASEOPERATIONS_H
