#include <iostream>
#include <vector>
using namespace std;

class Airplane {
   protected:
    int size;
    char flag;
    float speed;
    float fuel_capacity;
    float fuel_economy;
    float X;

   public:
    Airplane operator<<(Airplane plane) {
        cout << "size:\t" << size << endl;
        cout << "flag:\t" << flag << endl;
        cout << "speed:\t" << speed << endl;
        cout << "fuel capacity:\t" << fuel_capacity << endl;
        cout << "fuel economy:\t" << fuel_economy << endl;
        cout << "position:\t" << X << endl;
    }
};

class Passenger : Airplane {
    int seats;
    int passengers;
    int exits;
};

class Military : Airplane {
    float power;
};

class Cargo : Airplane {
    float cargo_capacity;
    float weight;
};

class Airport {
    int num_planes;
    int max_size;
    char flags;
    float X;
    vector<Passenger> passenger_planes;
    vector<Military> military_planes;
    vector<Cargo> cargo_planes;
};

int main() {}