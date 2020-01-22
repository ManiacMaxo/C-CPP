#include <map>
#include <string>
#include <vector>
#include "article.hh"
#include "user.hh"
using namespace std;

class NotAvailable : public exception {
} AvailableExeption;

class Order {
    int id;
    User user;
    vector<Tech> techItems;
    vector<Clothing> clothingItems;
    map<Tech, int> quantityTech;
    map<Clothing, int> quantityClothing;
    int status;

   public:
    int getId();
    void setId(int id);
    User getUser();
    void setUser(User user);
    vector<Tech> getTechItems();
    vector<Clothing> getClothingItems();
    int getStatus();
    void setStatus(int status);
    void addItem(Tech item);
    void addItem(Clothing item);
};
