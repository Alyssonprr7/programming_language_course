//
// Created by calindra on 17/04/2021.
//

#include "agenda.h"
#include <iostream>

using namespace std;

string Agenda::checkName(string name) {
    string newName = name;
    if(name.size() > maxNameSize){
        newName = name.substr(0, 10);
        cout << "The name is over 10 letters, so did trucated by: " << newName<< endl;
    }
    return newName;
}

bool Agenda::isUniqueContact(string name) {
    for (int i = 0; i < contacts.size(); i++){
        if(contacts[i].getName().compare(name) == 0){
            return false;
        }
    }

    return true;
}

void Agenda::addContact(string name, string job, int age) {
    if(contacts.size() < maxVectorSize){
        string verifiedName = checkName(name);
        if(isUniqueContact(verifiedName)) {
            Contact contact(verifiedName, job, age);
            contacts.push_back(contact);
        } else {
            cout << "The contact " << name <<" is existent in agenda" << endl;
        }
    } else {
        cout << "The max size of Agenda was reached" << endl;
    }
}

Agenda::Agenda(int maxContacts) {
    maxVectorSize = maxContacts;
    maxNameSize = 10;
    filename= "contactFile.txt";

    readFile();
}

int Agenda::findContactIndex(string name) {
    for (int i = 0; i < contacts.size(); i++){
        if(contacts[i].getName().compare(name) == 0){
            return i;
        }
    }

    return -1;
}

void Agenda::editJob(string name, string newJob) {
    int index = findContactIndex(name);
    if(index >= 0 ){
        contacts[index].setJob(newJob);
        cout << "The job of " << name <<  " was changed to " << newJob << endl;
    } else {
        cout << "This name not exists on a Agenda" << endl;
    }
}

void Agenda::editAge(string name, int newAge) {
    int index = findContactIndex(name);
    if(index >= 0 ){
        contacts[index].setAge(newAge);
        cout << "The age " << name <<  " was changed to " << newAge << endl;
    } else {
        cout << "This name not exists on a Agenda" << endl;
    }
}

void Agenda::deleteContact(string name) {
    int index = findContactIndex(name);
    if(index >= 0 ){
        contacts.erase(contacts.begin() + index);
        cout << "The contact " << name << " was deleted" << endl;
    } else {
        cout << "This name not exists on a Agenda" << endl;
    }
}

void Agenda::readFile() {
    string name, job;
    int age;
    file.open(filename, fstream::in);

    if(!file.is_open()){
        cout << "Error to open file" << endl;
    }

    while(file.good()){
        bool isEmpty = file.peek() == EOF;
        if(!isEmpty){
            file >> name >> job >> age;
            addContact(name, job, age);
            cout << "Get contact " << name << endl;
        }
    }

    file.close();
}

void Agenda::writeFile() {
    file.open(filename, fstream::out);
    for (int i = 0; i < contacts.size(); i++){
        file << contacts[i].getName() << " " << contacts[i].getJob() << " " << contacts[i].getAge() << endl;
    }

    file.close();
}

void Agenda::showAllContacts() {
    for(int i = 0; i < contacts.size(); i++){
        cout << "Name: " << contacts[i].getName() << endl;
        cout << "Job: " << contacts[i].getJob() << endl;
        cout << "Age: " << contacts[i].getAge() << endl;
        cout << endl;
    }
}



