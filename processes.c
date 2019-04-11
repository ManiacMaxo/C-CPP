#include <stdio.h>

typedef struct {
    int id;
    int time;
    int num;
} processor_t;

void load_pocesses(processor_t **processors, int *time) {  // create queues
    int i, t[4], min = time[0], minp;
    char s[2] = "";

    for (i = 0; i < 3; i++) {
        processors[i]->time += time[i];
        processors[i]->num++;
        if (time[i] < min) {
            min = time[i];
            minp = i;
        }
    }

    processors[minp]->time += time[4];
    processors[minp]->num++;

    for (i = 0; i < 4; i++) {
        if (processors[i]->num != 1) {
            strcpy(s, "es");
        }
        printf("Queue for processor %d: %d process%s, Total time: %d\n", i + 1, processors[i]->num, s, processors[i]->time);
    }
}

int main() {
    processor_t processors[4];  // queues
    char input[10];
    int time[5], count = 0;

    do {
        scanf("%s", &input);
        if (input[0] >= '0' && input[0] <= '9') {
            time[count] = atoi(input);
            *input = '\0';
        }
        if (count == 5) {  // return queues
            count = 0;
            load_pocesses(processors, time);
        }
    } while (!strstr("exit", time));  // exit

    return 0;
}
