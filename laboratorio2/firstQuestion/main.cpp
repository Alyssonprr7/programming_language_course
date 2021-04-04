//
// Created by calindra on 04/04/2021.
//

#include <iostream>
#include "Parallelepiped.h"

using namespace std;

int main () {
    int widht, length, height;

    cout << "Insert width dimension" << endl;
    cin >> widht;

    cout << "Insert height dimension" << endl;
    cin >> height;

    cout << "Insert lenght dimension" << endl;
    cin >> length;

    Parallelepiped parallelepiped(widht, height, length);

    cout << "The volum is: " << parallelepiped.getVolum() << endl;

    return 0;
}