//
// Created by calindra on 27/03/2021.
//

#include <iostream>
#include "fibonacci.h"
using namespace std;

int main ()  {
    int sequenceNumber;
    Fibonacci fibonacci;

    cout << "Please, insert the number: " << endl;
    cin >> sequenceNumber;

    fibonacci.setSequenceNumber(sequenceNumber);


    cout << "The number in Fibonacci sequence is " << fibonacci.getResult() << endl;

    return 0;
}