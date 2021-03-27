//
// Created by Alysson on 27/03/2021.
//
#include <iostream>

using namespace std;

int main() {
    int firstNumber;
    int secondNumber;
    int sum;

    do{
        cout << "Please, insert the two positives numbers: ";
        cin >> firstNumber >> secondNumber;
    } while(firstNumber< 0 || secondNumber<0);

    if(firstNumber == secondNumber){
        sum = 2*firstNumber;
    } else{
        sum = firstNumber + secondNumber;
    }

    cout << "The sum is: " << sum << endl;

    return 0;
}

