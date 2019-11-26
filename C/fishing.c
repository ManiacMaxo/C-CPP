#include <stdio.h>
#include <stdlib.h>

struct fish_t {
    int type;
    float bait[4];
};

struct river_t {
    struct fish_t fish[4];
};

int fish4fish(struct river_t r_segment, float chance, int bait) {
    for (int i = 0; i < 4; i++) {
        if (chance <= r_segment.fish[i].bait[bait]) {
            return 1;
        }
    }
    return 0;
}

void init_river(struct river_t *segment) {
    int size = sizeof(segment) / sizeof(struct river_t);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 4; j++) {
            segment[i].fish[j].type = i + j;
            for (int k = 0; k < 4; k++) {
                float num = (rand() % 11) / 10;
                segment[i].fish[j].bait[k] = num;
            }
        }
    }
}

int main(int argc, char *argv[2]) {
    struct river_t *river = malloc(sizeof(struct river_t) * atoi(argv[1]));
    int bait[4] = {10};
    int t_bait = 40;
    int segment, type;
    for (int i = 0; i < t_bait; i++) {
        float chance = (rand() % 11) / 10;
        // fish4fish(segment, chance, type);
    }
    return 0;
}
