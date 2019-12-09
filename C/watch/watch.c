/* ------------------------------------------------------------------------
NAME: Victor Gorchilov
CLASS: 11a
NUMBER: 8
FILE NAME: watch.c (unix file name)
FILE PURPOSE:
implementation of watch function in c
------------------------------------------------------------------------ */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void run_cmd(const char *cmd, char **args) {
    /* ------------------------------------------------------------------------
    FUNCTION: error
    run a given unix command with error checking
    PARAMETERS:
    command and arguments
    the command and its arguments
    ------------------------------------------------------------------------ */

    pid_t pid;
    int wstatus;

    pid = fork();
    if (pid == -1) {  // parent, no memory
        perror("fork");
        return 0;
    } else if (pid == 0) {  // child
        execvp(cmd, args);
        perror(cmd);
        exit(1);
    } else {                             // parent
        while (wait(&wstatus) != pid) {  // wait for the child to finish
        }
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
