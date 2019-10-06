// ------------------------------------------------------------------------
// NAME: Victor Gorchilov
// CLASS: 11a
// NUMBER: 8
// PROBLEM: #4
// FILE NAME: void_swap.c (unix file name)
// FILE PURPOSE: swaping two variables
// ------------------------------------------------------------------------
#include <stdio.h>

void swap(void *a, void *b, size_t len) {
    //------------------------------------------------------------------------
    // FUNCTION: swap
    // swap two pointers
    // PARAMETERS:
    // two pointers to swap
    //------------------------------------------------------------------------
    unsigned char *p = a, *q = b, tmp;
    for (size_t i = 0; i != len; ++i) {
        tmp = p[i];
        p[i] = q[i];
        q[i] = tmp;
    }
}

int main() {
    int a, b;
    a = 5;
    b = 7;
    swap(&a, &b, 10);
    printf("%d %d\n", a, b);
}
