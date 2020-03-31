#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#define N 20
#define M 5
pthread_mutex_t cars[M] = {PTHREAD_MUTEX_INITIALIZER, PTHREAD_MUTEX_INITIALIZER,
                           PTHREAD_MUTEX_INITIALIZER, PTHREAD_MUTEX_INITIALIZER,
                           PTHREAD_MUTEX_INITIALIZER};

void *test(void *arg) {
    int tested[M] = {0, 0, 0, 0, 0};  // which cars are tested
    int t_cars = 0;                   // number of cars tested
    do {
        for (int i = 0; i < M; i++) {
            if (tested[i] == 1) {
                continue;
            }
            if (pthread_mutex_trylock(&cars[i]) == 0) {
                tested[i] = 1;
                t_cars++;
                printf("Buyer %d takes car %d.\n", (int)arg + 1, i + 1);
                // sleep(1);
                printf("Buyer %d returns car %d.\n", (int)arg + 1, i + 1);
                pthread_mutex_unlock(&cars[i]);
            }
        }
    } while (t_cars != 5);
    pthread_exit(NULL);
}

int main() {
    pthread_t buyers[N];
    int i;
    for (i = 0; i < N; i++) {
        pthread_create(&buyers[i], NULL, test, (void *)i);
    }
    while (i >= 0) {
        pthread_join(buyers[i--], NULL);
    }
    return 0;
}
