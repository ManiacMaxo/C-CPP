/* ------------------------------------------------------------------------
NAME: Victor Gorchilov
CLASS: 11a
NUMBER: 8
FILE NAME: threads.c
FILE PURPOSE:
implementation of multithreading in c
finding number of primes until n
------------------------------------------------------------------------ */
#pragma GCC diagnostic ignored "-Wint-to-void-pointer-cast"
#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INBUFLEN sizeof(char) * 100

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
    char* str = malloc(INBUFLEN);
    fgets(str, INBUFLEN, stdin);
    int num = -1;  // quit on anything other than p
    if (str[0] == 'q') {
        return -1;
    } else if (str[0] == 'p') {
        for (int i = 0; i < strlen(str); i++) {
            if (str[i] < '0' || str[i] > '9') {
                str[i] = ' ';
            }
        }

        num = atoi(str);
    } else {
        return -2;
    }
    free(str);
    return num;
}

int main() {
    pthread_t threads[15];
    int i = 0;
    while (42) {
        int num = input();
        if (num == -1) {
            return 0;
        } else if (num == -2) {
            printf("Error: Not a valid input!\n");
            continue;
        }
        pthread_create(&threads[i++], NULL, num_primes, (void*)num);

        if (i == 16) {
            i = 0;
        }
    }
}
