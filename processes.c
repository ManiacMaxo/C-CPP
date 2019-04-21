#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 30
#define PROCNUM 4

typedef struct {
    int id;
    int p_time;
} process_t;

typedef struct {
    int num;
    int t_time;
} values_t;
/* 
void load_queues(process_t **queues, process_t process, values_t *v, int *nump) {
    int min = INT_MAX, mpos;
    for (int i = 0; i < PROCNUM; i++) {
        if (v[i].t_time < min) {
            min = v[i].t_time;
            mpos = i;
        }
    }
}
 */
// ----------------------------------------------------------------------------------------------------------------

int main() {
    int pid = 0, nump = 15;  // process id, number of processes
    char input[MAXLINE];
    process_t process;

    process_t **queue = (process_t **)malloc(PROCNUM * sizeof(process_t));

    // queues
    for (int i = 0; i < PROCNUM; i++) {
        queue[i] = (process_t *)malloc(nump * sizeof(process_t));
    }

    values_t v[PROCNUM];
    for (int i = 0; i < PROCNUM; i++) {
        v[i].num = 0;
        v[i].t_time = 0;
    }

    do {
        fgets(input, MAXLINE, stdin);

        if (input[0] >= '0' && input[0] <= '9') {
            process.p_time = atoi(input);
            process.id = pid++;

            int min = INT_MAX, mpos;
            for (int i = 0; i < PROCNUM; i++) {
                if (v[i].t_time < min) {
                    min = v[i].t_time;
                    mpos = i;
                }
            }
            if (v[mpos].num == nump) {  // extend vector
                nump += 10;
                queue[mpos] = realloc(queue[mpos], nump * sizeof(process_t));
            }
            v[mpos].num++;
            v[mpos].t_time += process.p_time;
            queue[mpos][v[mpos].num] = process;
        }

        if (!pid % 5) {
            for (int i = 0; i < PROCNUM; i++) {
                printf("Queue for processor %d: %d processes, Total time: %d", i + 1, v[i].num, v[i].t_time);
            }
        }

    } while (strstr("exit", input) != 0);  // exit
    free(queue);
    return 0;
}
