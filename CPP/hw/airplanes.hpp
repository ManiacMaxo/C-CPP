#include <string>

class Airplane {
   public:
    unsigned int size;
    unsigned int flight_num;
    bool military;
    std::string model;
    double speed;
    double fuel;
    double fuel_efficiency;
    double x;
};

class PassengerPlane : Airplane {
   public:
    int passengers;
    int seats;
    int exits;
};

class CargoPlane : Airplane {
   public:
    double weight;
    double max_weight;
};

class MilitaryPlane {
   public:
    double power;
};
