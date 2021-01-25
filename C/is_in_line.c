#include <stdio.h>
#include <string.h>

struct point_t {
    float x;
    float y;
};

int threeOnLine(struct point_t *p) {
    return (p[1].y - p[0].y) * (p[2].x - p[1].x) ==
           (p[2].y - p[1].y) * (p[1].x - p[0].x);
}

int main() {
    int i;
    struct point_t point[2];
    for (i = 0; i < strlen(point); i++) {
        printf("Enter a coordinate for point %d\n", i + 1);
        scanf("%f", &point[i].x);
        scanf("%f", &point[i].y);
    }
    printf("%d\n", threeOnLine(point));
    return 0;
}
