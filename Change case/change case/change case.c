#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void toUpper(char *str) {
    int i=0, n;
    n = strlen(str);
    for(i=0; i<n; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
    }
}

void toLower(char *str) {
    int i=0, n;
    n = strlen(str);
    for(i=0; i<n; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
    }
}

int main() {
    int kind;
    char str[100];
    printf("Enter a string");
    gets(str);
    do {
        scanf("%d", &kind);
    } while(kind!=1 && kind!=2);
    if(kind == 1)
        toUpper(str);
    else toLower(str);
    printf("%s", str);
}
