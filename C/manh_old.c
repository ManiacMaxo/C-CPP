#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x1;
    int x2;
    int y1;
    int y2;
} line_t;

int main() {
    line_t l1, l2;
    int *a1, *a2, i, j;
    int a1_len = 0, a2_len = 0;
    int min = INT_MAX, manhdist;

    scanf("%d %d %d %d", &l1.x1, &l1.y1, &l1.x2, &l1.y2);
    scanf("%d %d %d %d", &l2.x1, &l2.y1, &l2.x2, &l2.y2);

    if (l1.x1 == l1.x2) {  // Line 1 is vertical
        a1_len = abs(l1.y1 - l1.y2) + 1;
        a1 = malloc(a1_len);
        if (l1.y1 < l1.y2) {
            for (i = 0; i < a1_len; i++) {
                a1[i] = l1.y1 + i;
            }
        } else {
            for (i = 0; i < a1_len; i++) {
                a1[i] = l1.y2 + i;
            }
        }
    } else if (l1.y1 == l1.y2) {  // line 1 is horizontal
        a1_len = abs(l1.x1 - l1.x2) + 1;
        a1 = malloc(a1_len);
        if (l1.x1 < l1.x2) {
            for (i = 0; i < a1_len; i++) {
                a1[i] = l1.x1 + i;
            }
        } else {
            for (i = 0; i < a1_len; i++) {
                a1[i] = l1.x2 + i;
            }
        }
    }

    if (l2.x1 == l2.x2) {  // line 2 is vertical
        a2_len = abs(l2.y1 - l2.y2) + 1;
        a2 = malloc(a2_len);
        if (l2.y1 < l2.y2) {
            for (i = 0; i < a2_len; i++) {
                a2[i] = l2.y1 + i;
            }
        } else {
            for (i = 0; i < a2_len; i++) {
                a2[i] = l2.y2 + i;
            }
        }
    } else if (l2.y1 == l2.y2) {  // line 2 is horizontal
        a2_len = abs(l2.x1 - l2.x2) + 1;
        a2 = malloc(a2_len);
        if (l2.x1 < l2.x2) {
            for (i = 0; i < a2_len; i++) {
                a2[i] = l2.x1 + i;
            }
        } else {
            for (i = 0; i < a2_len; i++) {
                a2[i] = l2.x2 + i;
            }
        }
    }

    for (i = 0; i < a1_len; i++) {
        for (j = 0; j < a2_len; j++) {
            if (l1.x1 == l1.x2 && l2.x1 == l2.x2) {  // line 1 is vertical and line 2 is vertical
                manhdist = abs(l1.x1 - l2.x1) + abs(a1[i] - a2[j]);
            } else if (l1.x1 == l1.x2 && l2.y1 == l2.y2) {  // line 1 is vertical and line 2 is horizontal
                manhdist = abs(l1.x1 - a2[j]) + abs(a1[i] - l2.y1);
            } else if (l1.y1 == l1.y2 && l2.y1 == l2.y2) {  // line 1 is horizontal and line 2 is horizontal
                manhdist = abs(a1[i] - a2[j]) + abs(l1.y1 - l2.y1);
            } else if (l1.y1 == l1.y2 && l2.x1 == l2.x2) {  // line 1 is horizontal and line 2 is vertical
                manhdist = abs(a1[i] - l2.x1) + abs(l1.y1 - a2[j]);
            }
            if (manhdist < min) {
                min = manhdist;
            }
        }
    }

    printf("%d\n", min);
}
