#include <stdio.h>

typedef struct {
    int id;
    int time;
} process_t;

typedef struct {
    process_t *processes;
} processor_t;

void queue() {
}

int main() {
    process_t **processors;  // queues
    char input[10];
    int time[5], count = 0;

    do {
        scanf("%s", &input);
        if (input[0] >= '0' && input[0] <= '9') {
            time[count] = atoi(input);
            *input = '\0';
            if (count == 5) {  // return queues
                count = 0;
                // queue procceses
            }
        }
    } while (!strstr("exit", time));  // exit

    return 0;
}
