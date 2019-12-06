#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int run_cmd(const char *cmd, char **args) {
    pid_t pid;
    int wstatus;

    pid = fork();
    if (pid == -1) {  // parent, no memory
        perror("fork");
        return 0;
    } else if (pid == 0) {  // child
        execvp(cmd, args);
        perror("execvp");
        exit(1);
    } else {  // parent
        // wait for the child to finish
        while (wait(&wstatus) != pid)
            ;
        return wstatus == 0;  // was it a gracefull child exit?
    }
}

int main(int argc, char **argv) {
    const char *cmd = argv[1];
    char **args = malloc(sizeof(char *) * argc);

    if (argc >= 2) {
        int i;
        for (i = 1; i < argc; i++) {
            args[i - 1] = argv[i];
        }
        args[i - 1] = NULL;
        while (42) {
            run_cmd(cmd, args);
            sleep(2);
        }
    }
}
