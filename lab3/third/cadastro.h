//
// Created by calindra on 09/04/2021.
//

#ifndef LABORATORIO_3_CADASTRO_H
#define LABORATORIO_3_CADASTRO_H
#include <string>

using namespace std;

class Cadastro {
    public:
        void setName(string newName);
        string getName();

        void setJob(string newJob);
        string getJob();

        void setAge(int newAge);
        string getAge();

    private:
        string name, job;
        int age;
        string checkName(string name);

};


#endif //LABORATORIO_3_CADASTRO_H
