#include "shop.hh"

bool Shop::userExists(unsigned int id) {
    for (auto i = users.begin(); i != users.end(); i++) {
        if ((*i)->getId() == id) {
            return true;
        }
    }
    return false;
}

void Shop::addUser(User const& user) {
    if (userExists(user.getId())) {
        throw UserExists();
    } else {
        this->users.push_back(&user);
    }
}

bool Shop::orderExists(unsigned int id) {
    for (auto i = orders.begin(); i != orders.end(); i++) {
        if ((*i)->getId() == id) {
            return true;
        }
    }
    return false;
}

void Shop::createOrder(Order const& order) {
    if (orderExists(order.getId())) {
        throw OrderExists();
    }
}

void Shop::addItem(Tech item) {
    if (!item.isAvailable()) {
        throw NotAvailable();
    }
    if (techMap.at(item) >= 0) {
        techMap.at(item)++;
    } else {
        techMap.insert(pair<Tech, int>(item, 1));
    }
}

void Shop::addItem(Clothing item) {
    if (!item.isAvailable()) {
        throw NotAvailable();
    }
    if (clothingMap.at(item) >= 0) {
        clothingMap.at(item)++;
    } else {
        clothingMap.insert(pair<Clothing, int>(item, 1));
    }
}

pair<double, unsigned int> Shop::acceptOrder(unsigned int orderID) {
    for (auto i = orders.begin(); i != orders.end(); i++) {
        if ((*i)->getId() == orderID) {
            Order& order = *i;
        } else {
            throw OrderDoesntExist();
        }
    }

    unsigned int time = 0;
    for (auto i = order.techMap.begin(); i != order.techMap.end(); i++) {
        if (i.getTime > time) {
            time = i.getTime();
        }
    }
    for (auto i = order.clothingMap.begin(); i != order.clothingMap.end(); i++) {
        if (i.getTime > time) {
            time = i.getTime();
        }
    }
    double value = 0;
    return pair<double, unsigned int>(value, time);
}

void Shop::sendOrder(unsigned int orderID) {
    for (auto i = orders.begin(); i != orders.end(); i++) {
        if ((*i)->getId() == orderID) {
            Order order = *i;
        } else {
            throw OrderDoesntExist();
        }
    }
}

vector<Order const*> Shop::getOrdersByUser(unsigned int userID) {
    vector<Order const*> userOrders;
    for (auto i = orders.begin(); i != orders.end(); i++) {
        User const temp = (*i)->getUser();
        if (temp.getId() == userID) {
            // userOrders.push_back(&i);
        }
    }
    return userOrders;
}

// vector<Order const*> Shop::getOrdersBySupplier(Supplier const& supplier) {}

int main() {}
