#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    int graduationYear, currentYear;

    cout << "Please enter your name: ";
    cin >> name;
    cout << "Please enter your graduation year: ";
    cin >> graduationYear;
    cout << "Please enter current year: ";
    cin >> currentYear;

    int year = graduationYear - currentYear;
    switch (year)
    {
        case 4:
            cout << name << ", you are a Freshman" << endl;
            break;
        case 3:
            cout << name << ", you are a Sophomore" << endl;
            break;
        case 2:
            cout << name << ", you are a Junior" << endl;
            break;
        case 1:
            cout << name << ", you are a Senior" << endl;
            break;
        default:
            if(year > 4) {
                cout << name << ", you are not in college yet" << endl;
            }
            if(year <= 0) {
                cout << name << ", you are Graduated" << endl;
                break;
            }
    }
    return 0;
}
