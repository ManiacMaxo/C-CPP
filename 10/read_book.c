#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fileRead(char* book) {
    FILE* file = fopen(book, "r");
    char s[30];
    if (file) {
        while (!feof(file)) {
            fscanf(file, "s", s);
        }
        fclose(file);
        return 1;
    }
    return 0;
}

int check(char* verbs, char* word) {
    FILE* f = fopen(verbs, "r");
    if (f) {
        while (!EOF) {
        }
    }
}

int fileWrite(char* ans, char* word) {
    FILE* file;
    file = fopen(ans, "w");
    if (file) {
        fprintf(file, word);
    }
    fclose(file);
}

int main() {
    char* book = "book.txt";
}
