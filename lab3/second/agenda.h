//
// Created by calindra on 09/04/2021.
//

#ifndef LABORATORIO_3_AGENDA_H
#define LABORATORIO_3_AGENDA_H

#include <string>

using namespace std;

class Agenda {
    private:
        const static int maxNames = 2;
        string names[maxNames];
//        void setMaxNames(int newMaxNames);
        static int insertedNames;
    public:
        void setNames(string name);
        void printNames();


protected:
        string checkName(string name);

};


#endif //LABORATORIO_3_AGENDA_H
