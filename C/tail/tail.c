//------------------------------------------------------------------------
// NAME: Victor Gorchilov
// CLASS: 11a
// NUMBER: 8
// FILE NAME: tail.c (unix file name)
// FILE PURPOSE:
// implementation of tail function in c
//------------------------------------------------------------------------

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define BUFSIZE 10000

int find_start(int fd) {
    char ch = 0;
    int pos = lseek(fd, -1, SEEK_END);
    ssize_t r_value = read(fd, &ch, 1);
    if (r_value == -1) {
        perror("read");
    }

    for (int i = 0; i < 10; i++) {
        ch = 0;
        while (ch != '\n') {
            read(fd, &ch, 1);
            lseek(fd, pos--, SEEK_SET);
        }
    }
    return pos + 1;
}

void tail(int fd) {
    char buf[BUFSIZE], ch;
    ssize_t r_value, w_value;
    int idx = 0, pos = find_start(fd);
    lseek(fd, pos, SEEK_SET);
    printf("pos = %d\n", pos);

    do {
        r_value = read(fd, &ch, 1);
        if (r_value == -1) {
            perror("read");
            break;
        } else if (r_value == 0) {
            ch = '\n';
            break;
        }

        buf[idx++] = ch;
        if (ch == '\n') {
            w_value = write(STDOUT_FILENO, buf, idx);
            if (w_value == -1) {
                perror("write");
            }
            idx = 0;
        } else if (idx == BUFSIZE) {
            w_value = write(STDOUT_FILENO, buf, idx);
            if (w_value == -1) {
                perror("write");
            }
            idx = 0;
        }
    } while (42);
}

void print_header(const char *fName, int i) {
    char header[200];
    strcat(header, ((i > 1) ? "\n==> " : "==> "));
    strcat(strcat(header, fName), " <==\n");

    ssize_t w_value = write(STDOUT_FILENO, header, strlen(header));
    if (w_value == -1) {
        perror("write header");
    }
}

int main(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        char *fName = argv[i];
        if (argc > 2) {
            print_header(fName, i);
        }
        int fd = open(fName, O_RDONLY);
        if (fd == -1) {
            perror("open");
        }
        tail(fd);
    }
    return 0;
}
