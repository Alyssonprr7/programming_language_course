//
// Created by calindra on 04/04/2021.
//

#include "Parallelepiped.h"
#include <iostream>

using namespace std;

Parallelepiped::Parallelepiped(int width, int height , int length){
    setWidth(width);
    setHeight(height);
    setLength(length);

}

void Parallelepiped::setWidth(int newWidth) {
    width = checkValue(newWidth);
}

void Parallelepiped::setHeight(int newHeigth){
    height = checkValue(newHeigth);

}

void Parallelepiped::setLength(int newLength){
    length = checkValue(newLength);
}

int Parallelepiped::computeVolum() {
    volum = width * height * length;
    return volum;
}

int Parallelepiped::getVolum(){
    return computeVolum();
}

int Parallelepiped::checkValue(int value) {
    int defaulValue = 1;
    if(value<=0){
        cout << "The value " << value << " is invalid because is less than 0. It's replaced by " << defaulValue << endl;
        return defaulValue;

    } else {
        return value;
    }
}