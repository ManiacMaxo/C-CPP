#include <map>
#include <string>
#include <vector>
#include "article.hh"
#include "user.hh"
using namespace std;

class NotAvailable : exception {};

class Order {
    unsigned int id;
    User user;
    map<Tech, int> techMap;
    map<Clothing, int> clothingMap;
    string status[3] = {"New", "In Progress", "Shipped"};
    int statusID;

   public:
    Order(User user);
    // Getters and setters
    int getId() const;
    void setId(int id);
    User getUser() const;
    void setUser(User user);
    string getStatus() const;
    void setStatus(int num);
    // functionality
    void addItem(Tech item);
    void addItem(Clothing item);
};
