#include <iostream>
#include <string>
using namespace std;

class Dog {
    // const string name;
   public:
    int age;

    Dog(string d_name, int d_age) {
        age = d_age;
        const string name = d_name;
    }
};

class Cat {
    // const string name;
   public:
    int age;

    Cat(string c_name, int c_age) {
        age = c_age;
        const string name = c_name;
    }
};

const class Shelter {
   private:
    Shelter() {
    }
};

int main() {
}
