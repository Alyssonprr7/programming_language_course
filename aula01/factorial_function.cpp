//
// Created by Alysson on 27/03/2021.
//

#include <iostream>
using namespace std;

int factorial(int number) {
    if (number == 1){
        return 1;
    } else {
        return number * factorial(number-1);
    }
};

int main () {
    int number;

    cout << "Please, inset a integer positive number: ";
    cin >> number;

    cout << "Factorial: " << factorial(number) << endl;

    return 0;
}