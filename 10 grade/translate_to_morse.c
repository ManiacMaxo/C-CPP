#include <ctype.h>
#include <stdio.h>
#include <string.h>

char *toMorse(char *text) {
    static char morseText[200];
    int i;
    morseText[0] = '\0';
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
        "-.- ",   // K 11
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
    for (i = 0; i < strlen(text); i++)
        strcat(morseText, morse[toupper(text[i]) - 'A']);
    return morseText;
}

int main(int argc, char **argv) {
    for (int i = 1; i < argc; i++) printf("%s   ", toMorse(argv[i]));
    printf("\n");
}
