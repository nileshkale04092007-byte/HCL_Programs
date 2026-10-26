#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    double balance;

public:
    BankAccount(int accNo, double initialBalance) {
        accountNumber = accNo;
        balance = initialBalance;
        cout << "Account " << accountNumber << " Created with balance: " << balance << endl;
    }

    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Deposit amount must be positive!" << endl;
            return;
        }
        balance += amount;
        cout << "Deposited: " << amount << " | New Balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Withdrawal amount must be positive!" << endl;
            return;
        }
        if (amount > balance) {
            cout << "ERROR: Insufficient balance! Cannot withdraw " 
                 << amount << " (Available: " << balance << ")" << endl;
        } else {
            balance -= amount;
            cout << "Withdrawn: " << amount << " | Remaining Balance: " << balance << endl;
        }
    }

    void display() const {
        cout << "\n--- Account Details ---\n"
             << "Account No: " << accountNumber << "\n"
             << "Balance: " << balance << endl;
    }
};

int main() {
    BankAccount acc1(1001, 5000.0);
    
    acc1.display();
    acc1.deposit(2000);
    acc1.withdraw(1000);
    acc1.withdraw(8000); // ye fail hoga
    acc1.display();

    return 0;
}