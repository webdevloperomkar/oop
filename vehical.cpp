#include <iostream>
#include <string>
using namespace std;

// Abstract base class
class Vehicle {
protected:
    string vno;
    string brand;
    double rent;

public:
    Vehicle(string num, string b, double rentv) {
        vno = num;
        brand = b;
        rent = rentv;
    }

    virtual void displayDetails() = 0;
    virtual double calculateRent(int days) = 0;

    virtual ~Vehicle() {
        cout << "Vehicle destructor called." << endl;
    }
};

// Car class
class Car : public Vehicle {
    int VCapacity;

public:
    Car(string num, string b, double rent, int seats)
        : Vehicle(num, b, rent) {
        VCapacity = seats;
    }

    void displayDetails() override {
        cout << "\n--- Car Details ---" << endl;
        cout << "Vehicle Number : " << vno << endl;
        cout << "Brand : " << brand << endl;
        cout << "Rent per Day : Rs. " << rent << endl;
        cout << "Seating Capacity: " << VCapacity << endl;
    }

    double calculateRent(int days) override {
        return rent * days;
    }

    ~Car() {
        cout << "Car destructor called." << endl;
    }
};

// Bike class
class Bike : public Vehicle {
    string bikeType;

public:
    Bike(string num, string b, double rent, string type)
        : Vehicle(num, b, rent) {
        bikeType = type;
    }

    void displayDetails() override {
        cout << "\n--- Bike Details ---" << endl;
        cout << "Vehicle Number : " << vno << endl;
        cout << "Brand : " << brand << endl;
        cout << "Rent per Day : Rs. " << rent << endl;
        cout << "Bike Type : " << bikeType << endl;
    }

    double calculateRent(int days) override {
        return rent * days;
    }

    ~Bike() {
        cout << "Bike destructor called." << endl;
    }
};

// Truck class
class Truck : public Vehicle {
    double loadCapacity;

public:
    Truck(string num, string b, double rent, double load)
        : Vehicle(num, b, rent) {
        loadCapacity = load;
    }

    void displayDetails() override {
        cout << "\n--- Truck Details ---" << endl;
        cout << "Vehicle Number : " << vno << endl;
        cout << "Brand : " << brand << endl;
        cout << "Rent per Day : Rs. " << rent << endl;
        cout << "Load Capacity : " << loadCapacity << " tons" << endl;
    }

    double calculateRent(int days) override {
        return rent * days;
    }

    ~Truck() {
        cout << "Truck destructor called." << endl;
    }
};

int main() {
    int days;

    cout << "===== VEHICLE RENTAL SYSTEM =====" << endl;
    cout << "\nEnter rental duration (in days): ";
    cin >> days;

    if (days <= 0) {
        cout << "Invalid rental duration." << endl;
        return 0;
    }

    Vehicle *v1 = new Car("MH12AB1234", "Honda City", 2500, 5);
    Vehicle *v2 = new Bike("MH12XY5678", "Royal Enfield", 1000, "Cruiser");
    Vehicle *v3 = new Truck("MH12TR9012", "Tata", 5000, 10);

    // Runtime polymorphism
    v1->displayDetails();
    cout << "Total Rent for " << days << " days: Rs. "
         << v1->calculateRent(days) << endl;

    v2->displayDetails();
    cout << "Total Rent for " << days << " days: Rs. "
         << v2->calculateRent(days) << endl;

    v3->displayDetails();
    cout << "Total Rent for " << days << " days: Rs. "
         << v3->calculateRent(days) << endl;

    // Deallocation
    delete v1;
    delete v2;
    delete v3;

    cout << "\nAll vehicle objects deleted successfully." << endl;

    return 0;
}