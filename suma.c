#include <stdio.h>

int main() {
    int *a, S1 = 0, S2 = 0, n, i, j;
    scanf("%d", &n);
    a = malloc(n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // ----------------------------------------------------------------

    for (i = 0; i < n; i++) {
        S1 += a[i];
    }
    for
}
