#include "order.hh"

int orderIdCounter = 0;

int Order::getId() const { return this->id; }
void Order::setId(int id) { this->id = id; }
User Order::getUser() const { return this->user; }
void Order::setUser(User user) { this->user = user; }
string Order::getStatus() const { return this->status[statusID]; }
void Order::setStatus(int num) { this->statusID = num; }

Order::Order(User user) {
    this->user = user;
    id = orderIdCounter++;
    statusID = 0;
}

void Order::addItem(Tech item) {
    if (!item.isAvailable()) {
        throw NotAvailable();
    }
    if (techMap.at(item) > 0) {
        techMap.at(item)++;
    } else {
        techMap.insert(pair<Tech, int>(item, 1));
    }
}

void Order::addItem(Clothing item) {
    if (!item.isAvailable()) {
        throw NotAvailable();
    }
    if (clothingMap.at(item) > 0) {
        clothingMap.at(item)++;
    } else {
        clothingMap.insert(pair<Clothing, int>(item, 1));
    }
}
