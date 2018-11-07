#include <stdio.h>
#include <string.h>
#define max 100

int fileRead(char* fName) {
    FILE* file;
    char s[max];
    file = fopen(fName, "r");
    if(file) {
        while(!feof(file)) {
            fgets(s, max, file);
            if(strlen(s)>10)
                printf("%s", s);
        }
        fclose(file);
        return 1;
    }
    return 0;
}

int main() {
    char fName[max];
    printf("Enter a filename\n");
    gets(fName);
    fileRead(fName);
    printf("\n");
}
