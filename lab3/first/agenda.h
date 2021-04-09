//
// Created by calindra on 09/04/2021.
//

#ifndef LABORATORIO_3_AGENDA_H
#define LABORATORIO_3_AGENDA_H

#include <vector>
#include <string>

using namespace std;

class Agenda {
    private:
        vector <string> names;
        int maxNames;
        void setMaxNames(int newMaxNames);

    public:
        Agenda(int maxNames = 1);
        void setNames(string name);
        void printNames();


protected:
        string checkName(string name);

};


#endif //LABORATORIO_3_AGENDA_H
