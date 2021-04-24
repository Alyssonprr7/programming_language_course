//
// Created by calindra on 23/04/2021.
//

#ifndef LABORATORIO5_EDGE_H
#define LABORATORIO5_EDGE_H


#include "vertex.h"

class Edge {
    private:
        Vertex *firstVertexPtr, *secondVertexPtr;
        double weight;

    public:
        Edge(Vertex *first, Vertex *second, double newWeight = 1.0);
        Vertex *getFirstVertex();
        Vertex *getSecondVertex();
        double getweight();



};


#endif //LABORATORIO5_EDGE_H
