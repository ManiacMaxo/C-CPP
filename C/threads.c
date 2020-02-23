#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void* work(void* arg) {
    int id = (int)arg;
    free(arg);
    printf("Hello from thread %d\n", id);
}

int main() {
    pthread_t threads[10];
    for (int i = 0; i < 10; i++) {
        int* p = malloc(sizeof(int));
        pthread_create(&threads[i], NULL, work, p);
    }
}
