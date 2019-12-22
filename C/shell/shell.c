/* ------------------------------------------------------------------------
NAME: Victor Gorchilov
CLASS: 11a
NUMBER: 8
FILE NAME: shell.c
FILE PURPOSE:
implementation of a basic shell in c
------------------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 1024
#define MAX_CMD_ARRAY 100

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
        if (execv(cmd, args) < 0) {
            perror(cmd);
        }
        // return 1;
    } else {                             // parent
        while (wait(&wstatus) != pid) {  // wait for the child to finish
        }
    }
    return 0;
}

void parse_cmdline(char *cmdline, char **args) {
    /* ------------------------------------------------------------------------
    FUNCTION: error
    parse input string and split on spaces
    PARAMETERS:
    input and arguments
    input string and the arguments to parse into
    ------------------------------------------------------------------------ */
    char *token = strtok(cmdline, " ");
    int i = 0;
    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }

    // last argument, last character (-1 because of \0)
    char *temp = &args[i - 1][strlen(args[i - 1]) - 1];
    if (*temp == '\n') {  // remove newline from input
        *temp = '\0';
    }

    // add NULL as last argument
    if (args[i - 1][0] == '\0') {
        // last token is empty. terminate here
        args[i - 1] = NULL;
    } else {
        // add one more element
        args[i] = NULL;
    }
}

int main() {
    char *cmdline = malloc(sizeof(char) * MAX_CMD_LEN);
    char **args = malloc(sizeof(char *) * MAX_CMD_ARRAY);
    while (42) {
        printf("$ ");
        if (fgets(cmdline, MAX_CMD_LEN, stdin) == NULL) {
            break;
        }
        // FIXME: check if last symbol \n. if so - remove, if not - expand the
        // buffer and read again
        parse_cmdline(cmdline, args);
        run_cmd(args[0], args);
    }
    free(cmdline);
    free(args);
}
