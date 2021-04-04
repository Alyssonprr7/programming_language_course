//
// Created by calindra on 04/04/2021.
//

#include "Line.h"
#include <cmath>

Line::Line(Dot firstDot, Dot secondDot){
    setFirstDot(firstDot);
    setSecondDot(secondDot);
}

void Line::setFirstDot(Dot newDot) {
    firstDot = newDot;
}

void Line::setSecondDot(Dot newDot) {
    secondDot = newDot;
}

double Line::getLength() {
    return sqrt(
            pow((secondDot.getX() - firstDot.getX()), 2.0) +
            pow((secondDot.getY() - firstDot.getY()), 2.0) +
            pow((secondDot.getZ() - firstDot.getZ()), 2.0)
            );
}