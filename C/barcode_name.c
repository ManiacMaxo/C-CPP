#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int len = atoi(argv[1]);
    char arr[len];
    char letters[] = {'l', 'I'};
    srand(time(0));
    for (int i = 0; i < len; i++) {
        // printf("%d\n", rand() % 2);
        arr[i] = letters[rand() % 2];
    }
    printf("%s\n", arr);
}
