//
// Created by calindra on 04/04/2021.
//

#ifndef LABORATORIO2_DOT_H
#define LABORATORIO2_DOT_H


class Dot {
    private:
        double x, y, z;

    public:
        Dot(double x = 1, double y = 1, double z = 1);
        void setX(double x);
        void setY(double y);
        void setZ(double z);

        double getX();
        double getY();
        double getZ();
};


#endif //LABORATORIO2_DOT_H
