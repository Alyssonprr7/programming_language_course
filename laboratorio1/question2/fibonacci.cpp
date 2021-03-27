//
// Created by calindra on 27/03/2021.
//

#include "fibonacci.h"

void Fibonacci::setSequenceNumber (int sequenceNumber){
    result = getFibonacciNumber(sequenceNumber);
}

int Fibonacci::getResult () {
    return result;
}

int Fibonacci::getFibonacciNumber (int sequenceNumber) {
    if (sequenceNumber ==  0) {
        return 0;
    } else if (sequenceNumber == 1 ) {
        return 1;
    } else {
        return getFibonacciNumber(sequenceNumber -1 ) + getFibonacciNumber(sequenceNumber - 2);
    }
}
