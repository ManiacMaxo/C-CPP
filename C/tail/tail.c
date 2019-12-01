/* ------------------------------------------------------------------------
NAME: Victor Gorchilov
CLASS: 11a
NUMBER: 8
FILE NAME: tail.c (unix file name)
FILE PURPOSE:
implementation of tail function in c
------------------------------------------------------------------------ */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int multiple_files = 0;

void error(char *err_msg, char *filename) {
    /* ------------------------------------------------------------------------
    FUNCTION: error
    return error on given message
    PARAMETERS:
    error message and filename
    what kind of error needs to be returned
    ------------------------------------------------------------------------ */

    char buf1[255], buf2[255];
    sprintf(buf1, err_msg, filename);
    sprintf(buf2, "tail: %s", buf1);
    perror(buf2);
}

void print_header(const char *filename) {
    /* ------------------------------------------------------------------------
    FUNCTION: print_header
    print the header of a given file
    PARAMETERS:
    filename
    the name of the file whose header has to be printed
    ------------------------------------------------------------------------ */

    char header[255];
    sprintf(header, "==> %s <==\n", filename);
    if (write(STDOUT_FILENO, header, strlen(header)) == -1) {
        error("error writing '%s'", "standart ouput");
    }
}

int find_start(int fd, char *filename) {
    /* ------------------------------------------------------------------------
    FUNCTION: find_start
    go through the fd backwards until 10 lines are read and return the position
    PARAMETERS:
    file descriptor and filename
    self-explanatory, filename needed for error checking
    ------------------------------------------------------------------------ */

    char ch;
    int i = 0;
    int pos = lseek(fd, -2, SEEK_END);
    if (pos == -1) {
        error("error seeking '%s'", filename);
        return -1;
    }
    do {
        if (read(fd, &ch, 1) == -1) {
            error("error reading '%s'", filename);
            return -1;
        }
        if (ch == '\n') {
            i++;
        }
        if (lseek(fd, --pos, SEEK_SET) == -1) {  // short file
            error("error reading '%s'", filename);
            return -1;
        }
        if (pos == 0) {
            return 0;
        }
    } while (i < 10);
    return pos + 2;
}

void tail(int fd, char *filename) {
    /* ------------------------------------------------------------------------
    FUNCTION: tail
    start from position and print unil EOF
    PARAMETERS:
    file descriptor and filename
    self-explanatory, filename needed for error checking
    ------------------------------------------------------------------------ */

    char ch;
    int pos = find_start(fd, filename);
    if (pos == -1) {
        return;
    }
    if (lseek(fd, pos, SEEK_SET) == -1) {
        error("error seeking %s", filename);
        return;
    };

    if (multiple_files) {
        print_header(filename);
    }
    while (read(fd, &ch, 1) > 0) {
        if (write(STDOUT_FILENO, &ch, 1) == -1) {
            error("error writing '%s'", "standart ouput");
        }
    }
    if (ch != '\n') {
        if (write(STDOUT_FILENO, "\n", 1) == -1) {
            error("error writing '%s'", "standart ouput");
        }
    }
    return;
}

int main(int argc, char **argv) {
    if (argc == 1) {  // no file input
        tail(STDIN_FILENO, "standart input");
    } else {
        multiple_files = 1;
        char *filename;
        for (int i = 1; i < argc; i++) {
            if (i > 1) {
                if (write(STDOUT_FILENO, "\n", 1) == -1) {
                    error("error writing '%s'", "standart ouput");
                }
            }

            int fd;
            if (argv[i][0] == '-') {
                fd = STDIN_FILENO;
                filename = "standart input";
            } else {
                filename = argv[i];
                fd = open(filename, O_RDONLY);
                if (fd == -1) {
                    error("cannot open '%s' for reading", filename);
                    continue;
                }
            }

            tail(fd, filename);
            if (fd != STDIN_FILENO) {
                if (close(fd) == -1) {
                    error("error reading '%s'", filename);
                }
            }
        }
    }
}
