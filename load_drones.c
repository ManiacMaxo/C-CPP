#include <stdio.h>

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
    int num_d;
    drone_t *drones = malloc(num_d * sizeof(drone_t));
    return 0;
}
