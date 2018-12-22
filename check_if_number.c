#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checker(char *str) {
    int i = 0;
    if (str[i] == '+' || str[i] == '-' || (str[i] >= '0' && str[i] <= '9')) {
        i++;
        while (str[i] >= '0' && str[i] <= '9') i++;
        if (i == strlen(str)) return 1;
    }
    return 0;
}

int main() {
    char str[100];
    int s;
    printf("Enter a number: ");
    gets(str);
    if (checker(str)) {
        s = atoi(str);
        printf("String is a number %d\n", s);
    } else
        printf("That is not a number!\n");
}
