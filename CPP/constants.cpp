#include <iostream>
using namespace std;

int main() {
    const int a = 100;
    char str1[] = "hello";
    char str2[] = "hello 2";
    const char *pc = str1;
    pc = str2;
    //pc[2] = 'A';
}
