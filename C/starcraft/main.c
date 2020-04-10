/***************************************************************************
 * NAME: Victor Gorchilov
 * CLASS: 11a
 * NUMBER: 8
 * FILE NAME: main.c
 * FILE PURPOSE:
 * very simple command line starcraft with a few interactions
 ***************************************************************************/
// #include <curses.h> // for getch - non blocking input
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

    m_blocks = malloc(sizeof(MineralBlock) * total_m_blocks);
    for (int i = 0; i < total_m_blocks; i++) {
        m_blocks[i].mass = 50;
        pthread_mutex_init(&m_blocks[i].mutex, NULL);
    }

    center.minerals = 0;
    center.soldiers = 20;
    center.workers = malloc(sizeof(pthread_t) * center.num_workers);
    center.num_workers = 5;
    for (int i = 0; i < center.num_workers; i++) {
        pthread_create(&center.workers[i], NULL, worker, (void *)i);
        // pthread_detach(center.workers[i]);
        /* creates a thread that doesn't need to be joined
        by another thread and doesn't block the function */
        sleep(1);
    }

    // --------------- runtime ---------------

    while (42) {
        if ((center.minerals < 50 || center.soldiers >= 20) && num_m_blocks <= 0) {
            break;
        }

        char temp = '0';
        temp = getchar();
        if (temp == 's' || temp == 'm') {
            addUnit(temp);
        }
    }

    // --------------- finish ---------------

    printf("Map minerals %d, player minerals %d, SCVs %d, Marines %d\n",
           total_m_blocks, center.minerals, center.num_workers, center.soldiers);
    m_blocks = malloc(sizeof(MineralBlock) * total_m_blocks);

    free(m_blocks);
    free(center.workers);
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
    while (42) {
        if (num_m_blocks <= 0) {
            pthread_exit(NULL);
        }
        for (int i = 0; i < total_m_blocks; i++) {
            if (m_blocks[i].mass == 0) {  // is block mined
                continue;
            }
            sleep(3);  // move to block

            if (pthread_mutex_trylock(&m_blocks[i].mutex) != 0) {
                continue;
            }
            printf("SCV %d is mining from mineral block %d\n", num, i);
            int val = m_blocks[i].mass < 8 ? m_blocks[i].mass : 8;
            // remove 8 from block, if block is smaller then take all
            m_blocks[i].mass -= 8;
            if (m_blocks[i].mass <= 0) {
                num_m_blocks--;
                printf("number of blocks: %d\n", num_m_blocks);
            }
            pthread_mutex_unlock(&m_blocks[i].mutex);
            printf("SCV %d is transporting minerals\n", num);
            sleep(2);
            center.minerals += val;
            printf("SCV %d delivered minerals to the Command center\n", num);
            break;
        }
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
    printf("Total minerals: %d\n", center.minerals);
    if (center.soldiers + center.num_workers == 200 || center.minerals < 50) {
        printf("\033[0;31m");
        printf("Not enought minerals or too many units!\n");
        printf("\033[0m");
        return;
    }
    switch (unit) {
        case 'm':  // soldier
            center.soldiers++;
            center.minerals -= 50;
            sleep(1);
            printf("\033[0;33m");
            printf("You wanna piece of me boy?\n");
            printf("\033[0m");
            break;
        case 's':  // worker
            center.num_workers++;
            center.minerals -= 50;
            center.workers =
                realloc(center.workers, sizeof(pthread_t) * center.num_workers);
            pthread_create(&center.workers[center.num_workers - 1], NULL, worker,
                           (void *)center.num_workers - 1);
            sleep(4);
            printf("\033[0;32m");
            printf("SCV is good to go\n");
            printf("\033[0m");
            pthread_detach(center.workers[center.num_workers]);
            break;
    }
}
