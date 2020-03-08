/* ------------------------------------------------------------------------
NAME: Victor Gorchilov
CLASS: 11a
NUMBER: 8
FILE NAME: main.c
FILE PURPOSE:
implementation of multithreading in c with mutex synchronization
miners getting gold, traders selling gold
------------------------------------------------------------------------ */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int gold = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
#define SLEEP sleep(1);

void *mine(void *arg) {
    /* ------------------------------------------------------------------------
    FUNCTION: mine
    locking other threads, increasing gold and unlocking the threads
    PARAMETERS:
    void * to the miner id
    ------------------------------------------------------------------------ */
    int num = (int)arg + 1;
    for (int i = 0; i < 20; i++) {
        pthread_mutex_lock(&mutex);
        gold += 10;
        printf("Miner %d gathered 10 gold\n", num);
        pthread_mutex_unlock(&mutex);
        SLEEP
    }
    pthread_exit(NULL);
}

void *trade(void *arg) {
    /* ------------------------------------------------------------------------
    FUNCTION: trade
    locking other threads, decreasing gold and unlocking the threads
    PARAMETERS:
    void * to the trader id
    ------------------------------------------------------------------------ */
    int num = (int)arg + 1;
    for (int i = 0; i < 20; i++) {
        pthread_mutex_lock(&mutex);
        if (gold < 10) {
            printf("The warehouse is empty, cannot sell!\n");
        } else {
            gold -= 10;
            printf("Trader %d sold 10 gold!\n", num);
        }
        pthread_mutex_unlock(&mutex);
        SLEEP
    }
    pthread_exit(NULL);
}

int max(const int a, const int b) {
    /* ------------------------------------------------------------------------
    FUNCTION: max
    locking other threads, increasing gold and unlocking the threads
    PARAMETERS:
    finding the max of two numbers
    ------------------------------------------------------------------------ */
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main(int argc, char **argv) {
    int miners_count, traders_count;
    // Create threads, if no args -> 1 each
    if (argc == 1) {
        miners_count = 1;
        traders_count = 1;
    } else {
        miners_count = atoi(argv[1]);
        traders_count = atoi(argv[2]);
    }
    pthread_t miners[miners_count];
    pthread_t traders[traders_count];
    for (int i = 0; i < max(miners_count, traders_count); i++) {
        if (i < traders_count) {
            pthread_create(&traders[i], NULL, trade, (void *)i);
        }
        if (i < miners_count) {
            pthread_create(&miners[i], NULL, mine, (void *)i);
        }
    }
    // Closing threads
    miners_count--;
    traders_count--;
    while (miners_count >= 0) {
        pthread_join(miners[miners_count--], NULL);
    }
    // printf("Closed miners\n");
    while (traders_count >= 0) {
        pthread_join(traders[traders_count--], NULL);
    }
    // printf("Closed traders\n");
    printf("Gold: %d\n", gold);
    return 0;
}
