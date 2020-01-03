#include <string>

class Airplane {
   protected:
    unsigned int size;
    unsigned int flight_num;
    bool military;
    std::string model;
    double speed;
    double fuel;
    double fuel_efficiency;
    double x;

   public:
    unsigned int get_size() { return size; }
    unsigned int get_flight_num() { return flight_num; }
    bool get_military() { return military; }
    std::string get_model() { return model; }
    double get_speed() { return speed; }
    double get_fuel() { return fuel; }
    double get_fuel_efficiency() { return fuel_efficiency; }
    double get_x() { return x; }
};

class PassengerPlane : Airplane {
    int passengers;
    int seats;
    int exits;
};

class CargoPlane : Airplane {
    double weight;
    double max_weight;
};

class MilitaryPlane {
    double power;
};
