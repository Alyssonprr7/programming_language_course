//
// Created by calindra on 04/04/2021.
//

#include <iostream>
#include "Dot.h"
#include "Line.h"
#include <iomanip>

using namespace std;

void printCoordinates(Dot dot);

int main() {
    int times = 0;
    Dot firstDot(1.0, 2.0, 1.0);
    Dot secondDot(2.0, 3.0, 2.0);

    Line line(firstDot, secondDot);

    cout << "The length is " << fixed << line.getLength() << endl;

    while(times<4){
        printCoordinates(firstDot);
        times++;
    }



    return 0;
}

void printCoordinates(Dot dot){
    static int impressionNumber;
    impressionNumber ++;
    cout << "[Impressao no.  " << impressionNumber<< "] : Coordinates of p (" << setprecision(3) << dot.getX() <<"," << setprecision(3) << dot.getY() << "," << setprecision(3) << dot.getZ() << ")" << endl;
}