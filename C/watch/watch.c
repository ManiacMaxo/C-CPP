#include <stdio.h>
#include <unistd.h>

int compile_func(char *func) {
    pid_t pid = fork();
}

int main(int argc, char **argv) {
    char *func;

    do {
        printf("Hey!\n");
        sleep(2);
    } while (42);
}
