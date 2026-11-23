#include <iostream>
#include <string>
using namespace std;

// Base class
class EmployeeInfo {
protected:
    int empId;
    string name;

public:
    void getInfo() {
        cout << "Enter Employee ID: ";
        cin >> empId;

        cin.ignore();

        cout << "Enter Employee Name: ";
        getline(cin, name);
    }

    void displayInfo() {
        cout << "\nEmployee ID: " << empId;
        cout << "\nName: " << name;
    }
};

// Personal Record class
class PersonalRecord : virtual public EmployeeInfo {
protected:
    int age;
    string gender, address;

public:
    void getPersonal() {
        cout << "Enter Age: ";
        cin >> age;

        cin.ignore();

        cout << "Enter Gender: ";
        getline(cin, gender);

        cout << "Enter Address: ";
        getline(cin, address);
    }

    void displayPersonal() {
        cout << "\nAge: " << age;
        cout << "\nGender: " << gender;
        cout << "\nAddress: " << address;
    }
};

// Professional Record class
class ProfessionalRecord : virtual public EmployeeInfo {
protected:
    string designation, company;
    float salary;

public:
    void getProfessional() {
        cout << "Enter Designation: ";
        getline(cin, designation);

        cout << "Enter Company Name: ";
        getline(cin, company);

        cout << "Enter Salary: ";
        cin >> salary;
    }

    void displayProfessional() {
        cout << "\nDesignation: " << designation;
        cout << "\nCompany: " << company;
        cout << "\nSalary: " << salary;
    }
};

// Academic Record class
class AcademicRecord : virtual public EmployeeInfo {
protected:
    string qualification, university;
    float percentage;

public:
    void getAcademic() {
        cin.ignore();

        cout << "Enter Qualification: ";
        getline(cin, qualification);

        cout << "Enter University: ";
        getline(cin, university);

        cout << "Enter Percentage: ";
        cin >> percentage;
    }

    void displayAcademic() {
        cout << "\nQualification: " << qualification;
        cout << "\nUniversity: " << university;
        cout << "\nPercentage: " << percentage << "%";
    }
};

// Derived class
class Employee : public PersonalRecord,
                 public ProfessionalRecord,
                 public AcademicRecord {
public:
    void acceptData() {
        cout << "\nEnter Employee Details\n";

        getInfo();
        getPersonal();
        getProfessional();
        getAcademic();
    }

    void displayData() {
        cout << "\n\n===== EMPLOYEE BIO-DATA =====";

        displayInfo();
        displayPersonal();
        displayProfessional();
        displayAcademic();

        cout << "\n============================";
    }
};

int main() {
    Employee e;

    e.acceptData();
    e.displayData();

    return 0;
}