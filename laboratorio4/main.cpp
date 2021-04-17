#include <iostream>
#include "agenda.h"

using namespace std;

int main() {
    Agenda agenda(3);

    agenda.addContact("Alysson", "Dev", 21);
    agenda.addContact("Matheus", "Engineer", 26);
    agenda.addContact("Kauã", "Student", 14);

    agenda.showAllContacts();


//    Delete Contact
//    agenda.deleteContact("Alysson");
//    agenda.showAllContacts();
//

// Edit Age
//    agenda.editAge("Alysson", 34);
//    agenda.showAllContacts();
//

// Edit Job
//    agenda.editJob("Alysson", "Student");
//    agenda.showAllContacts();
//

//Write on agenda
    agenda.writeFile();
//

    return 0;
}
