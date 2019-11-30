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
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int find_start(int fd) {
    char ch;
    int i = 0;
    int pos = lseek(fd, -2, SEEK_END);
    do {
        if (read(fd, &ch, 1) == -1) {
            perror("read");
        }
        if (ch == '\n') {
            i++;
        }
        if (lseek(fd, --pos, SEEK_SET) == -1) {
            perror("seek");
        }
    } while (i < 10);
    return pos + 2;
}

void tail(int fd) {
    char ch;
    lseek(fd, find_start(fd), SEEK_SET);

    while (read(fd, &ch, 1) > 0) {
        if (write(STDOUT_FILENO, &ch, 1) == -1) {
            perror("write");
        }
    }
    if (ch != '\n')
        if (write(STDOUT_FILENO, "\n", 1) == -1)
            perror("write");
}

void print_header(const char *fName) {
    char header[255];
    sprintf(header, "==> %s <==\n", fName);
    if (write(STDOUT_FILENO, header, strlen(header)) == -1) {
        perror("write header");
    }
}

int main(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        char *fName = argv[i];
        if (argc > 2) {
            if (i > 1) {
                write(STDOUT_FILENO, "\n", 1);
            }
            print_header(fName);
        }

        if (argv[i][0] == '-') {
            continue;
        }

        int fd = open(fName, O_RDONLY);
        if (fd == -1) {
            perror("open");
        }
        tail(fd);
    }
    return 0;
}
