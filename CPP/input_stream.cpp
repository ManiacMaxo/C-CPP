#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string test = "3.141592 4k";

    istringstream in(test);

    double pi;
    in >> pi;

    if (in.good()) {
        cout << "Everything is ok" << endl;
        cout << "pi: " << pi << endl;
    } else {
        cout << "Something went wrong" << endl;
    }

    int number;
    in >> number;
    if (in.good()) {
        cout << "Everything is OK" << endl;
        cout << "number: " << number << endl;
    } else {
        cout << "Something went wrong" << endl;
    }

    char end;
    in >> end;

    if (in.good()) {
        cout << "Everything is OK" << endl;
        cout << "end: " << end << endl;
    } else {
        cout << "Something went wrong" << endl;
    }

    if (in.eof()) {
        cout << "End of file" << endl;
    }
}