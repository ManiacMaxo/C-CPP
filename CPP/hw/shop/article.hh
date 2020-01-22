#include <string>
using namespace std;

class Supplier {
    string name;

   public:
    string getName() { return this->name; }
    void setName(string name) { this->name = name; }
};

class Article {
    string name;
    float price;
    bool available;
    Supplier supplier;
    float deliveryTime;

   public:
    string getName();
    void setName(string name);
    float getPrice();
    void setPrice(float price);
    bool isAvailable();
    void setAvailable(bool available);
    Supplier getSupplier();
    void setSupplier(Supplier supplier);
    float getDeliveryTime();
    void setDeliveryTime(float deliveryTime);
};

class Clothing : public Article {
    string color;
    char size;
    string material;

   public:
    string getColor();
    void setColor(string color);
    char getSize();
    void setSize(char size);
    string getMaterial();
    void setMaterial(string material);
};

class Tech : public Article {
    int type;  // 1 - appliance, 2 - others, 3 - consumable
    int warranty;
    float weight;

   public:
    int getType();
    void setType(int type);
    int getWarranty();
    void setWarranty(int warranty);
    float getWeight();
    void setWeight(float weight);
};
