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

using namespace std;

class DatabaseOperations {
    public:
        DatabaseOperations();
//        ~DatabaseOperations();
        void getAllAppointmentsFromNow();
        void getAllDoctor();
        void getAllPacients();
        bool doctorHaveAppointmentByDate(int crm, string dateString);
        bool pacientHaveAppointmentByDate(int cpf, string dateString);
        bool createPacient(int cpf, string name, int idade, string email);
        bool createAppointment(int cpf, int crm, string dateString);
        bool updateAppointmentDate(int appointmentId, string newDateString);
        void activeFks(bool active);
        bool deleteAppointment(int appointmentId);
        vector<string> getEmailsFromTomorrowAppointments();


    private:
        sql::mysql::MySQL_Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        sql::ResultSet *res;
        sql::PreparedStatement  *prep_stmt;

};


#endif //ETAPA_2_DATABASEOPERATIONS_H
