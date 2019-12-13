#ifndef RECEIPT_HPP
#define RECEIPT_HPP

#include <string>
#include <vector>
#include "materials.hpp"
using namespace std;

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

#endif
