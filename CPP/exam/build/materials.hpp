#ifndef MATERIALS_HPP
#define MATERIALS_HPP

#include <iostream>
#include <string>
using namespace std;

class Base {
   protected:
    string name;
    double price;

   public:
    string get_name() { return name; }
    double get_price() { return price; }
};

class Solids : public Base {
    int quantity;

   public:
    int get_quantity() { return quantity; }
};

class Liquids : public Base {
    double volume;

   public:
    double get_volume() { return volume; }
};

#endif
