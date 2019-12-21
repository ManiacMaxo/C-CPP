#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int run_cmd(const char *cmd, char **args) {
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
        execv(cmd, args);
        perror(cmd);
        return 1;
    } else {                             // parent
        while (wait(&wstatus) != pid) {  // wait for the child to finish
        }
    }
    return 0;
}

void parse_cmdline(char *cmdline, char **args) {
    char *temp_cmdline = cmdline;
    char *token = strtok(cmdline, " ");
    int i = 0;
    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, temp_cmdline);
    }
    args[i] = NULL;
}

int main() {
    char *cmdline = malloc(sizeof(char) * 100);
    char **args = malloc(sizeof(cmdline));
    int i = 0;
    while (i != 4) {
        printf("$ ");
        fgets(cmdline, 100, stdin);
        parse_cmdline(cmdline, args);
        run_cmd(args[0], args);
    }
}
