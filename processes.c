#include <stdio.h>

typedef struct {
    int id;
    int time;
} processor_t;

void load_pocesses(processor_t **processors, int *time) {  // create queues
    int i, t[4], n[4];
    char *s;

    // create program here

    for (i = 0; i < 4; i++) {
        if (n == 1) {
            s = "";
        } else {
            s = "es";
        }
        printf("Queue for processor %d: %d process%s, Total time: %d", i + 1, n[i], s, t[i]);
    }
    free(s);
}

int main() {
    processor_t *processor1, *processor2, *processor3, *processor4;  // queues
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
            //load_pocesses(&processors, time);
        }
    } while (!strstr("exit", time));  // exit

    return 0;
}
