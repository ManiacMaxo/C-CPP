#include "account.hh"

void Transaction::getTransaction() {
    cout << "Amount: " << this->amount << endl;
    cout << "Destination: " << this->destination << endl;
}
void Transaction::setTransaction(unsigned int amount, string IBAN) {
    this->amount = amount;
    this->destination = IBAN;
}
void Transaction::setTransaction(unsigned int amount) {
    this->amount = amount;
    this->destination = "withdraw";
}

void Account::getAccount() {
    cout << "IBAN: " << this->IBAN << endl;
    cout << "Amount: " << this->money << endl;
}

void Debit::withdraw(unsigned int amount) {
    if (this->money - amount >= 0) {
        this->money -= amount;
    } else {
        throw insufficientFunds;
    }
}

void Debit::deposit(unsigned int amount) { this->money += amount; }

void Credit::withdraw(unsigned int amount) {
    if (this->money == 0) {
        int withdrawAmount = amount + 1 / 20 * (amount);
        if (intoLimit + withdrawAmount > limit) {
            throw insufficientFunds;
        }
        this->intoLimit += withdrawAmount;
    } else if (this->money - amount < 0) {
        amount -= this->money;
        this->money = 0;
        int withdrawAmount = amount + 1 / 20 * (amount);
        if (intoLimit + withdrawAmount > limit) {
            throw insufficientFunds;
        }
        this->intoLimit += withdrawAmount;
    }
}

void Credit::deposit(unsigned int amount) {
    if (this->intoLimit == 0) {
        this->money += amount;
    } else if (this->intoLimit - amount > 0) {
        this->intoLimit -= amount;
    } else {
        amount -= this->intoLimit;
        this->intoLimit = 0;
        this->money += amount;
    }
}

void Credit::getCredit() {
    getAccount();
    cout << "Limit: " << this->limit << endl;
    cout << "Into Limit: " << this->intoLimit << endl;
}

int main() {}
