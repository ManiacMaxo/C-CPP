#include <stdio.h>
#include <string.h>

void toMockingCase(char *str) {
    int i, len=strlen(str);
    for (i=0; i<len; i++) {
        if(i % 2 == 0) {
            if(str[i] > 'A' && str[i] < 'Z')
                str[i] += 32;
        } else {
            if(str[i] > 'a' && str[i] < 'z')
                str[i] -= 32;
        }
    }
}

int main(int argc, char **argv) {
    int i;
    for (i=1; i<argc; i++) {
        toMockingCase(argv[i]);
        printf("%s", *argv);
    }
    printf("\n");
    
}
