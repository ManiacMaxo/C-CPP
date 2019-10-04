#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int start;
    int end;
} tResult;

tResult red(int n, int *a) {
    int i;
    tResult r;
    int min = INT_MAX, max = INT_MIN;
    for (i = 0; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
        }
        if (a[i] > max) {
            max = a[i];
        }
    }

    int fposmin = -1, fposmax = -1, lposmin = -1, lposmax = -1;
    for (i = 0; i < n; i++) {
        if (a[i] == min && fposmin == -1) {
            fposmin = i;
        } else if (a[i] == min) {
            lposmin = i;
        } else if (a[i] == max && fposmax == -1) {
            fposmax = i;
        } else if (a[i] == max) {
            lposmax = i;
        }
    }
    int minmax = lposmax - fposmin;
    int maxmin = lposmin - fposmax;
    if (minmax > maxmin) {
        r.start = fposmin;
        r.end = lposmax;
    } else if (maxmin > minmax) {
        r.start = fposmax;
        r.end = lposmin;
    } else if (fposmin < fposmax) {
        r.start = fposmin;
        r.end = lposmax;
    } else {
        r.start = fposmax;
        r.end = lposmin;
    }
    return r;
}

int main() {
    int *a;
    int n;
    tResult r;
    scanf("%d", &n);
    a = malloc(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    r = red(n, a);
    printf("%d %d", r.start + 1, r.end + 1);

    return 0;
}