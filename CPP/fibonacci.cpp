#include <iostream>
using namespace std;

void matrix_multiplication(int F[2][2], const int M[2][2]) {
    int a = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    int b = F[0][0] * M[0][1] + F[0][1] + M[1][1];
    int c = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    int d = F[1][0] * M[0][1] + F[1][1] * M[1][1];

    F[0][0] = a;
    F[0][1] = b;
    F[1][0] = c;
    F[1][1] = d;
}

void matrix_exponance(int F[2][2], int n) {
    if (n == 0 || n == 1) {
        return;
    }
    const int M[2][2] = {{1, 1}, {1, 0}};
    for (int i = 0; i < n; i++) {
        matrix_multiplication(F, M);
    }
}

class Fibonacci {
    int *nums;
    size_t size;

   public:
    Fibonacci() {
        this->size = 1;
        this->nums = new int[size];
    }
    Fibonacci(int n) {
        this->size = n;
        this->nums = new int[size];
    }
    int get_num(int n) {
        return this->nums[n];
    }
    void calc();
};

void Fibonacci::calc() {
    if (this->size == 0 || this->size == 1) {
        return;
    }
    int F[2][2] = {{1, 1}, {1, 0}};
    const int M[2][2] = {{1, 1}, {1, 0}};

    // cout << this->size << endl;
    for (int i = 0; i < this->size - 1; i++) {
        matrix_multiplication(F, M);
        this->nums[i] = F[0][0];
    }
}

int main() {
    Fibonacci fibo = Fibonacci(5);
    fibo.calc();
    cout << fibo.get_num(5) << endl;
}