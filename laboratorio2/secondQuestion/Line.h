//
// Created by calindra on 04/04/2021.
//

#ifndef LABORATORIO2_LINE_H
#define LABORATORIO2_LINE_H

#include "Dot.h"

class Line {
    private:
        Dot firstDot, secondDot;
    public:
        Line(Dot firstDot, Dot secondDot);
        void setFirstDot(Dot newDot);
        void setSecondDot(Dot newDot);
        double getLength();

};


#endif //LABORATORIO2_LINE_H
