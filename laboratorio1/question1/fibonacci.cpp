//
// Created by calindra on 27/03/2021.
//

int getFibonacciNumber (int sequenceNumber) {
    if (sequenceNumber ==  0) {
        return 0;
    } else if (sequenceNumber == 1 ) {
        return 1;
    } else {
        return getFibonacciNumber(sequenceNumber -1 ) + getFibonacciNumber(sequenceNumber - 2);
    }
}

