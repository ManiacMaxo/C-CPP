#include <stdio.h>
#include <string.h>
#define num 100

int myFind(char *str, char x) {
    int i, p=0;
    for(i=0; i<strlen(str); i++) {
        p += (str[i] == x);
    }
    return p;
}

void RandString(char *str) {
    int i;
    srand(0);
    for (i = 0; i < num; i++) {
        str[i] = rand() % (100 + 1 - 0) + 0;
    }
}

int main() {
    char str[num], x;
    RandString(str);
    printf("Symbol you want to find: ");
    x = getchar();
    printf("Number of %c elements in the string is %d\n", x, myFind(str, x));
}
