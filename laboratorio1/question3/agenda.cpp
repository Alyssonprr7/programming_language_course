//
// Created by calindra on 27/03/2021.
//

#include "agenda.h"

void Agenda::setNames() {
    string name;

    for (int i = 0; i < 3; i++){
        cout << "Insert a name " << endl;
        getline(cin,name);
        names [i] = checkName(name);
    }

}

void Agenda::getNames() {
    for(int i = 0; i < 3; i++ ) {
        cout << "Name " << (i + 1) << " " << names [i] << endl;
    }
}

string Agenda::checkName(string name) {
    if(name.length() > 10){
        name = name.substr(0,10);
        cout << "The name " << name << " was sliced because had more than 10 letters" << endl;
    }
    return name;
}
