#include <stdio.h>
#include <stdlib.h>

struct gun_t {
    char model[128];
    int accuracy;
    int ammo_capacity;
};

int getScore(int gun_accuracy, int shot_accuracy) {
    short i;
    int score = 9;
    int a[10], b[10];

    if (gun_accuracy > 50) {
        for (i = 0; i < 10; i++) {
            a[i] = 50 - i * 5;
            b[i] = gun_accuracy + i * (100 - gun_accuracy) / 10;
        }
    } else {
        for (i = 0; i < 10; i++) {
            a[i] = gun_accuracy - i * gun_accuracy / 10;
            b[i] = 50 + i * 5;
        }
    }
    for (i = 0; i < 10; i++, score--) {
        if (shot_accuracy >= a[i] && shot_accuracy <= b[i]) {
            return score;
        }
    }
    return score;
}  // не разбирам условието на задачата

void testGun(struct gun_t gun, int shot_count) {
    short shot_accuracy, overallS = 0, currentS;
    for (int i = 0; i < shot_count; i++) {
        shot_accuracy = rand() % 100;
        currentS = getScore(gun.accuracy, shot_accuracy);
        overallS += currentS;
        printf("shot %d\taccuracy: %d\tscore: %d\n", i + 1, shot_accuracy,
               currentS);
        printf("overall score: %d\t average: %d\n\n", overallS,
               overallS / (i + 1));
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
