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
    pthread_mutex_t mutex;
} CommandCenter;

// initialize functions
void *worker(void *arg);
void *addUnit(void *arg);

// global variables
int total_m_blocks = 2;
int num_m_blocks = 2;
pthread_mutex_t num_m_blocks_mutex = PTHREAD_MUTEX_INITIALIZER;
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
        m_blocks[i].mass = 500;
        if (pthread_mutex_init(&m_blocks[i].mutex, NULL)) {
            perror("pthread_mutex_init");
        }
    }

    // init input thread
    pthread_t addUnitThread;
    if (pthread_create(&addUnitThread, NULL, addUnit, NULL)) {
        perror("pthread_create");
    }

    // init Command Center
    pthread_mutex_init(&center.mutex, NULL);
    center.minerals = 0;
    center.soldiers = 0;
    center.num_workers = 5;
    center.workers = malloc(sizeof(pthread_t) * center.num_workers);
    for (int i = 0; i < center.num_workers; i++) {
        if (pthread_create(&center.workers[i], NULL, worker, (void *)i)) {
            perror("pthread_create");
        }
        pthread_detach(center.workers[i]);
    }

    // --------------- runtime ---------------

    while (center.soldiers < 20) {
        usleep(1000);
    }
    sleep(5);
    pthread_cancel(addUnitThread);

    // --------------- finish ---------------

    printf("Map minerals %d, player minerals %d, SCVs %d, Marines %d\n",
           total_m_blocks * 500, center.minerals, center.num_workers,
           center.soldiers);
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
    while (num_m_blocks > 0) {
        for (int i = 0; i < total_m_blocks; i++) {
            if (m_blocks[i].mass <= 0) {  // is block mined
                continue;
            }

            sleep(3);  // move to block
            if (pthread_mutex_trylock(&m_blocks[i].mutex) != 0 ||
                m_blocks[i].mass <= 0) {
                continue;
            }
            printf("SCV %d is mining from mineral block %d\n", num + 1, i + 1);
            int val = m_blocks[i].mass < 8 ? m_blocks[i].mass : 8;
            // remove 8 from block; if block is less remove remaining
            m_blocks[i].mass -= val;

            pthread_mutex_lock(&num_m_blocks_mutex);
            if (m_blocks[i].mass == 0) {
                num_m_blocks--;
                // printf("number of blocks: %d\n", num_m_blocks);
            }
            pthread_mutex_unlock(&num_m_blocks_mutex);
            pthread_mutex_unlock(&m_blocks[i].mutex);
            printf("SCV %d is transporting minerals\n", num + 1);
            sleep(2);
            while (pthread_mutex_trylock(&center.mutex) != 0) {
                usleep(1000);
            }
            center.minerals += val;
            pthread_mutex_unlock(&center.mutex);
            printf("SCV %d delivered minerals to the Command center\n", num + 1);
            break;
        }
    }
    pthread_exit(NULL);
}

void *addUnit(void *arg) {
    /**************************************************************************
     * FUNCTION: addUnit
     * function for creating a soldier or worker and starting worker
     * PARAMETERS:
     * none
     **************************************************************************/
    do {
        char unit;
        do {
            unit = getchar();
        } while (unit != 'm' && unit != 's' && unit != 't');

        if (center.soldiers + center.num_workers == 200 || center.minerals < 50) {
            printf("\033[0;31m");
            printf("Not enough minerals.\n");
            printf("\033[0m");
            continue;
        }

        switch (unit) {
            case 'm':  // soldier
                center.soldiers++;
                center.minerals -= 50;
                sleep(1);
                printf("You wanna piece of me, boy?\n");
                break;
            case 's':  // worker
                center.num_workers++;
                center.minerals -= 50;
                center.workers =
                    realloc(center.workers, sizeof(pthread_t) * center.num_workers);
                sleep(4);
                if (pthread_create(&center.workers[center.num_workers - 1], NULL,
                                   worker, (void *)center.num_workers - 1)) {
                    perror("pthread_create");
                }
                pthread_detach(center.workers[center.num_workers - 1]);
                printf("SCV is good to go, sir.\n");
                break;
                // case 't':
                //     printf("Total minerals: %d\n", center.minerals);
                //     for (int i = 0; i < total_m_blocks; i++) {
                //         printf("block %d mass: %d\n", i, m_blocks[i].mass);
                //     }
                //     break;
        }
    } while (42);
    pthread_exit(NULL);
}
