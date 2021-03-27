
//
// Created by Alysson on 27/03/2021.
//


#include <iostream>
#include <iomanip> //To manipulate numbers
#include <string>

using namespace std;

class GradeBook {
    private:
        string className;

    public:
        void displayMessage() {
            cout << "Welcome to your first project with C++ in your class from " << getClassName() << "!" << endl;
        };

        float sumGrade(float firstGrade, float secondGrade ) {
            return firstGrade + secondGrade;
        };

    const string &getClassName() const {
        return className;
    }

    void setClassName(const string &className) {
        GradeBook::className = className;
    }
};

int main() {
    float firstGrade = 7.5, segundGrade = 9;
    string className;

    GradeBook instanceOfGradeBook;

    cout << "Type your class name ";
    getline(cin, className); //Melhor para ler strings => Vem da biblioteca string
    instanceOfGradeBook.setClassName(className);
    instanceOfGradeBook.displayMessage();

    cout << "The sum is " << setprecision(3) <<  instanceOfGradeBook.sumGrade(firstGrade,segundGrade) << endl;

    return 0;
}
