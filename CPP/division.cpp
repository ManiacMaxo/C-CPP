#include <iostream>
using namespace std;

class DivisionByZero {
   public:
    void printErrMessage() {
        cout << "Error: division by zero" << endl;
    }
};

double division(double a, double b) {
    if (b == 0) {
        throw DivisionByZero();
    }
    return a / b;
}

int main() {
    double a, b;
    while (true) {
        cout << "Value of a: ";
        cin >> a;
        cout << "Value of b: ";
        cin >> b;
        try {
            double result = division(a, b);
        } catch (DivisionByZero ex) {
            ex.printErrMessage();
            cout << "Division by zero";
        };
        //cout << "Result: " << result << endl;
    };
}
