#include <stdio.h>

void load_train(int *train, int station[], int n) {
    int time = 0;
    for (int i = 0; i < 4; i++) {
        if (train[i] + station[i] >= n) {
            station[i] -= (n - train[i]);
            time += (n - train[i]);
            train[i] = n;
        } else {
            train[i] += station[i];
            time += station[i];
            station[i] = 0;
        }
    }
}

int main(int argc, char **argv) {
    int n = atoi(argv[1]);
    int train[4];

    for (int i = 0; i < 5; i++) {
        // unload_train();
        // load_train();
    }

    return 0;
}
