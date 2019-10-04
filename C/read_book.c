#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read(char* book) {
    FILE* fp = fopen(book, "r");
    char s[30];
    if (fp) {
        while (!feof(fp)) {
            fscanf(fp, "s", s);
        }
        fclose(fp);
        return 1;
    }
    return 0;
}

int check(char* verbs, char* word) {
    FILE* f = fopen(verbs, "r");
    char s[30];
    if (f) {
        while (!EOF) {
            fscanf(f, "s", s);
            if (strstr(word, s)) {
                return 1;
            }
        }
    }
    return 0;
}

int append(char* ans, char* word) {
    FILE* fp;
    fp = fopen(ans, "a");
    if (fp) {
        fprintf(fp, word);
    }
    fclose(fp);
}

int main() {
    char* book = "book.txt";
}
