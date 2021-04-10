//
// Created by calindra on 09/04/2021.
//

#include "cadastro.h"
#include <string>
#include <iostream>

using namespace std;

string Cadastro::checkName(string name) {
    string newName = name;
    if(name.size() > 10){
        newName = name.substr(0, 10);
        cout << "The name is over 10 letters, so did trucated by: " << newName<< endl;
    }
    return newName;
}

void Cadastro::setName(string newName) {
    name = checkName(newName);
}

string Cadastro::getName() {
    return name;
}

void Cadastro::setJob(string newJob) {
    job = newJob;
}

string Cadastro::getJob() {
    return job;
}

void Cadastro::setAge(int newAge) {
    age = newAge;
}

string Cadastro::getAge() {
    return to_string(age);
}

