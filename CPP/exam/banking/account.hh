#include <iostream>
#include <string>
using namespace std;

class Transaction {
    int amount;
    string destination;  // IBAN
   public:
    void getTransaction();
    void setTransaction(unsigned int amount, string IBAN);
    void setTransaction(unsigned int amount);
};

class MoneyException : public exception {
} insufficientFunds;

class Account {
   protected:
    string IBAN;
    int money;
    vector<Transaction> transactions;

   public:
    string getIBAN() { return this->IBAN; }
    void getAccount();
};

class Debit : public Account {
   public:
    void withdraw(unsigned int amount);
    void deposit(unsigned int amount);
};

class Credit : public Account {
    int limit;
    int intoLimit;

   public:
    void withdraw(unsigned int amount);
    void deposit(unsigned int amount);
    void getCredit();
};
