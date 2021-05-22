#include <iostream>
#include <cstdlib>
#include "databaseOperations.h"
#include "utils.h"

using namespace std;

int main() {
    DatabaseOperations databaseOperations;
////////////////////////////////////// Todas as consultas
//    databaseOperations.getAllAppointments(Utils::getDateNowString());
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
//    string stringDate = Utils::makeDate(05,26);
//    databaseOperations.getAllAppointmentsFromNow();
//    cout << databaseOperations.updateAppointmentDate(5, stringDate);

/////////////////////////

///////////////// Excluir consulta
//    databaseOperations.getAllAppointmentsFromNow();
//    ///Explicar no código
//    databaseOperations.activeFks(false);
//    cout << databaseOperations.deleteAppointment(5);
//    databaseOperations.activeFks(true);

/////////////////////////

///////////////// Consultas de amanha
    databaseOperations.getEmailsFromTomorrowAppointments();


/////////////////////////


    return EXIT_SUCCESS;
}
