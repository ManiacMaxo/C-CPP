#include <stdio.h>

int aVeryBigSum(int *arr, int n) {
    int i;
    long int sum = 0;
    for (i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int arr[10], n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("%d", aVeryBigSum(arr, n));
}
