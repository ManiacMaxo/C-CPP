/* ------------------------------------------------------------------------
NAME: Victor Gorchilov
CLASS: 11a
NUMBER: 8
FILE NAME: thread.c
FILE PURPOSE:
implementation of multithreading in c
finding number of primes until n
------------------------------------------------------------------------ */
// #pragma GCC diagnostic ignored "-Wint-to-void-pointer-cast"
#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define BUFLEN sizeof(char) * 100

int prime(unsigned int num) {
    /* ------------------------------------------------------------------------
    FUNCTION: prime
    check if input is prime
    PARAMETERS:
    a number to check
    ------------------------------------------------------------------------ */
    if (num == 1) {
        return 0;
    }
    for (unsigned int i = 2; i <= (unsigned int)sqrt(num); i++) {
        // for (unsigned int i = 2; i < num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

void* num_primes(void* arg) {
    /* ------------------------------------------------------------------------
    FUNCTION: num_primes
    find number of primes from 1 to n
    PARAMETERS:
    a number that is the endpoint
    ------------------------------------------------------------------------ */
    int n = (unsigned int)arg;
    printf("Prime calculation started for N=%d\n", n);
    int count = 0;
    for (unsigned int i = 1; i < n; i++) {
        if (prime(i)) {
            count++;
        }
    }
    printf("Number of primes for N=%d is %d\n", n, count);
    return NULL;
}

int input() {
    /* ------------------------------------------------------------------------
    FUNCTION: input
    parsing input
    PARAMETERS:
    none
    ------------------------------------------------------------------------ */
    char* str = malloc(BUFLEN);
    fgets(str, BUFLEN, stdin);
    int num = 0;
    if (str[0] == 'e') {
        num = -1;
    } else if (str[0] == 'p') {
        int i = 0;
        while (str[i] != '\0') {
            if (str[i] < '0' || str[i] > '9') {
                str[i] = ' ';
            }
            i++;
        }
        num = atoi(str);
    } else {
        num = -2;
    }
    free(str);
    return num;
}

int main() {
    pthread_t thread[100];
    int i = -1;
    while (i < 100) {
        int num = input();
        if (num == -1) {
            break;
        } else if (num == -2) {
            printf("Error: Not a valid input!\n");
            continue;
        }
        pthread_create(&thread[++i], NULL, num_primes, (void*)num);
    }
    while (i >= 0) {
        printf("i=%d\n", i);
        pthread_join(thread[i--], NULL);
    }
    return 0;
}
