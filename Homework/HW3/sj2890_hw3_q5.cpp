#include <iostream>
#include <string>

using namespace std;

int main() {
    const double POUND_TO_KILO = 0.453592;
    const double INCH_TO_METERS = 0.0254;

    int weight, height;
    double weightKilo, heightMeters, bmi;
    string status;

    cout << "Please enter weight (in pounds): ";
    cin >> weight;
    cout << "Please enter height (in inches): ";
    cin >> height;

    weightKilo = weight * POUND_TO_KILO;
    heightMeters = height * INCH_TO_METERS;

    bmi = weightKilo / (heightMeters * heightMeters);

    if (bmi < 18.5) {
        status = "Underweight";
    } else if (bmi >= 18.5 && bmi < 25) {
        status = "Normal";
    } else if (bmi >= 25 && bmi < 30) {
        status = "Overweight";
    } else {
        status = "Obese";
    }

    cout << "The weight status is: " << status;

    return 0;
}
