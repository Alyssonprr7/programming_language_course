//
// Created by calindra on 27/03/2021.
//

#ifndef LABORATORIO1_AGENDA_H
#define LABORATORIO1_AGENDA_H

#include <string>
#include <iostream>

using namespace std;

class Agenda {
public:
    void getNames();
    void setNames();

private:
    string names [3];
    string checkName(string name);

};


#endif //LABORATORIO1_AGENDA_H
