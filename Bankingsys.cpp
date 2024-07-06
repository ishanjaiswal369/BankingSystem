#include <iostream>
#include <unordered_map>
using namespace std;

class Customer {
public:
    string name;
    int accountNumber;
    double balance;

    Customer(string name, int accountNumber, double balance) {
        this->name = name;
        this->accountNumber = accountNumber;
        this->balance = balance;
    }

    void displayDetails() {
        cout << "Name: " << name << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
    }
};

class Bank {
private:
    unordered_map<int, Customer*> accounts;
    int nextAccountNumber;

public:
    Bank() {
        nextAccountNumber = 1;
    }

    int createAccount(string name, double initialDeposit) {
        Customer* newCustomer = new Customer(name, nextAccountNumber, initialDeposit);
        accounts[nextAccountNumber] = newCustomer;
        return nextAccountNumber++;
    }

    void deposit(int accountNumber, double amount) {
        if (accounts.find(accountNumber) != accounts.end()) {
            accounts[accountNumber]->balance += amount;
            cout << "Deposited $" << amount << " to account number " << accountNumber << "." << endl;
        } else {
            cout << "Account number " << accountNumber << " not found." << endl;
        }
    }

    void withdraw(int accountNumber, double amount) {
        if (accounts.find(accountNumber) != accounts.end()) {
            if (accounts[accountNumber]->balance >= amount) {
                accounts[accountNumber]->balance -= amount;
                cout << "Withdrew $" << amount << " from account number " << accountNumber << "." << endl;
            } else {
                cout << "Insufficient balance." << endl;
            }
        } else {
            cout << "Account number " << accountNumber << " not found." << endl;
        }
    }

    void displayAccountDetails(int accountNumber) {
        if (accounts.find(accountNumber) != accounts.end()) {
            accounts[accountNumber]->displayDetails();
        } else {
            cout << "Account number " << accountNumber << " not found." << endl;
        }
    }
};

int main() {
    Bank bank;

    int account1 = bank.createAccount("Alice", 500.0);
    int account2 = bank.createAccount("Bob", 1000.0);

    // Performing operations
    bank.deposit(account1, 200.0);
    bank.withdraw(account2, 300.0);

    bank.displayAccountDetails(account1);
    bank.displayAccountDetails(account2);

    return 0;
}
