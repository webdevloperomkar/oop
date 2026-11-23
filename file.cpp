#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string name;
    int age, rollNo;

    // Open file in write mode
    ofstream fout("student.txt");

    if (fout.is_open()) {
        cout << "Enter Student Name: ";
        getline(cin, name);

        cout << "Enter Age: ";
        cin >> age;

        cout << "Enter Roll Number: ";
        cin >> rollNo;

        // Write data into file
        fout << "Student Details" << endl;
        fout << "Name: " << name << endl;
        fout << "Age: " << age << endl;
        fout << "Roll Number: " << rollNo << endl;

        fout.close();

        cout << "\nData written successfully!" << endl;
    }
    else {
        cout << "Error: File cannot be opened for writing!";
        return 1;
    }

    // Open file in read mode
    ifstream fin("student.txt");

    if (fin.is_open()) {
        string line;

        cout << "\nStudent Details:\n";

        while (getline(fin, line)) {
            cout << line << endl;
        }

        fin.close();
    }
    else {
        cout << "Error: File cannot be opened for reading!";
        return 1;
    }

    return 0;
}