#include <string>
using namespace std;

class User {
    unsigned int id;
    string name;
    string pswd;

   public:
    User(string name, string pswd);
    User();
    int getId() const;
};
