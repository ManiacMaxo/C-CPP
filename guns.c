#include <stdio.h>

struct gun_t {
    char model[128];
    int accuracy;
    int ammo_capacity;
};

int getScore(int gun_accuracy, int shot_accuracy) {
    int score = 0, i = 1, j = 9;
    if (shot_accuracy <= gun_accuracy) {
        score = 10;
    } else {
        do {
            if (shot_accuracy >= gun_accuracy + i && shot_accuracy <= gun_accuracy + i + 5) {
                i += 5;
                score = j;
                j--;
            }
        } while (!score);
    }
    return score;
}

void testGun(struct gun_t gun, int shot_count) {
    int hit_or_miss, overall = 0, currentS;
    for (int i = 0; i < shot_count; i++) {
        hit_or_miss = rand() % 100;
        currentS = getScore(gun.accuracy, hit_or_miss);
        overall += currentS;
        printf("shot %d score: %d\n", i, currentS);
        printf("overall score: %d\t average: %d\n", overall, overall / (i + 1));
    }
}

int main() {
    int shot_count;
    struct gun_t gun = {
        .model = "M1A",
        .accuracy = 70,
        .ammo_capacity = 20,
    };
    scanf("%d", &shot_count);
    testGun(gun, shot_count);
}
