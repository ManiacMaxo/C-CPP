#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef struct { int x1; int x2; int y1; int y2; } t_line;

int main() {
	t_line l1, l2;
	int a1, a2, i, j;
	int a1_len = 0, a2_len = 0, start1 = 0, start2 = 0;
	int min = INT_MAX, manhdist;

	scanf("%d %d %d %d", &l1.x1, &l1.y1, &l1.x2, &l1.y2);
	scanf("%d %d %d %d", &l2.x1, &l2.y1, &l2.x2, &l2.y2);
	
	if (l1.x1 == l1.x2) { // Line 1 is vertical
		a1 = 1;
		a1_len = abs(l1.y1 - l1.y2) + 1;
		if (l1.y1 < l1.y2) {
			start1 = l1.y1;
		} else {
			start1 = l1.y2;
		}
	} else if (l1.y1 == l1.y2) { // line 1 is horizontal
		a1 = 0;
		a1_len = abs(l1.x1 - l1.x2) + 1;
		if (l1.x1 < l1.x2) {
			start1 = l1.x1;
		} else {
			start1 = l1.x2;
		}
	}

	if (l2.x1 == l2.x2) { // line 2 is vertical
		a2 = 1;
		a2_len = abs(l2.y1 - l2.y2) + 1;
		if (l2.y1 < l2.y2) {
			start2 = l2.y1;
		} else {
			start2 = l2.y2;
		}
	} else if (l2.y1 == l2.y2) { // line 2 is horizontal
		a2 = 0;
		a2_len = abs(l2.x1 - l2.x2) + 1;
		if (l2.x1 < l2.x2) {
			start2 = l2.x1;
		} else {
			start2 = l2.x2;
		}
	}


	for (i = 0; i < a1_len; i++) {
		for (j = 0; j < a2_len; j++) {
			printf("%i=%d\tj=%d\tstart1=%d\tstart2=%d\n", i, j, start1, start2);
			if (a1 == 1 && a2 == 1) { // line 1 is vertical and line 2 is vertical
				manhdist = abs(l1.x1 - l2.x1) + abs(start1 + i - start2 + j);
			} else if (a1 == 1 && a2 == 0) { // line 1 is vertical and line 2 is horizontal
				manhdist = abs(l1.x1 - start2 + j) + abs(start1 + i - l2.y1);
			} else if (a1 == 0 && a2 == 0) { // line 1 is horizontal and line 2 is horizontal
				manhdist = abs(start1 + i - start2 + j) + abs(l1.y1 - l2.y1);
			} else if (a1 == 0 && a2 == 1) { // line 1 is horizontal and line 2 is vertical
				manhdist = abs(start1 + i - l2.x1) + abs(l1.y1 - start2 + j);
			}
			if (manhdist < min) {
				min = manhdist;
			}
		}
	}

	printf("%d\n", min);
	
}
