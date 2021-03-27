//
// Created by calindra on 27/03/2021.
//

#include <iostream>

int main() {
    int firstNumber;
    int secondNumber;
    int sum;

    std::cout << "Please, insert the first number: ";
    std::cin >> firstNumber;

    std::cout << "Please, insert the second number: ";
    std::cin >> secondNumber;

    sum = firstNumber + secondNumber;

    std::cout << "The sum is: " << sum << std::endl;

    return 0;

};
