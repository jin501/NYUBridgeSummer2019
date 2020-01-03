#include <iostream>
using namespace std;

const int MINUTES_TO_HOURS = 60;
const int HOURS_TO_DAYS = 24;

int main() {

    int daysJohnWorked, hoursJohnWorked, minutesJohnWorked;
    int daysBillWorked, hoursBillWorked, minutesBillWorked;
    int totalDaysWorked, totalHoursWorked, totalMinutesWorked;
    int hoursRemaining, hoursCarryOver, minutesRemaining, minutesCarryOver;

    // store number of days, hours, minutes John worked
    cout << "Please enter the number of days John has worked: ";
    cin >> daysJohnWorked;
    cout << "Please enter the number of hours John has worked: ";
    cin >> hoursJohnWorked;
    cout << "Please enter the number of minutes John has worked: ";
    cin >> minutesJohnWorked;

    // breakline
    cout << endl;

    // store number of days, hours, mins Bill worked
    cout << "Please enter the number of days Bill has worked: ";
    cin >> daysBillWorked;
    cout << "Please enter the number of hours Bill has worked: ";
    cin >> hoursBillWorked;
    cout << "Please enter the number of minutes Bill has worked: ";
    cin >> minutesBillWorked;

    // breakline
    cout << endl;

    // start with smallest unit of time (mins) and carry over values from there
    totalMinutesWorked = minutesJohnWorked + minutesBillWorked;

    // If total amount of minutes added together is 121 minutes => 2 hours and 1 minute
    minutesRemaining = totalMinutesWorked % MINUTES_TO_HOURS;
    minutesCarryOver = totalMinutesWorked / MINUTES_TO_HOURS; 
    totalHoursWorked = hoursJohnWorked + hoursBillWorked + minutesCarryOver; 
    hoursRemaining = totalHoursWorked % HOURS_TO_DAYS;
    hoursCarryOver = totalHoursWorked / HOURS_TO_DAYS; 
    totalDaysWorked = daysJohnWorked + daysBillWorked + hoursCarryOver;

    cout << "The total time both of them worked together is: " << totalDaysWorked << " days, " << hoursRemaining
         << " hours and " << minutesRemaining << " minutes." << endl;

    return 0;
}