//
// Created by calindra on 17/04/2021.
//

#include "contact.h"

void Contact::setName(string newName) {
    name = newName;
}

string Contact::getName() {
    return name;
}

void Contact::setJob(string newJob) {
    job = newJob;

}

string Contact::getJob() {
    return job;
}

void Contact::setAge(int newAge) {
    age = newAge;
}

int Contact::getAge() {
    return age;
}

Contact::Contact(string name, string job, int age) {
    setName(name);
    setJob(job);
    setAge(age);
}
