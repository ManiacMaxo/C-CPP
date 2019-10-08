#include <iostream>
using namespace std;

namespace firstSpace {
void say_hello() {
    cout << "Hello from first namespace" << endl;
}
};  // namespace firstSpace

namespace secondSpace {
void say_hello() {
    cout << "Hello from second namespace" << endl;
}
};  // namespace secondSpace

using namespace firstSpace;

int main() {
    say_hello();
}
