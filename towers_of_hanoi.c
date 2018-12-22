#include <stdio.h>
#include <stdlib.h>

int i;

void hanoi(int n, char s, char d, char m) {
    if (n == 1) {
        printf("\n%c -> %c", s, d);
        i++;
    } else {
        hanoi(n - 1, s, m, d);
        printf("\n%c -> %c", s, d);
        i++;
        hanoi(n - 1, m, d, s);
    }
}

int main() {
    int n;
    do {
        printf("Number of disks: ");
        scanf("%d", &n);
    } while (n < 0);
    hanoi(n, 'A', 'C', 'B');
    printf("\n\nNumber of moves: %d", i);
    return 0;
}
