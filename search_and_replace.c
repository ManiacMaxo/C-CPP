#include <stdio.h>
#include <string.h>
#define MAX 100

int searchOccur(char *str, char *find) {
    int lenStr = strlen(str), lenFind = strlen(find), j = 0, lastIsInFind = 0, numOccur = 0;
    for (int i = 0; i < lenStr; i++) {
        if (str[i] == find[j]) {
            lastIsInFind = 1;
            j++;
            if (j == lenFind) {
                numOccur++;
                j = 0;
            }
        } else {
            lastIsInFind = 0;
        }
    }
    return numOccur;
}

char *replace(char *str, char *replace, char *find, int numOccur) {
    char *strReplaced;
    strReplaced = malloc(strlen(str) + numOccur * abs(strlen(find) - strlen(replace)));
}

int main() {
    char str[MAX], find[MAX], replace[MAX];
    int numOccur = searchOccur(str, find);
}
