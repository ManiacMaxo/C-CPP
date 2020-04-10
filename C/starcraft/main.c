/***************************************************************************
 * NAME: Victor Gorchilov
 * CLASS: 11a
 * NUMBER: 8
 * FILE NAME: main.c
 * FILE PURPOSE:
 * very simple command line starcraft with a few interactions
 ***************************************************************************/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
    int mass;
    pthread_mutex_t mutex;
} MineralBlock;

typedef struct {
    int minerals;
    int num_workers;
    pthread_t *workers;
    int soldiers;
} CommandCenter;

// initialize functions
void *worker(void *arg);
void addUnit(char unit);

// global variables
int total_m_blocks = 2;
int num_m_blocks = 2;
MineralBlock *m_blocks;
CommandCenter center;

// --------------------------------------------------------------------------------------

int main(int argc, char **argv) {
    if (argc > 1) {
        total_m_blocks = atoi(argv[1]);
        num_m_blocks = total_m_blocks;
    }

    center.workers = malloc(sizeof(pthread_t) * center.num_workers);
    for (int i = 0; i < center.num_workers; i++) {
        pthread_create(&center.workers[i], NULL, worker, (void *)i);
        pthread_detach(center.workers[i]);
        /* creates a thread that doesn't need to be joined
        by another thread and doesn't block the function */
    }

    // --------------- runtime ---------------

    while (num_m_blocks > 0 && center.soldiers < 20) {
        char temp;
        scanf("%c", &temp);
        if (temp == 's' || temp == 'm') {
            addUnit(temp);
        }
    }

    // --------------- finish ---------------

    printf("Map minerals %d, player minerals %d, SCVs %d, Marines %d\n",
           total_m_blocks, center.minerals, center.num_workers, center.soldiers);
    m_blocks = malloc(sizeof(MineralBlock) * total_m_blocks);
    for (int i = 0; i < total_m_blocks; i++) {
        m_blocks[i].mass = 500;
        pthread_mutex_init(&m_blocks[i].mutex, NULL);
    }
}

// --------------------------------------------------------------------------------------

void *worker(void *arg) {
    /**************************************************************************
     * FUNCTION: worker
     * function for thread, all utility of the worker - seek, mine,transport
     * PARAMETERS:
     * arg : int (void *), id of worker
     **************************************************************************/
    int num = (int)arg;
    while (center.soldiers < 20 && total_m_blocks) {
        for (int i = 0; i < total_m_blocks; i++) {
            if (m_blocks[i].mass == 0) {  // is block mined
                continue;
            }
            sleep(3);  // move to block

            if (pthread_mutex_trylock(&m_blocks[i].mutex) == 0) {
                printf("SCV %d is mining from mineral block %d\n", num, i);
                m_blocks[i].mass -= 8;
                if (m_blocks[i].mass == 0) {
                    num_m_blocks--;
                }
                break;
            }
        }
        printf("SCV %d is transporting minerals\n", num);
        sleep(2);
        center.minerals += 8;
        printf("SCV %d delivered minerals to the Command center\n", num);
    }
    pthread_exit(NULL);
}

void addUnit(char unit) {
    /**************************************************************************
     * FUNCTION: addUnit
     * function for creating a soldier or worker and starting worker
     * PARAMETERS:
     * arg : int (void *), id of worker
     **************************************************************************/
    if (center.soldiers + center.num_workers != 200 && center.minerals >= 50) {
        switch (unit) {
            case 'm':  // soldier
                center.soldiers++;
                center.minerals -= 50;
                sleep(1);
                printf("You wanna piece of me boy?\n");
                break;
            case 's':  // worker
                center.num_workers++;
                center.minerals -= 50;
                center.workers =
                    realloc(center.workers, sizeof(pthread_t) * center.num_workers);
                pthread_create(&center.workers[center.num_workers], NULL, worker,
                               (void *)center.num_workers);
                sleep(4);
                printf("SCV is good to go\n");
                pthread_detach(center.workers[center.num_workers]);
                break;
        }
    }
}
