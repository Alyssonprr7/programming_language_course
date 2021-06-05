//
// Created by calindra on 02/06/2021.
//

#ifndef EXERCICIO_4_PATIENTALREADYEXISTEXCEPTION_H
#define EXERCICIO_4_PATIENTALREADYEXISTEXCEPTION_H

#include <stdexcept>

using namespace std;

class PatientAlreadyExistException : public exception {
public:
    virtual const char * what() const throw();

};


#endif //EXERCICIO_4_PATIENTALREADYEXISTEXCEPTION_H
