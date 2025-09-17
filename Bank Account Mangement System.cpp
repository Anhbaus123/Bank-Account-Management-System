#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Account 
{
    protected:
    string AccountNumber; // Số tài khoản
    string OwnName; // Tên chủ tài khoản
    vector <string> TransactionHistory; // Lịch sử giao dịch
    double balance; // Số dư tài khoản
    public:
    Account(string accNum, string name, double bal)
    {
        AccountNumber = accNum;
        OwnName = name;
        balance = bal;
    }
    // Setter
    void setAccountNumber(string accNum) { AccountNumber = accNum; }
    void setOwnName(string name) { OwnName = name; }
    void setBalance(double bal) { balance = bal; }
    // Getter
    string getAccountNumber() { return AccountNumber; }
    string getOwnName() { return OwnName; }
    double getBalance() { return balance; }
    void deposit(double amount )
    {
        balance += amount;
        TransactionHistory.push_back("Deposited: " + to_string(amount));
        cout << "Deposited " << amount << ". New balance: " << balance << endl;

    }
    void withdraw(double amount)
    {
        if (amount>balance)
        {
            cout << "Insufficient funds. Current balance: " << balance << endl;
        }
        else
        {
            balance -= amount;
            TransactionHistory.push_back("Withdrew: " + to_string(amount));
            cout << "Withdrew " << amount << ". New balance: " << balance << endl;
        }
    }
    void displayInfo()
    {
        cout << "Account Number: " << AccountNumber << endl;
        cout << "Owner Name: " << OwnName << endl;
        cout << "Balance: " << balance << endl;
        cout << "Transaction History: " << endl;
        for (int i=0; i<TransactionHistory.size(); i++)
        {
            cout << "- " << TransactionHistory[i] << endl;
        }
    }


};

int main()
{
    Account acc("123456", "John Doe", 1000.0);
    acc.displayInfo();
    acc.deposit(500.0);
    acc.withdraw(200.0);
    acc.displayInfo();
    acc.withdraw(2000.0);
    return 0;
}