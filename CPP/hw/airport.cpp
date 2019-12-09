#include <iostream>
using namespace std;

class Airplane {
    int size;
    char flag;
    float speed;
    float fuel_capacity;
    float fuel_economy;
    float X;
    // оператор << който извежда всичката информация за самолета
   public:
    Airplane operator<<(Airplane plane) {
        cout << "size: " << size << endl;
        cout << "flag: " << flag << endl;
        cout << "speed: " << speed << endl;
    }
};

int main() {}