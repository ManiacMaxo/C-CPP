#include <stdio.h>

int prime(int num) {
    if (num == 1) {
        return 1;
    }
    int count = 0;
    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            count++;
        }
    }
    if (count == 1) {
        return 1;
    }
    return 0;
}

int sum_prime(int num) {
    int sum = 0;
    while (num) {
        sum += num % 10;
        num /= 10;
    }
    if (prime(sum)) {
        return 1;
    }
    return 0;
}

int main() {
    for (int i = 1; i < 1000; i++) {
        if (sum_prime(i)) {
            printf("%d\n", i);
        }
    }
}
