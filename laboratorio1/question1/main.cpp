//
// Created by Rocha on 27/03/2021.
//

#include <iostream>
#include "fibonacci.h"

using namespace std;

int main ()  {
    int sequenceNumber;
    int fibonacciNumber;

    cout << "Please, insert the number: " << endl;
    cin >> sequenceNumber;

    fibonacciNumber = getFibonacciNumber(sequenceNumber);

    cout << "The number in Fibonacci sequence is " << fibonacciNumber << endl;

    return 0;
}