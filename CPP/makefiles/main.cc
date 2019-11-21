#include <iostream>
#include "./a.hh"

int main() {
    A a = A();
    a.a = 10;
    a.add();
    std::cout << a.a << std::endl;
    return 0;
}