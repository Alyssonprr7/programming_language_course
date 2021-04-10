//
// Created by calindra on 09/04/2021.
//

#include "agenda.h"
#include <iostream>

void Agenda::insereCadastro(Cadastro &cadastro) {
    if(cadastros.size() + 1 > maxCadastros){
        cout << "The max number of Cadastros was reached." << endl;
    } else {
        cadastros.push_back(cadastro);
        cout << "The Cadastro was inserted" << endl;
    }
}

void Agenda::printCadastros() {
//    for (int i = 0; i < cadastros.size(); i++){
    for (auto & cadastro : cadastros){
        cout << "Name: " << cadastro.getName() << endl;
        cout << "Job: " << cadastro.getJob() << endl;
        cout << "Age: " << cadastro.getAge() << endl;
        cout << "" << endl;
    }
}

