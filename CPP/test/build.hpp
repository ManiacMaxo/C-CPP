#include <string>
#include <vector>
#include "supplier.hpp"
using namespace std;

class Base {
   protected:
    string name;
    double price;

   public:
    string get_name() { return name; }
    double get_price() { return price; }
};

class Solids : Base {
    int quantity;

   public:
    int get_quantity() { return quantity; }
};

class Liquids : Base {
    double volume;

   public:
    double get_volume() { return volume; }
};

class Build {
    vector<Solids> solids;
    vector<Liquids> liquids;
    vector<Receipt> receipt;

    public:
    vector<Receipt> get_receipts() { return receipt; }
};
