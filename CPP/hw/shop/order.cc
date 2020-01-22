#include "order.hh"

int Order::getId() { return this->id; }
void Order::setId(int id) { this->id = id; }
User Order::getUser() { return this->user; }
void Order::setUser(User user) { this->user = user; }
vector<Tech> Order::getTechItems() { return this->techItems; }
vector<Clothing> Order::getClothingItems() { return this->clothingItems; }
int Order::getStatus() { return this->status; }
void Order::setStatus(int status) { this->status = status; }

void Order::addItem(Tech item) {
    if (!item.isAvailable()) {
        throw AvailableExeption;
    }
    for (auto i = techItems.begin(); i < techItems.end(); i++) {
        if (*i == item) {
            
        }
    }
}
