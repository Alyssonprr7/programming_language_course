//
// Created by calindra on 09/04/2021.
//

#ifndef LABORATORIO_3_AGENDA_H
#define LABORATORIO_3_AGENDA_H

#include <string>
#include "cadastro.h"
#include <vector>

class Agenda {
    public:
        void insereCadastro(Cadastro &);
        void printCadastros();
    private:
        const static int maxCadastros = 3;
        vector <Cadastro> cadastros;


};


#endif //LABORATORIO_3_AGENDA_H
