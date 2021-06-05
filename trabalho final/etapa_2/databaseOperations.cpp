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
        cout << "Erro ao se conectar com o banco de dados" << endl;
        cout << "# ERR: " << e.what();
    }
    cout << endl;
}

void DatabaseOperations::getAllAppointmentsFromNow() {
    try{
        string dateNow = Utils::getStringDate(Utils::getDateNow(), "%Y-%m-%d");
        stmt = con->createStatement();

        string query = "SELECT c.id,  DATE_FORMAT(c.data, '%d/%m/%Y'), m.nome, p.nome FROM consulta c join medico m on c.crm_medico = m.crm "
                       "join paciente p on c.cpf_paciente = p.cpf where c.data >= '" + dateNow + "' order by c.id";

        res = stmt->executeQuery(query);
        if(res->rowsCount()) {
            while (res->next()) {
                cout << "Id: " << left << setw(4) << setfill(' ') << res->getInt(1) ;
                cout << " Data: " << left << setw(12) << setfill(' ')  <<  res->getString(2);
                cout << " Médico: " << left << setw(15) << setfill(' ')  <<  res->getString(3);
                cout << " Paciente: " << left << setw(15) << setfill(' ') << res->getString(4) << endl;
            }

        } else {
            cout << "Nenhuma consulta de hoje em diante foi encontrada!" << endl;
        }
        delete res;
        delete stmt;

    } catch (sql::SQLException &e) {
        cout << "Erro ao selecionar consultas!" << endl;
        cout << "# ERR: " << e.what();
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
        ///Erro para Key duplicada
        if (e.getSQLState() == "23000" && e.getErrorCode() == 1022) {
            cout << "Esse paciente já se encontrava na base de dados" << endl;
        } else {
            cout << "Erro desconhecido ao criar paciente!" << endl;
            cout << "# ERR: " << e.what();
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
                cout << "CRM: " << setw(4) << setfill(' ') << left << res->getInt(1);
                cout << " Nome: " << res->getString(2) << endl;
            }
            delete res;
            delete stmt;
        } else {
            cout << "Nenhum médico foi encontrada!" << endl;
        }

    } catch (sql::SQLException &e) {
        cout << "Erro desconhecido ao obter médicos!" << endl;
        cout << "# ERR: " << e.what();
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
                cout << "CPF: "  << setw(4) << setfill(' ') << left <<res->getInt(1);
                cout << " Nome: " << res->getString(2) << endl;
            }

        } else {
            cout << "Nenhum médico foi encontrada!" << endl;
        }
        delete res;
        delete stmt;

    } catch (sql::SQLException &e) {
        cout << "Erro desconhecido ao obter pacientes!" << endl;
        cout << "# ERR: " << e.what();
    }
    cout << endl;
}

bool DatabaseOperations::doctorHaveAppointmentByDate(int crm, string dateString) {
    try{
        stmt = con->createStatement();
        string query = "SELECT c.id from consulta c join medico m on m.crm=c.crm_medico  where m.crm=" + to_string(crm) + " and c.data = '" + dateString + "'";
        res = stmt->executeQuery(query);

        int count = res->rowsCount();

        delete stmt;
        delete res;
        return count;

    } catch (sql::SQLException &e) {
        cout << "Erro desconhecido ao verificar disponibilidade do médico!" << endl;
        cout << "# ERR: " << e.what();
        return false;
    }
}

bool DatabaseOperations::pacientHaveAppointmentByDate(int cpf, string dateString) {
    try{
        stmt = con->createStatement();
        string query = "SELECT c.id from consulta c join paciente p on p.cpf=c.cpf_paciente where p.cpf=" + to_string(cpf)  + " and c.data = '" + dateString + "'";
        res = stmt->executeQuery(query);

        int count = res->rowsCount();

        delete stmt;
        delete res;
        return count;

    } catch (sql::SQLException &e) {
        cout << "Erro desconhecido ao verificar disponibilidade do paciente!" << endl;
        cout << "# ERR: " << e.what();
        return false;
    }
}

bool DatabaseOperations::createAppointment(int cpf, int crm, string dateString) {
    try{
        stmt = con->createStatement();
        string createAppointmentQuery = "INSERT INTO consulta(id, `data` , crm_medico, cpf_paciente) VALUES (null, '" + dateString + "', (SELECT crm FROM medico WHERE crm =" + to_string(crm) + "), (SELECT cpf FROM paciente WHERE cpf = " + to_string(cpf) +"));";
        stmt->execute(createAppointmentQuery);

        ///Como um paciente e um doutor só podem ter uma consulta por dia, faço essa busca para saber qual é a consulta
        string selectAppointmentQuery = "SELECT c.id,  DATE_FORMAT(c.data, '%d/%m/%Y'), m.nome, p.nome FROM consulta c join medico m on c.crm_medico = m.crm "
                       "join paciente p on c.cpf_paciente = p.cpf where c.data = '" + dateString + "' and c.crm_medico = " + to_string(crm) + " and c.cpf_paciente=" + to_string(cpf);
        res = stmt->executeQuery(selectAppointmentQuery);

        while (res->next()) {
            cout << "Id: " << left << setw(4) << setfill(' ') << res->getInt(1) ;
            cout << " Data: " << left << setw(12) << setfill(' ')  <<  res->getString(2);
            cout << " Médico: " << left << setw(15) << setfill(' ')  <<  res->getString(3);
            cout << " Paciente: " << left << setw(15) << setfill(' ') << res->getString(4) << endl;
        }

        delete res;
        delete stmt;
        return true;

    } catch (sql::SQLException &e) {
        cout << "Erro desconhecido ao criar consulta!" << endl;
        cout << "# ERR: " << e.what();
        return false;
    }
}

Utils::AllInfos DatabaseOperations::updateAppointmentDate(int appointmentId, string newDateString) {
    Utils::AllInfos allInfos;
    vector<Utils::InfoFromDbToRequest> infos;
    try{
        stmt = con->createStatement();
        string selectQuery = "SELECT m.nome, m.email, p.nome, p.email, DATE_FORMAT(c.data, '%d/%m/%Y') FROM consulta c join medico m on c.crm_medico = m.crm "
                             "join paciente p on c.cpf_paciente = p.cpf where c.id = " + to_string(appointmentId);


        res = stmt->executeQuery(selectQuery);
        while (res->next()) {
            Utils::InfoFromDbToRequest infoFromPacient;
            infoFromPacient.nome = res->getString(3);
            infoFromPacient.email = res->getString(4);
            infoFromPacient.dataOriginal = res->getString(5);
            infoFromPacient.novaData = Utils::formatDateStringToBRL(newDateString);


            Utils::InfoFromDbToRequest infoFromDoctor;
            infoFromDoctor.nome = res->getString(1);
            infoFromDoctor.email = res->getString(2);
            infoFromDoctor.dataOriginal = res->getString(5);
            infoFromDoctor.novaData = Utils::formatDateStringToBRL(newDateString);

            infos.push_back(infoFromPacient);
            infos.push_back(infoFromDoctor);
        }

        allInfos.infos = infos;

        string updateQuery = "UPDATE consulta c SET `data`='" + newDateString + "' where c.id=" + to_string(appointmentId);
        stmt->execute(updateQuery);

        delete stmt;
        delete res;

        allInfos.operationDb = true;
        return allInfos;

    } catch (sql::SQLException &e) {
        cout << "Erro desconhecido ao editar data da consulta!" << endl;
        cout << "# ERR: " << e.what();

        allInfos.operationDb = false;
        return allInfos;
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
        cout << "Erro desconhecido ao ativar/desativar FK's!" << endl;
        cout << "# ERR: " << e.what();
    }
}

Utils::AllInfos DatabaseOperations::deleteAppointment(int appointmentId) {
    Utils::AllInfos allInfos;
    vector<Utils::InfoFromDbToRequest> infos;
    try{
        stmt = con->createStatement();
        string selectQuery = "SELECT m.nome, m.email, p.nome, p.email, DATE_FORMAT(c.data, '%d/%m/%Y') FROM consulta c join medico m on c.crm_medico = m.crm "
                             "join paciente p on c.cpf_paciente = p.cpf where c.id = " + to_string(appointmentId);


        res = stmt->executeQuery(selectQuery);
        while (res->next()) {
            Utils::InfoFromDbToRequest infoFromPacient;
            infoFromPacient.nome = res->getString(3);
            infoFromPacient.email = res->getString(4);
            infoFromPacient.dataOriginal = res->getString(5);


            Utils::InfoFromDbToRequest infoFromDoctor;
            infoFromDoctor.nome = res->getString(1);
            infoFromDoctor.email = res->getString(2);
            infoFromDoctor.dataOriginal = res->getString(5);

            infos.push_back(infoFromPacient);
            infos.push_back(infoFromDoctor);
        }
        allInfos.infos = infos;

//        string deleteQuery = "DELETE FROM consulta c WHERE c.id=" + to_string(appointmentId);
//        stmt->execute(deleteQuery);

        delete res;
        delete stmt;

        allInfos.operationDb = true;
        return allInfos;

    } catch (sql::SQLException &e) {
        cout << "Erro desconhecido ao excluir consulta!" << endl;
        cout << "# ERR: " << e.what();

        allInfos.operationDb = false;
        return allInfos;
    }
}

Utils::AllInfos DatabaseOperations::getEmailsFromTomorrowAppointments() {
    Utils::AllInfos allInfos;
    vector<Utils::InfoFromDbToRequest> infos;
    try{
        struct tm* date = Utils::getDateNow();
        date->tm_mday +=1;

        string tomorrowDate = Utils::getStringDate(date, "%Y-%m-%d");
        stmt = con->createStatement();

        string query = "SELECT m.nome, m.email, p.nome, p.email FROM consulta c join medico m on c.crm_medico = m.crm "
                       "join paciente p on c.cpf_paciente = p.cpf where c.data = '" + tomorrowDate + "'";

        res = stmt->executeQuery(query);
        cout << res->rowsCount();
        if(res->rowsCount()) {
            while (res->next()) {
                Utils::InfoFromDbToRequest infoFromPacient;
                infoFromPacient.nome = res->getString(3);
                infoFromPacient.email = res->getString(4);
                infoFromPacient.dataOriginal = Utils::formatDateStringToBRL(tomorrowDate);


                Utils::InfoFromDbToRequest infoFromDoctor;
                infoFromDoctor.nome = res->getString(1);
                infoFromDoctor.email = res->getString(2);
                infoFromDoctor.dataOriginal =  Utils::formatDateStringToBRL(tomorrowDate);

                infos.push_back(infoFromPacient);
                infos.push_back(infoFromDoctor);
            }
            allInfos.infos = infos;
        } else {
            cout << "Nenhuma consulta foi encontrada!" << endl;
        }

        delete res;
        delete stmt;

        allInfos.operationDb = true;
        return allInfos;

    } catch (sql::SQLException &e) {
        cout << "Erro desconhecido ao buscar consultas para amanhã!" << endl;
        cout << "# ERR: " << e.what();

        allInfos.operationDb = false;
        return allInfos;
    }

}

pair<int, int> DatabaseOperations::getDoctorAndPatientByAppointmentId(int appointmentId) {
    pair<int,int> doctorCrmAndPatientCpf;
    try{
        stmt = con->createStatement();
        string selectQuery = "SELECT m.crm, p.cpf FROM consulta c join medico m on c.crm_medico = m.crm "
                             "join paciente p on c.cpf_paciente = p.cpf where c.id = " + to_string(appointmentId);


        res = stmt->executeQuery(selectQuery);
        while (res->next()) {
            doctorCrmAndPatientCpf = make_pair(res->getInt(1), res->getInt(2));
        }

        delete stmt;
        delete res;

        return doctorCrmAndPatientCpf;

    } catch (sql::SQLException &e) {
        cout << "Erro desconhecido ao buscar CRM e CPF pela consulta" << endl;
        cout << "# ERR: " << e.what();
        return make_pair(0,0);
    }
}
