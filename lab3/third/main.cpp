//
// Created by calindra on 09/04/2021.
//

#include <iostream>
#include "agenda.h"
#include "cadastro.h"
#include <string>

using namespace std;
int main() {
    string name, job;
    int age;
    Agenda agenda;
    Cadastro cadastro;


    cout  << "Insert 3 cadastros" << endl;
    for (int i = 0; i < 3; i++){
        cout << "Name[" << i + 1 << "]" << endl;
        getline(cin, name);
        cadastro.setName(name);

        cout << "Job[" << i + 1 << "]" << endl;
        getline(cin, job);
        cadastro.setJob(job);

        cout << "Age[" << i + 1 << "]" << endl;
        cin >> age;
        cin.ignore(); //Reseta o buffer de entrada, como se fosse o endl
        cadastro.setAge(age);

        agenda.insereCadastro(cadastro);
    }

    agenda.printCadastros();


    return 0;
}
