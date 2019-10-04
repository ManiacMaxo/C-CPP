#include <stdio.h>

int strlen(const char *str) {
    int i = 0;
    while (str[i++] != '\0') {
    }
    return i;
}

int main() {
    char str[100];
    fgets(str, 100, stdin);
    printf("Lenght of string: %d\n", strlen(str));
    return 0;
}
