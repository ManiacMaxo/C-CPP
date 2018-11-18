#include <stdio.h>

int absDiff(int a, int b) {
    if(b > a)
        return b - a;
    return a - b;
}

int findSmallestDifference(int *arr) {
    int min = absDiff(arr[0], arr[1]);
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(arr[i] == arr[j]) continue;
            int diff = absDiff(arr[i], arr[j]);
            if(diff < min)
                min = diff;
        }
    }
    return min;
}

int main(int argc, char **argv) {
    int arr[] = { 5, 7, 3, 4, 1, 6, 8, 10, 2, 9 };
    printf("%s\n", findSmallestDifference(arr));
    return 0;
}