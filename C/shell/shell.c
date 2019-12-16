#include <stdlib.h>
#include <string.h>

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

char **parse_cmdline(const char *cmdline) {
    char *temp_cmdline = cmdline;
    char *token = strtok(cmdline, " ");
    char **argv = malloc(sizeof(char) * 100);
    int i = 0;
    while (token != NULL) {
        argv[i++] = token;
        token = strtok(NULL, temp_cmdline);
    }
    return argv;
}

int main() {}
