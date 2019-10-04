#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void split_num(int num, int len) {
    int i = 0;
    int arr[len];
    while (num) {
        arr[i] = num % 10;
        num /= 10;
        i++;
    }

    int j = len - 1;
    for (i = 0; i <= j; i++, j--) {
        int temp = arr[i];
        arr[i] = arr[j]; 
        arr[j] = temp;
    }

    for (i = 0; i < len; i++) {
        printf("%d", arr[i]);
        if (i != len - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

int main(int argc, char **argv) {
    int num = atoi(argv[1]);
    int len = floor(log10(abs(num))) + 1;  // find the length of the number
    split_num(num, len);
}
