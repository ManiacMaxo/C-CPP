#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findInArr(char find, char *arr) {
    int i, len = stren(arr);
    for (i=0; i<len; i++) {
        if (find == arr[i])
            return 1;
    }
    return 0;
}

int main() {
    int find, i, arr[100];
    srand(0);
    for (i = 0; i < 100; i++) {
        arr[i] = rand() % (100 + 1 - 0) + 0;
    }
    printf("Number you want to find: ");
    getc(find);
    printf("%d", findInArr(find, arr));
    return 0;
}
