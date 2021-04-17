//
// Created by calindra on 17/04/2021.
//

#ifndef LABORATORIO4_AGENDA_H
#define LABORATORIO4_AGENDA_H
#include <vector>
#include "contact.h"
#include <fstream>

using namespace std;

class Agenda {
    public:
        void addContact(string name, string job, int age);
        Agenda(int vectorSize);
        void editJob(string name, string newJob);
        void editAge(string name, int newAge);
        void deleteContact(string name);
        void readFile();
        void writeFile();
        void showAllContacts();

    private:
        vector <Contact> contacts;
        int maxVectorSize;
        int maxNameSize;
        fstream file;
        string filename;

        string checkName(string name);
        bool isUniqueContact(string name);
        int findContactIndex(string name);

};


#endif //LABORATORIO4_AGENDA_H
