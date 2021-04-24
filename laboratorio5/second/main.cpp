//
// Created by calindra on 23/04/2021.
//

#include "vertex.h"
#include "edge.h"
#include "path.h"
#include <iostream>

using namespace std;
int main(){

    Vertex vertex1 ("A"), vertex2 ("B"), vertex3 ("C"), vertex4 ("D"), vertex5 ("E");
    Edge edge1 (&vertex1, &vertex2), edge2 (&vertex2, &vertex3, 2.5), edge3 (&vertex3, &vertex4, 1.5), edgeerr (&vertex5, &vertex3);

    Path path;
    path.insertEdge(&edge1);
    path.insertEdge(&edge2);
    path.insertEdge(&edge3);
// Tenta inserir um enlace que não dá continuidade ao path
    path.insertEdge(&edgeerr);
// Imprime o path e o peso correspondente
    cout << endl;
    path.printPath();
    return 0;
}