#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *morse[] = {
    ".- ",    // A 1
    "-... ",  // B 2
    "-.-. ",  // C 3
    "-.. ",   // D 4
    ". ",     // E 5
    "..-. ",  // F 6
    "--. ",   // G 7
    ".... ",  // H 8
    ".. ",    // I 9
    ".--- ",  // J 10
    "-.- ",   // j 11
    ".-.. ",  // L 12
    "-- ",    // M 13
    "-. ",    // N 14
    "--- ",   // O 15
    ".--. ",  // P 16
    "--.- ",  // Q 17
    ".-. ",   // R 18
    "... ",   // S 19
    "- ",     // T 20
    "..- ",   // U 21
    "...- ",  // V 22
    ".-- ",   // W 23
    "-..- ",  // X 24
    "-.-- ",  // Y 25
    "--.. ",  // Z 26
};

char *fRead(char *filename) {
    FILE *file;
    int size = 100, slen;
    char *s = malloc(sizeof(char) * size);
    file = fopen(filename, "r");
    if (file) {
        while (!feof(file)) {
            slen = strlen(s);
            if (slen > size - 10 && slen == size) {
                size *= 2;
                s = realloc(s, sizeof(char) * size);
            }
            fgets(s, size, file);
        }
    }
    fclose(file);
    return s;
}

char *toMorse(char *text) {
    int slen = strlen(text);
    char *morseText = malloc(sizeof(char) * slen * 4);
    morseText[0] = '\0';
    for (int i = 0; i < slen; i++) {
        if (text[i] == ' ') {
            strcat(morseText, " ");
            continue;
        }
        strcat(morseText, morse[toupper(text[i]) - 'A']);
    }
    return morseText;
}

/*
char *fromMorse(char *morseText) {
    int slen = strlen(morseText);
    char *text = malloc(sizeof(char) * strlen(morseText) / 4);
    char temp[5];
    int j = 0;
    for (int i = 0; i < slen; i++) {
        temp[j + 1] = '\0';
        if (morseText[i] == ' ') {
            for (j = 0; j < 26; j++) {
                if (strcmp(temp, morse[j])) {
                    strcat(text, j + 'A');
                }
            }
        }
    }
}
*/

void fWrite(char *filename, char *morse) {
    FILE *file;
    file = fopen(filename, "a");
    if (file) {
        fprintf(file, "%s\n", morse);
    }
    fclose(file);
}

int main(int argc, char **argv) {
    // argv[1] is file name
    fWrite(argv[1], toMorse(fRead(argv[1])));
    return 0;
}
