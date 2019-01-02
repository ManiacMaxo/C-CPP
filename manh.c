#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x1;
    int x2;
    int y1;
    int y2;
    int x;
    int y;
} line_t;

int main() {
    line_t l1, l2;
    int a1_len = 0, a2_len = 0;
    int min = -1, manhdist;

    scanf("%d %d %d %d", &l1.x1, &l1.y1, &l1.x2, &l1.y2);
    scanf("%d %d %d %d", &l2.x1, &l2.y1, &l2.x2, &l2.y2);

    // --------------------------------------------------------------

    if (l1.x1 == l1.x2) {  // Line 1 is vertical
        a1_len = abs(l1.y1 - l1.y2) + 1;
        l1.x = l1.x1;
        if (l1.y1 < l1.y2) {
            l1.y = l1.y1;
        } else {
            l1.y = l1.y2;
        }
    } else if (l1.y1 == l1.y2) {  // line 1 is horizontal
        a1_len = abs(l1.x1 - l1.x2) + 1;
        l1.y = l1.y1;
        if (l1.x1 < l1.x2) {
            l1.x = l1.x1;
        } else {
            l1.x = l1.x2;
        }
    }

    if (l2.x1 == l2.x2) {  // line 2 is vertical
        a2_len = abs(l2.y1 - l2.y2) + 1;
        l2.x = l2.x1;
        if (l2.y1 < l2.y2) {
            l2.y = l2.y1;
        } else {
            l2.y = l2.y2;
        }
    } else if (l2.y1 == l2.y2) {  // line 2 is horizontal
        a2_len = abs(l2.x1 - l2.x2) + 1;
        l2.y = l2.y1;
        if (l2.x1 < l2.x2) {
            l2.x = l2.x1;
        } else {
            l2.x = l2.x2;
        }
    }

    for (short i = 0; i < a1_len; i++) {
        for (short j = 0; j < a2_len; j++) {
            if (l1.x1 == l1.x2) {  // line 1 is vertical
                l1.y++;
            } else {  // line 1 is horizontal
                l1.x++;
            }
            if (l2.x1 == l2.x2) {  // line 2 is vertical
                l2.y++;
            } else {  // line 2 is horizontal
                l2.x++;
            }
            manhdist = abs(l1.x - l2.x) + abs(l1.y - l2.y);
            if (manhdist < min) {
                min = manhdist;
            }
        }
    }

    printf("%d\n", min);
}
