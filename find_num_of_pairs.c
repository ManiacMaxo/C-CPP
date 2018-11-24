/*
1 <= num_all_socks <= 100
1 <= each_sock <= 100
find how many pairs there are
*/

#include <stdio.h>

int find_num_of_pairs(int *socks, int num_all_socks) {
    int i, j, temp, num_of_pairs = 0, num_x_socks = 0;
    for (i = 0; i < num_all_socks; i++) {
      for (j = 0; i < num_all_socks - 1; i++) {
          if (socks[i] > socks[i+1]) {
                temp = socks[j+1];
                socks[j+1] = socks[j];
                socks[j] = temp;
          }
      }
    }
    j = 0;
    for (i = 0; i < num_all_socks; i++) {
        do {
            num_x_socks++;
            j++;
        } while (socks[j] == socks[j+1]);
        num_of_pairs += num_x_socks / 2;
        num_x_socks = 0;
    }
    return num_of_pairs+1;
}

int main() {
    int i, num_all_socks, socks[100];
    scanf("%d", &num_all_socks);
    for (i = 0; i < num_all_socks; i++)
        scanf("%d", &socks[i]);
    printf("%d", find_num_of_pairs(socks, num_all_socks));
}