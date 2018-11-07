#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int fileWrite(char* fName) {
    FILE* file;
    char s[100] = "0";
    int isFirst = 1;
    file = fopen(fName, "w");
    if(file) {
        printf("Write:\n");
        while(strcmp(s, "END") != 0) {
            if(!isFirst) {
                fprintf(file, "%s\n", s);
            }
            gets(s);
            isFirst = 0;
        }
        fclose(file);
        return 1;
    }
    return 0;
}

int fileRead(char* fName) {
    FILE* file;
    char s[100];
    file = fopen(fName, "r");
    if(file) {
        while(!feof(file)) {
            fgets(s, 100, file);
            printf("%s", s);
        }
        fclose(file);
        return 1;
    }
    return 0;
}

int fileAppend(char* fName) {
    FILE* file;
    char s[100];
    int isFirst;
    file = fopen(fName, "r+");
    if(file) {
        while(!feof(file)) {
            fgets(s, 100, file);
        }
        
        printf("Append:\n");
        while(strcmp(s, "END") != 0) {
            if(!isFirst) {
                fprintf(file, "%s\n", s);
            }
            gets(s);
            isFirst = 0;
        }
        fclose(file);
        return 1;
    }
    return 0;
}

int main() {
    char fName[100];
    printf("Name of file:\n");
    gets(fName);
    int op = 1;
    while(op != 5) {
        printf("File: %s\n", fName);
        printf("1. Write\n2. Read\n3. Append\n4. Change file\n5. Exit");
        scanf("%d", &op);
        getchar();
        
        if (op == 1) {
            if(!fileWrite(fName)) {
                printf("ERROR!\n");
            }
        }
        if (op == 2) {
            if(!fileRead(fName)) {
                printf("ERROR!\n");
            }
        }
        if (op == 3) {
            if(!fileAppend(fName)) {
                printf("ERROR!\n");
            }
        }
        if (op == 4) {
            printf("Name of file:\n");
            gets(fName);
        }
    }
    return 0;
}
