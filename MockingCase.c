#include <stdio.h>
#include <string.h>
#include <ctype.h>

int ind = 0;

void toMockingCase(char *str) {
    int i, len=strlen(str);
    for(i=0; i<len; i++) {
        if(!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')))
            continue;
        else if(ind % 2 == 0) {
            str[i] = tolower(str[i]);
            ind = 1;
        }
        else {
            str[i] = toupper(str[i]);
            ind = 0;
        }
    }
    if(ind == 1) ind = 0;
    else ind = 1;
}

int main(int argc, char **argv) {
    for(int i=1; i<argc; i++) {
        toMockingCase(argv[i]);
        printf("%s ", argv[i]);
    }
    printf("\n");
}
