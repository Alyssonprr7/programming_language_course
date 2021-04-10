//
// Created by calindra on 09/04/2021.
//

#include "agenda.h"
#include <iostream>

int Agenda::insertedCadastros = 0;

void Agenda::insereCadastro(Cadastro &cadastro) {
    if(insertedCadastros + 1 > maxCadastros){
        cout << "The max number of Cadastros was reached." << endl;
    } else {
        cadastros[insertedCadastros] = cadastro;
        insertedCadastros++;
        cout << "The Cadastro was inserted" << endl;
    }
}

void Agenda::printCadastros() {
    for (int i = 0; i < insertedCadastros; i++){
        cout << "Name: " << cadastros[i].getName() << endl;
        cout << "Job: " << cadastros[i].getJob() << endl;
        cout << "Age: " << cadastros[i].getAge() << endl;
        cout << "" << endl;
    }
}

