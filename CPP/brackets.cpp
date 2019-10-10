#include <iostream>
#include <queue>
using namespace std;

class Brackets {
   private:
    int opening;
    int closing;
    int balanced;
    char *string;

   public:
    Brackets();
    void read();
};

Brackets::Brackets() {
    queue<char> opening;
    queue<char> closing;
}

void Brackets::read() {
    char *string;
    cout << "Enter a string: " << endl;
    cin >> this->string;
}

int main() {
}
