//
// Created by calindra on 23/04/2021.
//

#ifndef LABORATORIO5_PATH_H
#define LABORATORIO5_PATH_H

#include <vector>
#include "edge.h"
#include <iostream>

using namespace  std;

class Path {
    private:
        vector<Edge *> edges;
    public:
        void insertEdge(Edge* edge);
        void printPath();
        double getDistance();


};


#endif //LABORATORIO5_PATH_H
