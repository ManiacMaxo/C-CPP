#include <string>
#include <vector>
#include "build.hpp"
using namespace std;

class Truck {
    bool liquids;  // can carry liquids
    double max_load;

   public:
    Truck(bool is_liquid, double quantity) {
        liquids = is_liquid;
        max_load = quantity;
    }
    bool is_liquids() { return liquids; }
    double get_max_load() { return max_load; }
};

class Receipt {
    vector<Liquids> liquids;
    vector<Solids> solids;
    int days;

   public:
    Receipt(vector<Liquids> liquids, vector<Solids> solids) {
        this->liquids = liquids;
        this->solids = solids;
        days = 0;
    }
    Receipt() { days = 0; }

    vector<Liquids> get_liquids() { return liquids; }
    vector<Solids> get_solids() { return solids; }
    int get_days() { return days; }

    void add_liquid(Liquids liquid) { liquids.push_back(liquid); }
    void add_solid(Solids solid) { solids.push_back(solid); }
    void add_day() { days++; }
};

class Supplier {
    vector<Truck> base_trucks;  // all trucks
    vector<Truck> trucks;       // available trucks

   public:
    vector<Truck> order(string name, double quantity, bool type) {
        // type 1 liquids, type 0 solids
        vector<Truck> order;
        for (int i = 0; i < trucks.size(); i++) {
            if (trucks[i].is_liquids == type) {
                quantity -= trucks[i].get_max_load();
                order.push_back(trucks[i]);
            }

            if (quantity <= 0) {
                break;
            }
        }
        return order;
    }

    void receipt(Build build) {}
};
