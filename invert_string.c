#include <stdio.h>
#include <string.h>

void invertStr(char *str) {
    int i, j, len = strlen(str);
    j = len;
    char strHelp[len];
    for (i=0; i<len; i++)
        str[i] = strHelp[j--];
    strcpy(str, strHelp);
}

int main() {
    char str[100];
    printf("Enter a string: ");
    gets(str);
    invertStr(str);
    printf("Inverted string is\n%s\n", str);
}
