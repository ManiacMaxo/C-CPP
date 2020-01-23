#include <iostream>
#include <string>
#include <vector>
#include "account.hh"
using namespace std;

class User {
    string name;
    string pswd;
    vector<Debit> debitAccounts;
    vector<Credit> creditAccounts;

   public:
    void getAccounts() {
        for (auto i = debitAccounts.begin(); i != debitAccounts.end(); i++) {
            i->getAccount();
        }
        for (auto i = creditAccounts.begin(); i != creditAccounts.end(); i++) {
            i->getCredit();
        }
    }
};

int main() {}
