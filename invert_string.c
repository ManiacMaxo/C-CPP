#include <stdio.h>
#include <string.h>

int main() {
    int i, k=0;
    char str[100], strNew[100];
    printf("Enter a string: ");
    gets(str);
    for(i=strlen(str)-1; i>=0; i--) {
        strNew[k] = str[i];
        k++;
    }
    printf("Inverted string is\n%s", strNew);
}
