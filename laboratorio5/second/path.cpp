//
// Created by calindra on 23/04/2021.
//

#include "path.h"

void Path::insertEdge(Edge *edge) {
    if(!edges.size()){
        edges.push_back(edge);
        cout << "Adicionando " << edge->getFirstVertex()->getLabel() << endl;
    } else {
        if( edge->getFirstVertex() == edges[edges.size() - 1]->getSecondVertex()){
            edges.push_back(edge);
            cout << "Adicionando " << edge->getFirstVertex()->getLabel() << endl;
        } else {
            cout << "Não foi possível adicionar o  " << edge->getFirstVertex()->getLabel() << endl;

        }
    }
}

void Path::printPath () {
    cout << "Caminho: ";
    for (unsigned i = 0; i < edges.size(); i++)
        cout << edges.at(i)->getFirstVertex()->getLabel() << " -- ";
    cout << edges.at(edges.size() - 1)->getSecondVertex()->getLabel() << endl;
    cout << "Distância: " << getDistance() << endl;
}

double Path::getDistance() {
    double distance = 0;
    for (size_t i = 0; i < edges.size(); i++) {
        distance += edges[i]->getweight();
    }
    return distance;
}
