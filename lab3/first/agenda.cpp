//
// Created by calindra on 09/04/2021.
//

#include "agenda.h"
#include <string>
#include <iostream>

using namespace std;

void Agenda::setNames(string name) {
    if(names.size() + 1 > maxNames){
        cout << "The max number of names was reached." << endl;
    } else {
        names.push_back(checkName(name));
        cout << "The name was inserted" << endl;
    }

}

string Agenda::checkName(string name) {
    string newName = name;
    if(name.size() > 10){
        newName = name.substr(0, 10);
        cout << "The name is over 10 letters, so did trucated by: " << newName<< endl;
    }
    return newName;
}

Agenda::Agenda(int maxNames) {
    setMaxNames(maxNames);
}

void Agenda::setMaxNames(int newMaxNames) {
    maxNames = newMaxNames;
}

void Agenda::printNames() {
//    for (int i = 0; i < names.size(); i++) {
//        cout << names[i] << endl;
    cout << "The names are: " << endl;
    for (auto & name : names) {
        cout << name << endl;
    }
}
