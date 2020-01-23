#include "user.hh"
using namespace std;

class OnlineBanking {
   public:
    void transaction(Debit a, Debit b, float amount);
    void transaction(Credit a, Credit b, float amount);
    void transaction(Debit a, Credit b, float amount);
    void transaction(Credit a, Debit b, float amount);
};
