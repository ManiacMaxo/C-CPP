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
#include <sys/errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int multiple_files = 0;

void error(char *err_msg, char *fName) {
    /* ------------------------------------------------------------------------
    FUNCTION: error
    return error on given message
    PARAMETERS:
    error message and filename
    what kind of error needs to be returned
    ------------------------------------------------------------------------ */

    char buf1[255], buf2[255];
    sprintf(buf1, err_msg, fName);
    sprintf(buf2, "tail: %s", buf1);
    perror(buf2);
}

void print_header(const char *fName) {
    /* ------------------------------------------------------------------------
    FUNCTION: print_header
    print the header of a given file
    PARAMETERS:
    filename
    the name of the file whose header has to be printed
    ------------------------------------------------------------------------ */

    char header[255];
    if (multiple_files) {
        sprintf(header, "\n");
    }
    sprintf(header, "==> %s <==\n", fName);
    if (write(STDOUT_FILENO, header, strlen(header)) == -1 || errno == 28) {
        error("error writing '%s'", "standard ouput");
    }
}

int find_start(int fd, char *fName) {
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
        error("error seeking '%s'", fName);
        return -1;
    }
    do {
        if (read(fd, &ch, 1) == -1) {
            error("error reading '%s'", fName);
            return -1;
        }
        if (ch == '\n') {
            i++;
        }
        if (lseek(fd, --pos, SEEK_SET) == -1) {  // short file
            pos--;
            break;
        }
    } while (i < 10);
    return pos + 2;
}

void tail(int fd, char *fName) {
    /* ------------------------------------------------------------------------
    FUNCTION: tail
    start from position and print unil EOF
    PARAMETERS:
    file descriptor and filename
    self-explanatory, filename needed for error checking
    ------------------------------------------------------------------------ */

    char ch;
    int pos = find_start(fd, fName);
    if (pos == -1) {  // error with file
        return;
    }
    if (lseek(fd, pos, SEEK_SET) == -1) {
        error("error seeking %s", fName);
        return;
    }

    if (multiple_files && fd != STDIN_FILENO) {
        print_header(fName);
    }
    while (read(fd, &ch, 1) > 0) {
        if (write(STDOUT_FILENO, &ch, 1) == -1 || errno == 28) {
            error("error writing '%s'", "standard ouput");
        }
    }
    if (ch != '\n') {
        if (write(STDOUT_FILENO, "\n", 1) == -1 || errno == 28) {
            error("error writing '%s'", "standard ouput");
        }
    }
}

void read_std() {
    char ch;
    int fd = open("temp.txt", O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        error("cannot open '%s'", "temp.txt");
    }

    while (read(STDIN_FILENO, &ch, 1)) {
        write(fd, &ch, 1);
    }

    tail(fd, "standard input");
    if (close(fd) == -1) {
        error("error reading '%s'", "temp.txt");
    }
}

int main(int argc, char **argv) {
    if (argc == 1) {  // no file arguments
        read_std();
    } else {
        if (argc > 2)
            multiple_files = 1;
        char *fName;

        for (int i = 1; i < argc; i++) {  // cycle through all given files
            int fd;
            if (argv[i][0] == '-') {
                read_std();
                continue;
            } else {  // normal file
                fName = argv[i];
                fd = open(fName, O_RDONLY);
                if (fd == -1) {
                    error("cannot open '%s' for reading", fName);
                    continue;
                }
            }
            if (multiple_files &&
                i > 1) {  // apply headers only if files are > 1
                if (write(STDOUT_FILENO, "\n", 1) == -1 || errno == 28) {
                    error("error writing '%s'", "standard ouput");
                }
            }
            tail(fd, fName);
            if (close(fd) == -1) {
                error("error reading '%s'", fName);
            }
        }
    }
    return 0;
}
