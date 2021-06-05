#include <iostream>
#include <cstdlib>
#include "databaseOperations.h"
#include "utils.h"
#include "httpRequests.h"

using namespace std;

void menu();

void pressEnterToContinue();

int main() {
    DatabaseOperations databaseOperations;
    HttpRequests httpRequests;
////////////////////////////////////// Todas as consultas
//    databaseOperations.getAllAppointmentsFromNow();
//////////////////////////////////////

////////////////// Criar Paciente ///////////////////////
//    string cpf, nome, email, idade;
//
//    cout << "Digite o cpf: " << endl;
//    getline(cin, cpf);
//
//    cout << "Digite o nome: " << endl;
//    getline(cin, nome);
//
//    cout << "Digite o email: " << endl;
//    getline(cin, email);
//
//    cout << "Digite o idade: " << endl;
//    getline(cin, idade);
//
//    if(databaseOperations.createPacient(stoi(cpf), nome, stoi(idade),  email))
//        cout << "SIM" <<endl;
////////////////////////////////////////////////////////////


///////////////// Todos os medicos
//    databaseOperations.getAllDoctor();

/////////////////////////

///////////////// Todos os pacientes
//    databaseOperations.getAllPacients();

/////////////////////////


///////////////// MakeDate
//    cout << Utils::makeDate(8,5);
//    cout << Utils::getStringDate(Utils::getDateNow());

/////////////////////////


///////////////// Have appointment
//    cout << databaseOperations.doctorHaveAppointmentByDate(2444, "2020-05-20");
//    cout << databaseOperations.pacientHaveAppointmentByDate(1234, "2020-05-20");

/////////////////////////

///////////////// Criar consulta
//    string stringDate = Utils::makeDate(05,22);
//    cout << stringDate;
//    databaseOperations.createAppointment(1234,2444, stringDate);

/////////////////////////


///////////////// Editar consulta
//    string stringDate = Utils::makeDate(05,29);
//    databaseOperations.getAllAppointmentsFromNow();
//    databaseOperations.updateAppointmentDate(1, stringDate);
//    cout << databaseOperations.updateAppointmentDate(5, stringDate);

/////////////////////////

///////////////// Excluir consulta
//    databaseOperations.getAllAppointmentsFromNow();
//    ///Explicar no código
//    databaseOperations.activeFks(false);
//    databaseOperations.deleteAppointment(1);
//    databaseOperations.activeFks(true);

/////////////////////////

///////////////// Consultas de amanha
//    Utils::AllInfos allInfos = databaseOperations.getEmailsFromTomorrowAppointments();
//    for (unsigned i = 0; i < allInfos.infos.size(); i++) {
//        httpRequests.rememberAppointment(allInfos.infos.at(i));
//    }

/////////////////////////

///////////////// Teste de Request
//    httpRequests.teste();
/////////////////////////
    int choice;

    do {
        menu();
        cin >> choice;
        cout << " " << endl;
        cin.ignore();

        if (choice == 0) {
            cout << "" << endl;
            cout << "Encerrando programa..." << endl;
            cout << "" << endl;

        } else if (choice == 1) {
            string cpf, nome, email, idade;
            cout << "Digite o CPF (4 dígitos): " << endl;
            getline(cin, cpf);

            cout << "Digite o nome: " << endl;
            getline(cin, nome);

            cout << "Digite o email: " << endl;
            getline(cin, email);

            cout << "Digite a idade: " << endl;
            getline(cin, idade);

            if(databaseOperations.createPacient(stoi(cpf), nome, stoi(idade),  email))
                cout << "Paciente criado com sucesso!" << endl;

        } else if (choice == 2) {
            int patientCPF;
            int doctorCRM;
            int day;
            int month;
            databaseOperations.getAllPacients();
            cout << "Selecione o CPF do paciente: " << endl;
            cin >> patientCPF;
            cout << endl;
            databaseOperations.getAllDoctor();
            cout << "Selecione o CRM do médico: " << endl;
            cin >> doctorCRM;
            cout << endl;
            cout << "Digite o número do mês da consulta: " << endl;
            cin >> month;
            cout << endl;
            cout << "Digite o dia da consulta: " << endl;
            cin >> day;
            cout << endl;
            string stringDate = Utils::makeDate(month,day);

            if (databaseOperations.doctorHaveAppointmentByDate(doctorCRM, stringDate)) {
                cout << "Não foi possível criar consulta, pois o médico tinha outra consulta nessa data" << endl;
            } else if (databaseOperations.pacientHaveAppointmentByDate(patientCPF, stringDate)) {
                cout << "Não foi possível criar consulta, pois o paciente tinha outra consulta nessa data" << endl;
            } else {
                if(databaseOperations.createAppointment(patientCPF, doctorCRM, stringDate)) {
                    cout << "Consulta criada com sucesso!" << endl;
                }
            }
        } else if (choice == 3) {
            databaseOperations.getAllAppointmentsFromNow();

        } else if (choice == 4) {
            int appointmentId;
            int day;
            int month;
            databaseOperations.getAllAppointmentsFromNow();
            cout << "Selecione o ID da consulta:" << endl;
            cin >> appointmentId;
            pair<int,int> doctorCrmAndPatientCpf = databaseOperations.getDoctorAndPatientByAppointmentId(appointmentId);

            cout << "Digite o novo número do mês da consulta: " << endl;
            cin >> month;
            cout << "Digite o novo dia da consulta: " << endl;
            cin >> day;
            string stringDate = Utils::makeDate(month,day);

            if (databaseOperations.doctorHaveAppointmentByDate(doctorCrmAndPatientCpf.first, stringDate)) {
                cout << "Não foi possível editar consulta, pois o médico tinha outra consulta nessa data" << endl;
            } else if (databaseOperations.pacientHaveAppointmentByDate(doctorCrmAndPatientCpf.second, stringDate)) {
                cout << "Não foi possível editar consulta, pois o paciente tinha outra consulta nessa data" << endl;
            } else {
                Utils::AllInfos allInfos = databaseOperations.updateAppointmentDate(appointmentId, stringDate);
                if (allInfos.operationDb) {
                    cout << "Consulta editada com sucesso! Preparando envio de emails..." << endl;
                    for (unsigned i = 0; i < allInfos.infos.size(); i++) {
                        if(httpRequests.changeAppointmentDate(allInfos.infos.at(i))){
                            cout << " - Email para " << allInfos.infos.at(i).nome << " enviado com sucesso!" << endl;
                        } else {
                            cout << " - Erro ao enviar email para " << allInfos.infos.at(i).nome << "!" << endl;
                        }
                    }
                }
            }

        } else if (choice == 5) {
            int appointmentId;
            databaseOperations.getAllAppointmentsFromNow();
            cout << "Selecione o ID da consulta:" << endl;
            cin >> appointmentId;
            ///Desabilitar E habilitar FKS para ocorrer a exclusão
            databaseOperations.activeFks(false);
            Utils::AllInfos allInfos = databaseOperations.deleteAppointment(appointmentId);
            databaseOperations.activeFks(true);

            if(allInfos.operationDb) {
                cout << "Consulta excluída com sucesso! Preparando envio de e-mails " << endl;
                for (unsigned i = 0; i < allInfos.infos.size(); i++) {
                    if(httpRequests.deletedAppointment(allInfos.infos.at(i))) {
                        cout << " - Email para " << allInfos.infos.at(i).nome << " enviado com sucesso!" << endl;
                    } else {
                        cout << " - Erro ao enviar email para " << allInfos.infos.at(i).nome << "!" << endl;
                    }
                }
            }
        } else if (choice == 6) {
            Utils::AllInfos allInfos = databaseOperations.getEmailsFromTomorrowAppointments();
            for (unsigned i = 0; i < allInfos.infos.size(); i++) {
                if (httpRequests.rememberAppointment(allInfos.infos.at(i))) {
                    cout << " - Email para " << allInfos.infos.at(i).nome << " enviado com sucesso!" << endl;
                } else {
                    cout << " - Erro ao enviar email para " << allInfos.infos.at(i).nome << "!" << endl;
                }
            }
        } else {
            cout << "Opção Inválida" << endl;
        }
        if (choice != 0) {
            pressEnterToContinue();
        }

    } while (choice != 0);

    return EXIT_SUCCESS;
}

void pressEnterToContinue() {
    cout << "" << endl;
    cout << "Aperte enter para continuar..." << endl;
    cin.ignore();
    cin.get();
    cout << "" << endl;
}


void menu() {
    cout << "*=====================================*" << endl;
    cout << "             ADMIN CLÍNICA LP         " << endl;
    cout << "*=====================================*" << endl;
    cout << "(1) Criar Paciente" << endl;
    cout << "(2) Criar Consulta" << endl;
    cout << "(3) Visualizar Consultas" << endl;
    cout << "(4) Editar data de Consulta" << endl;
    cout << "(5) Excluir Consulta" << endl;
    cout << "(6) E-mail para consultas de amanhã" << endl;
    cout << "(0) Finalizar programa" << endl;
    cout << "" << endl;
    cout << "Selecione uma opcao: " << endl;
}