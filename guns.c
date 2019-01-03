#include <stdio.h>

struct gun_t {
    char model[128];
    int accuracy;
    int ammo_capacity;
};

int getScore(int gun_accuracy, int shot_accuracy) {
    short score = 0, n = (100 - gun_accuracy) / 10, i = 1, score = 9;
    if (shot_accuracy <= gun_accuracy) {
        return 10;
    } else {
        do {
            if (shot_accuracy >= gun_accuracy + i && shot_accuracy <= gun_accuracy + i + 5) {
                return score;
            }
            i += n;
            score--;
        } while (42);
    }
    return score;
}

int getScore2(int gun_accuracy, int shot_accuracy) {
    short i, j;
    short score = 10;
    int a[10], b[10];

    for (i = 0; i < 10; i++) {
        a[i] = gun_accuracy - i * gun_accuracy / 10;
        b[i] = gun_accuracy - i * (100 - gun_accuracy) / 10;
    }

    do {
        if ((shot_accuracy >= a[i] && shot_accuracy <= a[i + 1]) || (shot_accuracy >= b[i] && shot_accuracy <= b[i])) {
            return score;
        }
        score--;
    } while (42);
}

void testGun(struct gun_t gun, int shot_count) {
    short shot_accuracy, overall = 0, currentS;
    for (int i = 0; i < shot_count; i++) {
        shot_accuracy = rand() % 100;
        currentS = getScore(gun.accuracy, shot_accuracy);
        overall += currentS;
        printf("shot %d score: %d\n", i, currentS);
        printf("overall score: %d\t average: %d\n", overall, overall / (i + 1));
    }
}

int main() {
    short shot_count;
    struct gun_t gun = {
        .model = "M1A",
        .accuracy = 70,
        .ammo_capacity = 20,
    };
    scanf("%d", &shot_count);
    testGun(gun, shot_count);
}
