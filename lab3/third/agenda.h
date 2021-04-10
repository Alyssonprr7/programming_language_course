//
// Created by calindra on 09/04/2021.
//

#ifndef LABORATORIO_3_AGENDA_H
#define LABORATORIO_3_AGENDA_H

#include <string>
#include "cadastro.h"

class Agenda {
    public:
        void insereCadastro(Cadastro &);
        void printCadastros();
    private:
        static int insertedCadastros;
        const static int maxCadastros = 3;
        Cadastro cadastros[maxCadastros];


};


#endif //LABORATORIO_3_AGENDA_H
