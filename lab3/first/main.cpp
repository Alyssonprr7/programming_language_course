#include <iostream>
#include "agenda.h"
#include <string>

using namespace std;
int main() {
    Agenda agenda;
    string name;

    cout  << "Insert 3 names" << endl;
    for (int i = 0; i < 3; i++){
        cout << "Name[" << i + 1 << "]" << endl;
        getline(cin, name);
        agenda.setNames(name);
    }

    agenda.printNames();

    return 0;
}
