#include <iostream>
using namespace std;
#define NUM_PRODUCTS 100

class Base {
   public:
    char *name;
    char *producer;
    float price;
    int barcode;
    char *description;
};

class Food : Base {
    char *type;
    char *best_before;
    char *allergents;
    bool is_bds;
};

class Electronics : Base {
    char *type;
    int warranty;        // in months
    char *warranty_tos;  // terms of service
};

class Others : Base {
    char *info;
};

class Product {
    Food food;
    Electronics electronics;
    Others others;
};

class Cart {
    Product products[];

   public:
    auto add_product(char *type) {
    }
    auto remove_product();
};

class Store {
    Product products;

   public:
    auto search();
};

int main() {
    return 0;
}
