#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    int p_time;
} process_t;

typedef struct {
    int num;
    int t_time;
} values_t;

void load_queues() {
}

void *init_queues(values_t **v) {
    for (int i = 0; i < 3; i++) {
        v[i]->num = 0;
        v[i]->t_time = 0;
    }
}

void print_queues(values_t *v) {
    for (int i = 0; i < 3; i++) {
        printf("Queue for processor %d: %d processes, Total time: %d", i + 1, v[i].num, v[i].t_time);
    }
}

// ----------------------------------------------------------------------------------------------------------------

int main() {
    int pid = 0, nump = 50;  // process id, number of processes
    char input[10];
    process_t process;

    process_t **queue = (process_t **)malloc(4 * sizeof(process_t));  // queues
    for (int i = 0; i < 4; i++) {
        queue[i] = (process_t *)malloc(nump * sizeof(process_t));
    }

    values_t v[4];
    init_queues(v);

    do {
        fgets(input, 10, stdin);
        if (input[0] >= '0' && input[0] <= '9') {
            process.p_time = atoi(input);
            process.id = pid++;
            *input = '\0';
            load_queues(&queue, process, v, &nump);
        }
        if (!pid % 5) {
            print_queues(v);
        }
    } while (strstr("exit", input) != 0);  // exit
    free(queue);
    return 0;
}
