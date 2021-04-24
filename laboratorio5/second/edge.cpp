//
// Created by calindra on 23/04/2021.
//

#include "edge.h"

Edge::Edge(Vertex *first, Vertex *second, double newWeight) {
    firstVertexPtr = first;
    secondVertexPtr = second;
    weight = newWeight;
}

Vertex *Edge::getFirstVertex() {
    return firstVertexPtr;
}

Vertex *Edge::getSecondVertex() {
    return secondVertexPtr;
}

double Edge::getweight() {
    return weight;
}
