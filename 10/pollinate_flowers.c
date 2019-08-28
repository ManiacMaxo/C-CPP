#include <stdio.h>

typedef struct {
    char name[15];
    int age;
    int pollinated;
} flower_t;

void pollinate(flower_t *main, flower_t *left, flower_t *right) {
    if (main->name == left->name && !left->pollinated) {
        left->pollinated = 1;
    }
    if (main->name == right->name && !right->pollinated) {
        right->pollinated = 1;
    }
}

int main() {
    int iterations;
    flower_t main = {
        "Azalea",
        2,
        0,
    };
    flower_t left = {
        "Azalea",
        5,
        0,
    };
    flower_t right = {
        "Not Azalea",
        1,
        0,
    };
    scanf("%d", &iterations);
    for (int i = 0; i < iterations; i++) {
        pollinate(&main, &left, &right);
    }
}