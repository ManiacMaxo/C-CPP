#ifndef SUPPLIER_HPP
#define SUPPLIER_HPP

#include <iostream>
#include <string>
#include <vector>
#include "build.hpp"
#include "materials.hpp"
#include "receipt.hpp"
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

class Supplier {
    vector<Truck> base_trucks;  // all trucks
    vector<Truck> trucks;       // available trucks

   public:
    vector<Truck> delivery(string name, double quantity, bool type) {
        // type 1 liquids, type 0 solids
        vector<Truck> delivery;
        for (int i = 0; i < trucks.size(); i++) {
            if (trucks[i].is_liquids() == type) {
                quantity -= trucks[i].get_max_load();
                delivery.push_back(trucks[i]);
            }

            if (quantity <= 0) {
                break;
            }
        }
        return delivery;
    }

    void receipt(Build build) {
        Receipt receipt = build.get_receipt();
        vector<Liquids> liquids = receipt.get_liquids();
        vector<Solids> solids = receipt.get_solids();

        cout << "Liquids:" << endl;
        double quantity = 0;
        double price = 0;
        for (auto i = liquids.begin(); i != liquids.end(); i++) {
            quantity += i->get_volume();
            price += i->get_price();
            cout << "A total of " << quantity << "litres and costs" << price
                 << endl;
        }
        quantity = 0;
        price = 0;
        cout << "Solids:" << endl;
        for (auto i = solids.begin(); i != solids.end(); i++) {
            quantity += i->get_quantity();
            price += i->get_price();
            cout << "A total of " << quantity << "pieces and costs" << price
                 << endl;
        }
    }
};

#endif
