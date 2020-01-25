#include "order.hh"
using namespace std;

class UserExists : exception {};
class OrderExists : exception {};
class OrderDoesntExist : exception {};

class Shop {
    vector<User const*> users;
    vector<Order const*> orders;
    map<Tech, int> techMap;
    map<Clothing, int> clothingMap;

   public:
    bool userExists(unsigned int id);
    void addUser(User const& user);
    void addItem(Tech item);
    void addItem(Clothing item);
    bool orderExists(unsigned int id);
    void createOrder(Order const& order);
    pair<double, unsigned int> acceptOrder(unsigned int orderID);
    void sendOrder(unsigned int orderID);
    vector<Order const*> getOrdersByUser(unsigned int userID);
    vector<Order const*> getOrdersBySupplier(Supplier const& supplier);
};
