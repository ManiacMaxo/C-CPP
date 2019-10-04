// ------------------------------------------------------------------------
// NAME: Victor Gorchilov
// CLASS: 11a
// NUMBER: 8
// PROBLEM: #1
// FILE NAME: strlen.c (unix file name)
// FILE PURPOSE: creating strlen without use of library
// ------------------------------------------------------------------------

#include <stdio.h>

size_t strlen(const char *string) {
    //------------------------------------------------------------------------
    // FUNCTION: strlen
    // finding length of a string
    // PARAMETERS:
    // a string to get length of
    //------------------------------------------------------------------------

    size_t size = 0;
    while (string[size]) {
        size++;
    }
    return size;
}

int main() {
    char str[100];
    fgets(str, 100, stdin);
    printf("Lenght of string: %lu\n", strlen(str));
    return 0;
}
