#include <iostream>
using namespace std;

class Complex {
public:
    float real, img;

    Complex() {
        real = 0;
        img = 0;
    }

    Complex operator+(Complex obj);
    Complex operator*(Complex obj);

    friend ostream& operator<<(ostream&, const Complex&);
    friend istream& operator>>(istream&, Complex&);
};

// Addition operator
Complex Complex::operator+(Complex obj) {
    Complex temp;

    temp.real = real + obj.real;
    temp.img = img + obj.img;

    return temp;
}

// Multiplication operator
Complex Complex::operator*(Complex obj) {
    Complex temp;

    temp.real = real * obj.real - img * obj.img;
    temp.img = real * obj.img + img * obj.real;

    return temp;
}

// Input operator
istream& operator>>(istream& is, Complex& obj) {
    is >> obj.real >> obj.img;
    return is;
}

// Output operator
ostream& operator<<(ostream& out, const Complex& obj) {
    out << obj.real;

    if (obj.img >= 0)
        out << "+" << obj.img << "i";
    else
        out << obj.img << "i";

    return out;
}

int main() {
    int ch;
    char ans;
    Complex a, b, c, d;

    do {
        cout << "\n\tArithmetic Operations";
        cout << "\n\t1. Addition";
        cout << "\n\t2. Multiplication";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "\n\tAddition";
                cout << "\nEnter first complex number";
                cout << "\nEnter real and imaginary: ";
                cin >> a;

                cout << "Enter second complex number";
                cout << "\nEnter real and imaginary: ";
                cin >> b;

                c = a + b;
                cout << "\nResult: " << c;
                break;

            case 2:
                cout << "\n\tMultiplication";
                cout << "\nEnter first complex number";
                cout << "\nEnter real and imaginary: ";
                cin >> a;

                cout << "Enter second complex number";
                cout << "\nEnter real and imaginary: ";
                cin >> b;

                d = a * b;
                cout << "\nResult: " << d;
                break;

            default:
                cout << "\nInvalid choice!";
        }

        cout << endl;
        cout << "\nDo you want to go to main menu (Y/N): ";
        cin >> ans;

    } while (ans == 'y' || ans == 'Y');

    return 0;
}