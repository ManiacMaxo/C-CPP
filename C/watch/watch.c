#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void compile_func(char **func) {
    pid_t pid;
    int status;

    if ((pid = fork()) < 0) {
        perror("execution failed");
        exit(1);
    } else if (pid == 0) {
        if (execvp(*func, func) < 0) {
            perror("execution failed");
            exit(1);
        }
    } else {
        while (wait(&status) != pid) {
        }
    }
}

int main(int argc, char **argv) {
    char *func = "ls";
    execvp(func, "-la");
    // char *func = argv[1];
    int i = 0;
    do {
        printf("i = %d\n", i++);
        // compile_func(func);
        sleep(2);
    } while (42);
}
