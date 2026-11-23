#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string accountHolderName;
    double accountBalance;
    string accountType;

    static int totalAccounts;

public:
    // Default constructor
    BankAccount() {
        accountNumber = 0;
        accountHolderName = "Not Available";
        accountBalance = 0.0;
        accountType = "Savings";
        totalAccounts++;
    }

    // Parameterized constructor
    BankAccount(int accNo, string name, double balance, string type) {
        this->accountNumber = accNo;
        this->accountHolderName = name;
        this->accountBalance = balance;
        this->accountType = type;
        totalAccounts++;
    }

    void enterDetails() {
        cout << "\nEnter Account Number: ";
        cin >> accountNumber;

        cout << "Enter Account Holder Name: ";
        cin.ignore();
        getline(cin, accountHolderName);

        cout << "Enter Account Balance: ";
        cin >> accountBalance;

        cout << "Enter Account Type (Savings/Current): ";
        cin >> accountType;
    }

    void displayDetails() {
        cout << "\n-----------------------------------";
        cout << "\nAccount Number : " << accountNumber;
        cout << "\nAccount Holder : " << accountHolderName;
        cout << "\nAccount Balance : Rs. "
             << fixed << setprecision(2) << accountBalance;
        cout << "\nAccount Type : " << accountType;
        cout << "\n-----------------------------------";
    }

    inline double calculateInterest(double rate) {
        return (accountBalance * rate) / 100;
    }

    inline double updatedBalance(double rate) {
        return accountBalance + calculateInterest(rate);
    }

    static void displayTotalAccounts() {
        cout << "\nTotal Number of Accounts Created: "
             << totalAccounts << endl;
    }

    friend void compareBalance(BankAccount, BankAccount);

    ~BankAccount() {
        cout << "\nAccount object destroyed.";
    }
};

// Definition of static data member
int BankAccount::totalAccounts = 0;

// Friend function
void compareBalance(BankAccount acc1, BankAccount acc2) {
    cout << "\n\n========== Balance Comparison ==========";

    if (acc1.accountBalance > acc2.accountBalance) {
        cout << "\nAccount " << acc1.accountNumber
             << " has higher balance.";
    }
    else if (acc2.accountBalance > acc1.accountBalance) {
        cout << "\nAccount " << acc2.accountNumber
             << " has higher balance.";
    }
    else {
        cout << "\nBoth accounts have the same balance.";
    }
}

int main() {
    int n;

    cout << "===== BANK ACCOUNT MANAGEMENT SYSTEM =====\n";
    cout << "\nEnter number of accounts: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of accounts.";
        return 0;
    }

    BankAccount accounts[n];

    // Enter account details
    for (int i = 0; i < n; i++) {
        cout << "\n\nEnter details for Account " << i + 1;
        accounts[i].enterDetails();
    }

    // Display account information
    cout << "\n\n========== ACCOUNT DETAILS ==========";

    for (int i = 0; i < n; i++) {
        accounts[i].displayDetails();
    }

    BankAccount::displayTotalAccounts();

    // Calculate interest for first account
    double rate;

    cout << "\n\nEnter interest rate for Account 1 (%): ";
    cin >> rate;

    cout << "\nInterest Amount: Rs. "
         << accounts[0].calculateInterest(rate);

    cout << "\nUpdated Balance: Rs. "
         << accounts[0].updatedBalance(rate);

    // Compare balances
    if (n >= 2) {
        compareBalance(accounts[0], accounts[1]);
    }
    else {
        cout << "\n\nAt least two accounts are required "
             << "for balance comparison.";
    }

    cout << "\n\n===== END OF PROGRAM =====\n";

    return 0;
}