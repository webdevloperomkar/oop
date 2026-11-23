#include <iostream>
#include <string>
using namespace std;

// User-defined exception class
class EligibilityException {
public:
    string message;

    EligibilityException(string msg) {
        message = msg;
    }
};

int main() {
    int age;
    double income;
    string city;
    char vehicle;

    cout << "Enter your age: ";
    cin >> age;

    cout << "Enter monthly income: ";
    cin >> income;

    cout << "Enter your city: ";
    cin >> city;

    cout << "Do you own a four-wheeler? (Y/N): ";
    cin >> vehicle;

    try {
        if (age < 18 || age > 55)
            throw EligibilityException(
                "Age must be between 18 and 55 years.");

        if (income < 50000 || income > 100000)
            throw EligibilityException(
                "Income must be between Rs. 50,000 and Rs. 1,00,000.");

        if (city != "Pune" && city != "Mumbai" &&
            city != "Bangalore" && city != "Chennai")
            throw EligibilityException("City is not eligible.");

        if (vehicle != 'Y' && vehicle != 'y')
            throw EligibilityException(
                "You must own a four-wheeler.");

        cout << "\nCongratulations! You are eligible." << endl;
    }
    catch (EligibilityException e) {
        cout << "\nEligibility Error: " << e.message << endl;
    }

    return 0;
}