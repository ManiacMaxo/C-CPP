// ------------------------------------------------------------------------
// NAME: Victor Gorchilov
// CLASS: 11a
// NUMBER: 8
// PROBLEM: #3
// FILE NAME: swap.c (unix file name)
// FILE PURPOSE: swaping two integers
// ------------------------------------------------------------------------

#include <stdio.h>

void swap(int *a, int *b) {
    //------------------------------------------------------------------------
    // FUNCTION: swap
    // swap two integers
    // PARAMETERS:
    // pointers to two integers
    //------------------------------------------------------------------------
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a = 1, b = 2;
    swap(&a, &b);
    printf("%d  %d", a, b);
}
