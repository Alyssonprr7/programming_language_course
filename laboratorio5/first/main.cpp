#include "clock.h"

int main() {
    Clock nowClock;
    nowClock.printTimes();

    //Correto
    Clock newClock2(10, 20, 33);
    newClock2.printTimes();

    //Hora errada
    Clock newClock3(-23, 20, 33);
    newClock3.printTimes();

    //minutos errada
    Clock newClock4(-23, -20, -13);
    newClock4.printTimes();

    newClock2.resetHour();
    newClock2.printTimes();

    newClock3.resetHour(10,20,33);
    newClock3.printTimes();

    return 0;
}
