#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int start;
    int stop;
    int sum;
} tResult;

tResult red(int n, int *a) {
    int i, diff;
    tResult r = {0, 0, 0};
    int currStart = 0, lastDiff = 0, len = 0, sum = 0;
    for (i = 1; i < n; i++) {
        diff = abs(a[currStart] - a[i]);
        printf("%d %d %d\n", currStart, i, diff);
        if (diff >= lastDiff) {
            lastDiff = diff;
            len++;
        } else {
            if (i - currStart - 1 > r.stop - r.start) {
                r.start = currStart;
                r.stop = i - 1;
            }
            lastDiff = 0;
            currStart++;
            i = currStart + 1;
            printf("\n");
        }
        printf("%d\n", a[i]);
    }
    return r;
}

int main() {
    int a[] = {3, 1, 2, 5, 5, 4, 4, 5, 3, 1};
    int n = sizeof(a) / sizeof(int);
    //   scanf("%d", &n);
    //    for (int i = 0; i < n; i++)
    //        scanf("%d", &arr[i]);
    //    printf("%d %d", start, end);
    tResult r = red(n, a);
    printf("\n");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    printf("start: %d\tstop: %d\n", r.start, r.stop);

    return 0;
}
