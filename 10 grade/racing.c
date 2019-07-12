#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int smallestNums(int n, int *price) {
    int i = -1, sum = 0;
    while (i < n - 2) {
        if (price[i + 1] < price[i + 2] && price[i + 1] < price[i + 3]) {
            sum += price[i + 1];
            i++;
        }
        if (price[i + 2] <= price[i + 1] && price[i + 2] < price[i + 3]) {
            sum += price[i + 2];
            i += 2;
        }
        if (price[i + 3] <= price[i + 1] && price[i + 3] <= price[i + 2]) {
            sum += price[i + 3];
            i += 3;
        }
    }
    return sum;
}

int minHops(int n, int *price) {
    int i, sum = 0;
    for (i = 2; i < n; i += 3) {
        sum += price[i];
    }
    return sum;
}

int main() {
    int i, n, *price;
    scanf("%d", &n);
    price = malloc(n);
    for (i = 0; i < n; i++) {
        scanf("%d", &price[i]);
    }

    if (smallestNums(n, price) < minHops(n, price)) {
        printf("%d", smallestNums(n, price));
    } else {
        printf("%d", minHops(n, price));
    }
}
