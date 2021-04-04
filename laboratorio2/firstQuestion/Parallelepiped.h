//
// Created by calindra on 04/04/2021.
//

#ifndef LABORATORIO2_PARALLELEPIPED_H
#define LABORATORIO2_PARALLELEPIPED_H


class Parallelepiped {

    public:
        Parallelepiped(int width, int height, int length);
        int getVolum();
        void setWidth(int width);
        void setHeight(int height);
        void setLength(int length);



    private:
        int width, height, length, volum;
        int computeVolum();
        int checkValue(int value);

};


#endif //LABORATORIO2_PARALLELEPIPED_H
