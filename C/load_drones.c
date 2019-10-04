#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *model;
    int capacity;
    int weight;
} drone_t;

void load_drones(drone_t *main, drone_t *backup, int load) {
    int loss;
    if (main->weight + load < main->capacity) {
        main->weight += load;
    } else {
        int first_possible_load = main->capacity - main->weight;
        int second_load = load - first_possible_load;
        if (backup->weight + second_load < backup->capacity) {
            main->weight = main->capacity;
            backup->weight += second_load;
        }
    }
}

int main(int argc, char **argv) {
    int iterations = atoi(argv[2]), num_d = atoi(argv[1]);
    drone_t *drones = malloc(num_d * sizeof(drone_t));
    for (int i = 0; i < num_d; i++) {
        drones[i] = {"MODEL X", i * 10, i};
    }

    for (int i = 0; i < iterations; i++) {
        load_drones();
    }
    return 0;
}
