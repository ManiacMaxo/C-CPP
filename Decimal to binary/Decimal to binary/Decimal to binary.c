#include <stdio.h>

int decToBinary(int n) {
    int a[100], i;
    for(i=0; n>0; i++) {
        a[i] = n%2;
        n = n/2;
    }
    return a;
}

int main() {
    int n;
    printf("Enter decimal number: ");
    scanf("%d", &n);
    printf("Number in binary is: %d\n", decToBinary(n));
}
