#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int prime(int num) {
    if (num == 1) {
        return 0;
    }
    for (int i = 2; i <= (int)sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

void* num_primes(void* arg) {
    int num = *(int*)arg;
    int count = 0;
    for (int i = 1; i < num; i++) {
        if (prime(i)) {
            count++;
        }
    }
    void* cnt = (int*)count;
    return cnt;
}

int input() {
    char* str = malloc(sizeof(char) * 15);
    fgets(str, sizeof(str), stdin);

    if (str[0] == 'q') {
        return -1;
    }
    if (str[0] == 'p') {
        char* temp = malloc(strlen(str));
        for (int i = 0, j = 0; i < strlen(temp); i++) {
            if (str[i] == ' ') {
                continue;
            } else {
                temp[j++] = str[i];
            }
        }
        int num = atoi(temp);
        free(temp);
        free(str);
        return num;
    }
}

int main() {
    pthread_t threads[15];
    int i = 0;
    while (42) {
        int num = input();
        if (num == -1) {
            return 0;
        } else {
            pthread_create(threads[i], NULL, num_primes, num);
        }
    }
}
