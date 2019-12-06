#include <iostream>
using namespace std;

class clientPersonOne {
   public:
    float delivery;
    float distribution;
    float tariffDay;
    float tariffNight;
    float usedPowerDay;
    float usedPowerNight;
    float calcBill() {
        return (delivery + distribution + tariffDay) * usedPowerDay +
               (delivery + distribution + tariffNight) * usedPowerNight;
    }
};

class clientPersonTwo {
   public:
    float delivery;
    float distribution;
    float tariff;
    float usedPower;
    float calcBill() { return (delivery + distribution + tariff) * usedPower; }
};

class clientInstitutionOne : clientPersonOne {
    float highVoltage;
    float calcBill() {
        return (delivery + distribution + tariffDay + highVoltage) * usedPowerDay +
               (delivery + distribution + tariffNight + highVoltage) * usedPowerNight;
    }
};

class clientInstitutionTwo : clientPersonTwo {
    float highVoltage;
    float calcBill() { return (delivery + distribution + tariff + highVoltage) * usedPower; }
};

int main() {}