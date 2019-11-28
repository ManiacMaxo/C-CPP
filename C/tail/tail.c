#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define BUFSIZE 10000

int find_start(int fd) {
    printf("entered find start\n");
    printf("%lld\n", lseek(fd, 0, SEEK_END));
    char ch = 0;
    ssize_t r_value = read(fd, &ch, 1);
    if (r_value == -1) {
        perror("read");
    }

    int pos;
    for (int i = 0; i < 10; i++) {
        ch = 0;
        while (ch != '\n') {
            read(fd, &ch, 1);
        }
        pos = fd;
    }
    printf("exited find start\n");
    return pos + 1;
}

void tail(int fd) {
    printf("in tail func\n");
    char buf[BUFSIZE], ch;
    ssize_t r_value, w_value;
    int cnt = 0, idx = 0, pos = find_start(fd);
    lseek(fd, pos, SEEK_SET);

    do {
        r_value = read(fd, &ch, 1);
        if (r_value == -1) {
            perror("read");
            break;
        } else if (r_value == 0) {
            ch = '\n';
        }

        buf[idx++] = ch;
        if (ch == '\n') {
            w_value = write(STDOUT_FILENO, buf, idx);
            if (w_value == -1) {
                perror("write");
            }
            idx = 0;
            if (++cnt == 10) {
                break;
            }
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
    char *full = ((i > 1) ? "\n==> " : "==> ");
    strcat(strcat(full, fName), " <==\n");
    ssize_t w_value = write(STDOUT_FILENO, full, strlen(full));
    if (w_value == -1) {
        perror("write header");
    }
}

int main(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        printf("%d\n", i);
        char *fName = argv[i];
        // print_header(fName, i);
        int fd = open(fName, O_RDONLY);
        if (fd == -1) {
            perror("open");
        }
        tail(fd);
    }
    return 0;
}
