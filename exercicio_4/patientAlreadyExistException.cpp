//
// Created by calindra on 02/06/2021.
//

#include "patientAlreadyExistException.h"

const char *PatientAlreadyExistException::what() const throw() {
    return "O paciente já se encontra na base!";
}
