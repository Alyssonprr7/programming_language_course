//
// Created by calindra on 17/04/2021.
//

#ifndef LABORATORIO4_CONTACT_H
#define LABORATORIO4_CONTACT_H
#include <string>

using namespace std;

class Contact {
    private:
        string name;
        string job;
        int age;

    public:
        Contact(string name, string job, int age);
        void setName(string newName);
        string getName();
        void setJob(string newJob);
        string getJob();
        void setAge(int newAge);
        int getAge();



};


#endif //LABORATORIO4_CONTACT_H
