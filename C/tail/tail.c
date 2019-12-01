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

void merror(char *err_msg, char *fName) {
    char buf1[255], buf2[255];
    sprintf(buf1, err_msg, fName);
    sprintf(buf2, "tail: %s", buf1);
    perror(buf2);
}

void print_header(const char *fName) {
    char header[255];
    sprintf(header, "==> %s <==\n", fName);
    if (write(STDOUT_FILENO, header, strlen(header)) == -1) {
        merror("error writing '%'", "standart ouput");
    }
}

int find_start(int fd, char *fName) {
    char ch;
    int i = 0;
    int pos = lseek(fd, -2, SEEK_END);
    if (pos == -1) {
        merror("error seeking '%s'", fName);
        return -1;
    }
    do {
        if (read(fd, &ch, 1) == -1) {
            merror("error reading '%s'", fName);
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
    char ch;
    int pos = find_start(fd, fName);
    if (pos == -1) {
        return;
    }
    if (lseek(fd, pos, SEEK_SET) == -1) {
        merror("error seeking %s", fName);
        return;
    };

    if (multiple_files) {
        print_header(fName);
    }
    while (read(fd, &ch, 1) > 0) {
        if (write(STDOUT_FILENO, &ch, 1) == -1) {
            merror("error writing '%'", "standart ouput");
        }
    }
    if (ch != '\n') {
        if (write(STDOUT_FILENO, "\n", 1) == -1) {
            merror("error writing '%'", "standart ouput");
        }
    }
}

int main(int argc, char **argv) {
    if (argc == 1) {
        tail(STDIN_FILENO, "standart input");
    } else {
        if (argc > 2) multiple_files = 1;
        char *fName;
        for (int i = 1; i < argc; i++) {
            if (argc > 2) {
                if (i > 1) {
                    if (write(STDOUT_FILENO, "\n", 1) == -1) {
                        merror("error writing '%'", "standart ouput");
                    }
                }
            }

            int fd;
            if (argv[i][0] == '-') {
                fd = STDIN_FILENO;
                fName = "standart input";
            } else {
                fName = argv[i];
                // struct stat sb;
                // if (stat(fName, &sb) == -1) {
                //     merror("error reading '%s'", fName);
                //     continue;
                // }
                // if (S_ISDIR(sb.st_mode)) {
                //     merror("error reading '%s'", fName);
                //     continue;
                // }
                fd = open(fName, O_RDONLY);
                if (fd == -1) {
                    merror("cannot open '%s' for reading", fName);
                    continue;
                }
            }

            tail(fd, fName);
            if (fd != STDIN_FILENO) {
                if (close(fd) == -1) {
                    merror("error reading '%s'", fName);
                }
            }
        }
    }
    return 0;
}
