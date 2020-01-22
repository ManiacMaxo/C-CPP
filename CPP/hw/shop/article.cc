#include "article.hh"

string Article::getName() { return this->name; }
void Article::setName(string name) { this->name = name; }
float Article::getPrice() { return this->price; }
void Article::setPrice(float price) { this->price = price; }
bool Article::isAvailable() { return this->available; }
void Article::setAvailable(bool available) { this->available = available; }
Supplier Article::getSupplier() { return this->supplier; }
void Article::setSupplier(Supplier supplier) { this->supplier = supplier; }
float Article::getDeliveryTime() { return this->deliveryTime; }
void Article::setDeliveryTime(float deliveryTime) {
    this->deliveryTime = deliveryTime;
}

string Clothing::getColor() { return this->color; }
void Clothing::setColor(string color) { this->color = color; }
char Clothing::getSize() { return this->size; }
void Clothing::setSize(char size) { this->size = size; }
string Clothing::getMaterial() { return this->material; }
void Clothing::setMaterial(string material) { this->material = material; }

int Tech::getType() { return this->type; }
void Tech::setType(int type) { this->type = type; }
int Tech::getWarranty() { return this->warranty; }
void Tech::setWarranty(int warranty) { this->warranty = warranty; }
float Tech::getWeight() { return this->weight; }
void Tech::setWeight(float weight) { this->weight = weight; }

bool operator==(Tech a, Tech b) {
    if (a.getName() == b.getName() && a.getType() == b.getType()) {
        return 1;
    }
    return 0;
}

bool operator==(Clothing a, Clothing b) {
    if (a.getName() == b.getName() && a.getColor() == b.getColor() &&
        a.getSize() == b.getSize() && a.getMaterial() == b.getMaterial()) {
        return 1;
    }
    return 0;
}

int main() {}
