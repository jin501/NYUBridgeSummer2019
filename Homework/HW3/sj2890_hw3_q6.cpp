#include <iostream>
#include <string>

using namespace std;

int main() {
    const double WEEKEND_RATE = 0.15;
    const double WEEKDAY_PEAK_RATE = 0.40;
    const double WEEKDAY_OFF_RATE = 0.25;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    string dayOfWeek;
    char colon;
    int callTimeHour, callTimeMinute, lengthOfCall;
    double costOfCall;

    cout << "Please enter day of week: ";
    cin >> dayOfWeek;
    cout << "Enter time call started in 24-hour notation " << endl;
    cin >> callTimeHour >> colon >> callTimeMinute;
    cout << "Enter length of call in minutes: " << endl;
    cin >> lengthOfCall;

    if(dayOfWeek == "Sa" || dayOfWeek == "Su") {
        costOfCall = lengthOfCall * WEEKEND_RATE;
        cout << "Total cost of call is: $" << costOfCall;
    } else if (dayOfWeek == "Mo" || dayOfWeek == "Tu" || dayOfWeek == "Th" || dayOfWeek == "Fr" ){
        if (callTimeHour < 8 || (callTimeHour >= 18 && callTimeMinute > 0)) {
            costOfCall = lengthOfCall * WEEKDAY_OFF_RATE;
            cout << "Total cost of call is: $" << costOfCall;
        } else {
            costOfCall = lengthOfCall * WEEKDAY_PEAK_RATE;
            cout << "Total cost of call is: $" << costOfCall;
        }
    } else {
        cout << "Please enter a valid weekday (Mo Tu We Th Fr Sa Su)";
    }

    return 0;
}
