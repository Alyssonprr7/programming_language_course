#include <iostream>
#include "stack.h"


using namespace std;
int main() {
    Stack pilha (5);
    int valor = 0;
    while (pilha.push (++valor)) {
        cout << "Valor: " << valor << " inserido" << endl;
    }
    cout << endl;
    while (pilha.pop (valor)) {
        cout << "Valor: " << valor << " removido" << endl;
    }
    return 0;
}
