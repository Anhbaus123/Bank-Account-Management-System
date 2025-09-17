//Student: Nguyen Van
//ID: 24110146
//Object: Bank Account Management System
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ======================= CLASS TRANSACTION =======================
class Transaction {
private:
    string type;   // deposit / withdraw / transfer
    double amount; 
    string date;   // ngày giao dịch 

public:
    Transaction(string t, double a, string d) {
        type = t;
        amount = a;
        date = d;
    }

    string getInfo() {
        return type + ": " + to_string(amount) + " on " + date;
    }
};

// ======================= CLASS ACCOUNT (BASE) =======================
class Account {
protected:
    string AccountNumber;
    string OwnerName;
    double balance;
    vector<string> TransactionHistory;

public:
    Account(string accNum, string name, double bal) {
        AccountNumber = accNum;
        OwnerName = name;
        balance = bal;
    }

    // Getter
    string getAccountNumber() { return AccountNumber; }
    string getOwnerName() { return OwnerName; }
    double getBalance() { return balance; }

    // Nạp tiền
    virtual void deposit(double amount) {
        balance += amount;
        TransactionHistory.push_back("Deposited: " + to_string(amount));
        cout << "Deposited " << amount << ". New balance: " << balance << endl;
    }

    // Rút tiền
    virtual void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds. Current balance: " << balance << endl;
        } else {
            balance -= amount;
            TransactionHistory.push_back("Withdrew: " + to_string(amount));
            cout << "Withdrew " << amount << ". New balance: " << balance << endl;
        }
    }

    // Hiển thị thông tin
    virtual void displayInfo() {
        cout << "Account Number: " << AccountNumber << endl;
        cout << "Owner Name: " << OwnerName << endl;
        cout << "Balance: " << balance << endl;
        cout << "Transaction History:" << endl;
        for (int i = 0; i < TransactionHistory.size(); i++) {
            cout << "- " << TransactionHistory[i] << endl;
        }
        cout << "---------------------" << endl;
    }

    // Operator overloading: so sánh số dư
    bool operator==(Account &other) {
        return this->balance == other.balance;
    }

    // Operator overloading: nạp tiền (+=)
    Account& operator+=(double amount) {
        this->deposit(amount);
        return *this;
    }
};

// ======================= CLASS SAVINGS ACCOUNT (DERIVED) =======================
class SavingsAccount : public Account {
private:
    double interestRate; // lãi suất %

public:
    SavingsAccount(string accNum, string name, double bal, double rate)
        : Account(accNum, name, bal) {
        interestRate = rate;
    }

    // Override withdraw
    void withdraw(double amount) override {
        if (amount > balance * 0.5) {
            cout << "Savings Account cannot withdraw more than 50% of balance!" << endl;
        } else {
            Account::withdraw(amount);
        }
    }

    // Áp dụng lãi suất
    void applyInterest() {
        double interest = balance * interestRate;
        balance += interest;
        TransactionHistory.push_back("Interest added: " + to_string(interest));
        cout << "Applied interest: " << interest << ". New balance: " << balance << endl;
    }
};

// ======================= CLASS CUSTOMER =======================
class Customer {
private:
    string name;
    string ID;
    vector<Account*> accounts; // Danh sách tài khoản (Account* để chứa cả Account và SavingsAccount)

public:
    Customer(string n, string i) {
        name = n;
        ID = i;
    }

    void addAccount(Account* acc) {
        accounts.push_back(acc);
        cout << "Added account " << acc->getAccountNumber() 
             << " to customer: " << name << endl;
    }

    void displayCustomerInfo() {
        cout << "===== Customer Info =====" << endl;
        cout << "Customer: " << name << " (ID: " << ID << ")" << endl;
        cout << "Accounts: " << endl;
        for (int i = 0; i < accounts.size(); i++) {
            accounts[i]->displayInfo();
        }
    }
};

// ======================= MAIN =======================
int main() {
    // Tạo khách hàng
    Customer c1("John Doe", "C001");

    // Tạo tài khoản thường
    Account* acc1 = new Account("123456", "John Doe", 1000.0);
    c1.addAccount(acc1);

    // Tạo tài khoản tiết kiệm
    SavingsAccount* acc2 = new SavingsAccount("654321", "John Doe", 2000.0, 0.05);
    c1.addAccount(acc2);

    // Giao dịch
    *acc1 += 500;         // nạp tiền bằng toán tử +=
    acc1->withdraw(200);

    *acc2 += 300;
    acc2->withdraw(2000); // vi phạm quy tắc (hơn 50%)
    acc2->applyInterest();

    // So sánh số dư
    if (*acc1 == *acc2) {
        cout << "acc1 và acc2 có số dư bằng nhau!" << endl;
    } else {
        cout << "acc1 và acc2 có số dư khác nhau!" << endl;
    }

    // Hiển thị thông tin khách hàng
    c1.displayCustomerInfo();

    // Giải phóng bộ nhớ
    delete acc1;
    delete acc2;

    return 0;
}
