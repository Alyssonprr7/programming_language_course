//
// Created by calindra on 18/05/2021.
//

#include "databaseOperations.h"

DatabaseOperations::DatabaseOperations() {
    try {
        driver = sql::mysql::get_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "root");
        con->setSchema("trabalho_final_LP");
    } catch (sql::SQLException &e) {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line "
             << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    cout << endl;
}
//
//DatabaseOperations::~DatabaseOperations() {
//    delete con;
//    delete driver;
//}

void DatabaseOperations::getAllAppointmentsFromNow() {
    try{
        string dateNow = Utils::getStringDate(Utils::getDateNow());
        stmt = con->createStatement();

        string query = "SELECT c.id,  DATE_FORMAT(c.data, '%d/%m/%Y'), m.nome, p.nome FROM consulta c join medico m on c.crm_medico = m.crm "
                       "join paciente p on c.cpf_paciente = p.cpf where c.data >= '" + dateNow + "' order by c.id";

        res = stmt->executeQuery(query);
        if(res->rowsCount()) {
            while (res->next()) {
                cout << "Id: " << res->getInt(1);
                cout << " Data = " << res->getString(2);
                cout << " Médico: " << res->getString(3);
                cout << " Paciente: " << res->getString(4) << endl;
            }
            delete res;
            delete stmt;
        } else {
            cout << "Nenhuma consulta foi encontrada!" << endl;
        }

    } catch (sql::SQLException &e) {
        //TODO Mudar a mensageem???
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line "
             << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    cout << endl;

}

bool DatabaseOperations::createPacient(int cpf, string name, int idade, string email) {
    try{
        stmt = con->createStatement();
        string query = "INSERT INTO paciente(cpf, nome, email, idade) VALUES (" + to_string(cpf) + ", '" + name + "', '" + email + "', " + to_string(idade) +");";
        stmt->execute(query);

        delete stmt;

        return true;

    } catch (sql::SQLException &e) {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line "
             << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;

        if (e.getSQLState() == "23000") {
            cout << "Esse paciente já se encontrava na base de dados" << endl;
        }
        return false;
    }
}

void DatabaseOperations::getAllDoctor() {
    try{
        stmt = con->createStatement();

        string query = "SELECT crm, nome from medico";

        res = stmt->executeQuery(query);
        if(res->rowsCount()) {
            while (res->next()) {
                cout << "CRM: " << setw(11) << setfill(' ') << left << res->getInt(1);
                cout << " Nome: " << res->getString(2) << endl;
            }
            delete res;
            delete stmt;
        } else {
            cout << "Nenhum médico foi encontrada!" << endl;
        }

    } catch (sql::SQLException &e) {
        //TODO Mudar a mensageem???
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line "
             << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    cout << endl;
}

void DatabaseOperations::getAllPacients() {
    try{
        stmt = con->createStatement();

        string query = "SELECT cpf, nome from paciente";

        res = stmt->executeQuery(query);
        if(res->rowsCount()) {
            while (res->next()) {
                cout << "CPF: "  << setw(11) << setfill(' ') << left <<res->getInt(1);
                cout << " Nome: " << res->getString(2) << endl;
            }

        } else {
            cout << "Nenhum médico foi encontrada!" << endl;
        }
        delete res;
        delete stmt;

    } catch (sql::SQLException &e) {
        //TODO Mudar a mensageem???
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line "
             << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    cout << endl;
}

bool DatabaseOperations::doctorHaveAppointmentByDate(int crm, string dateString) {
    try{
        stmt = con->createStatement();

        string query = "SELECT c.id from consulta c join medico m on m.crm=c.crm_medico  where m.crm=" + to_string(crm) + " and c.data = '" + dateString + "'";

        res = stmt->executeQuery(query);
//        delete res;
//        delete stmt;
//
//        while (res->next()) {
//            cout << "CRM: "  << setw(11) << setfill(' ') << left <<res->getInt(1);
//        }
//        bool teste = res->rowsCount();

        return res->rowsCount();

    } catch (sql::SQLException &e) {
        //TODO Mudar a mensageem???
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line "
             << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
        return false;
    }
}

bool DatabaseOperations::pacientHaveAppointmentByDate(int cpf, string dateString) {
    try{
        stmt = con->createStatement();

        string query = "SELECT c.id from consulta c join paciente p on p.cpf=c.cpf_paciente where p.cpf=" + to_string(cpf)  + " and c.data = '" + dateString + "'";

        res = stmt->executeQuery(query);
//        delete res;
//        delete stmt;
//
//        while (res->next()) {
//            cout << "CRM: "  << setw(11) << setfill(' ') << left <<res->getInt(1);
//        }
//        bool teste = res->rowsCount();

        return res->rowsCount();

    } catch (sql::SQLException &e) {
        //TODO Mudar a mensageem???
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line "
             << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
        return false;
    }
}

bool DatabaseOperations::createAppointment(int cpf, int crm, string dateString) {
    try{
        stmt = con->createStatement();
        string query = "INSERT INTO consulta(id, `data` , crm_medico, cpf_paciente) VALUES (null, '" + dateString + "', (SELECT crm FROM medico WHERE crm =" + to_string(crm) + "), (SELECT cpf FROM paciente WHERE cpf = " + to_string(cpf) +"));";
        stmt->execute(query);

        delete stmt;

        return true;

    } catch (sql::SQLException &e) {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line "
             << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;

        if (e.getSQLState() == "23000") {
            cout << "Esse paciente já se encontrava na base de dados" << endl;
        }
        return false;
    }
}

bool DatabaseOperations::updateAppointmentDate(int appointmentId, string newDateString) {
    try{
        stmt = con->createStatement();
        string query = "UPDATE consulta c SET `data`='" + newDateString + "' where c.id=" + to_string(appointmentId);
        stmt->execute(query);

        delete stmt;

        return true;

    } catch (sql::SQLException &e) {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line "
             << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;

        if (e.getSQLState() == "23000") {
            cout << "Esse paciente já se encontrava na base de dados" << endl;
        }
        return false;
    }
}

void DatabaseOperations::activeFks(bool active) {
    try{
        stmt = con->createStatement();
        string activeString = active ? "1" : "0";
        string query = "SET FOREIGN_KEY_CHECKS=" + activeString;
        stmt->execute(query);

        delete stmt;

    } catch (sql::SQLException &e) {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line "
             << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;

        if (e.getSQLState() == "23000") {
            cout << "Esse paciente já se encontrava na base de dados" << endl;
        }
    }
}

bool DatabaseOperations::deleteAppointment(int appointmentId) {
    try{
        stmt = con->createStatement();
        string query = "DELETE FROM consulta c WHERE c.id=" + to_string(appointmentId);
        stmt->execute(query);

        delete stmt;

        return true;

    } catch (sql::SQLException &e) {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line "
             << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;

        if (e.getSQLState() == "23000") {
            cout << "Esse paciente já se encontrava na base de dados" << endl;
        }
        return false;
    }
}

vector<string> DatabaseOperations::getEmailsFromTomorrowAppointments() {

    try{
        struct tm* date = Utils::getDateNow();
        date->tm_mday +=1;
        string tomorrowDate = Utils::getStringDate(date);
        vector<string> emails;
        stmt = con->createStatement();

        string query = "SELECT m.email, p.email FROM consulta c join medico m on c.crm_medico = m.crm "
                       "join paciente p on c.cpf_paciente = p.cpf where c.data = '" + tomorrowDate + "'";

        res = stmt->executeQuery(query);
        if(res->rowsCount()) {
            while (res->next()) {
                cout << "Email 1: " << res->getString(1);
                emails.push_back(res->getString(1));
                cout << " Email2: " << res->getString(2);
                emails.push_back(res->getString(2));
            }
            delete res;
            delete stmt;
        } else {
            cout << "Nenhuma consulta foi encontrada!" << endl;
        }

        return emails;

    } catch (sql::SQLException &e) {
        //TODO Mudar a mensageem???
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line "
             << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
        //TODO: Mudar aqui
        return vector<string>();
    }

}
