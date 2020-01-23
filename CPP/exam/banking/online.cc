#include "online.hh"

void OnlineBanking::transaction(Debit a, Debit b, float amount) {
    a.withdraw(amount + 1 / 10 * amount);
    b.deposit(amount);
}

void OnlineBanking::transaction(Credit a, Credit b, float amount) {
    a.withdraw(amount + 1 / 10 * amount);
    b.deposit(amount);
}

void OnlineBanking::transaction(Debit a, Credit b, float amount) {
    a.withdraw(amount + 1 / 10 * amount);
    b.deposit(amount);
}

void OnlineBanking::transaction(Credit a, Debit b, float amount) {
    a.withdraw(amount + 1 / 10 * amount);
    b.deposit(amount);
}
