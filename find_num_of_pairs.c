/*
1 <= num_all_socks <= 100
1 <= each_sock <= 100
find how many pairs there are
*/

#include <stdio.h>

void bubbleSort(int *arr, int size) {
    int i, j, temp;
    for (i = 0; i < size; i++) {
        for (j = 0; i < size; i++) {
            if (arr[i] > arr[i+1]) {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int findNumOfPairs(int *socks, int num_all_socks) {
    int i, last = 0, num_of_pairs = 0;
    bubbleSort(socks, num_all_socks);
    for (i = 0; i < num_all_socks; i++) {
        if (last == socks[i]) {
            last = 0;
            num_of_pairs++;
        } else {
            last = socks[i];
        }
    }
    return num_of_pairs+1;
}

int main() {
    int i, num_all_socks, socks[100];
    scanf("%d", &num_all_socks);
    for (i = 0; i < num_all_socks; i++)
        scanf("%d", &socks[i]);
    printf("%d", findNumOfPairs(socks, num_all_socks));
}