//
// Created by calindra on 04/04/2021.
//

#include "Dot.h"

Dot::Dot(double x, double y, double z) {
    setX(x);
    setY(y);
    setZ(z);

}

void Dot::setX(double newX) {
    x = newX;
}

void Dot::setY(double newY) {
    y = newY;
}

void Dot::setZ(double newZ) {
    z = newZ;
}

double Dot::getX() {
    return x;
}

double Dot::getY() {
    return y;
}

double Dot::getZ() {
    return z;
}