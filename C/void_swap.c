// ------------------------------------------------------------------------
// NAME: Victor Gorchilov
// CLASS: 11a
// NUMBER: 8
// PROBLEM: #4
// FILE NAME: void_swap.c (unix file name)
// FILE PURPOSE: swaping two variables
// ------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(void **a, void **b, size_t size) {
    //------------------------------------------------------------------------
    // FUNCTION: swap
    // swap two pointers
    // PARAMETERS:
    // two pointers to swap
    //------------------------------------------------------------------------

    /* 
    char *x = a, *y = b, temp;
    for (size_t i = 0; i < size; i++) {
        temp = x[i];
        x[i] = y[i];
        y[i] = temp;
    } */
}

int main() {
    char a[] = "1234567890";
    char b[] = "abcdefghij";
    swap(&a, &b, (sizeof(a) + sizeof(b)));
    printf("%s %s\n", a, b);
}
