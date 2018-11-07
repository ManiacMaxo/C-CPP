#include <stdio.h>
#include <string.h>
#define size 100

void fix(char *str) {
    int i = 0, j = 0, lastSpace = 1;
    char strFixed[size];
    
    for (i=0; i<strlen(str); i++) {
        if (str[i] == ' ') {
            if (lastSpace == 1) { // consecutive space found. skip it
                continue;
            } else { // first space found. remember it
                lastSpace = 1;
            }
        } else {
            lastSpace = 0;
        }
        strFixed[j] = str[i];
        j++;
    }
    if(strFixed[j-1] == ' ') {
        strFixed[j-1] = '\0';
    } else {
        strFixed[j] = '\0';
    }
    strcpy(str, strFixed);
}

int main() {
    char str[size];
    printf("Enter a string: ");
    gets(str);
    fix(str);
    printf("%s\n", str);
}
