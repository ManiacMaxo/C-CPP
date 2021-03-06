#include <ctype.h>
#include <stdio.h>
#include <string.h>

int ind = 0;

void toMockingCase(char *str) {
    int i, len = strlen(str);
    for (i = 0; i < len; i++) {
        if (!((str[i] >= 'a' && str[i] <= 'z') ||
              (str[i] >= 'A' && str[i] <= 'Z')))
            continue;
        else if (ind) {
            str[i] = tolower(str[i]);
        } else {
            str[i] = toupper(str[i]);
        }
        ind = !ind;
    }
}

int main(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        toMockingCase(argv[i]);
        printf("%s ", argv[i]);
    }
    printf("\n");
}
