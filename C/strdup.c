// ------------------------------------------------------------------------
// NAME: Victor Gorchilov
// CLASS: 11a
// NUMBER: 8
// PROBLEM: #5
// FILE NAME: strdup.c (unix file name)
// FILE PURPOSE: duplicate string
// ------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

char *strdup(const char *str) {
    //------------------------------------------------------------------------
    // FUNCTION: strdup
    // duplicate a string
    // PARAMETERS:
    // a string to duplicate
    //------------------------------------------------------------------------
    char *ptr = (char *)malloc(strlen(str) + 1);
    int i = 0;
    for (; i < strlen(str); i++) {
        ptr[i] = str[i];
    }
    ptr[i + 1] = '\0';
    return ptr;
}

int main() {
    char str[] = "Hello, World!";
    char *temp = strdup(str);
    printf("%s\n", temp);
}
