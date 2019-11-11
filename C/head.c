#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define BUFSIZE 10

int main() {
    int fd = open("a.txt", O_RDONLY);
    if (fd == -1) {
        perror("open a.txt");
        return 1;
    }

    char buf[BUFSIZE];
    ssize_t read_value;
    int count = 0;

    do {
        read_value = read(fd, buf, 1);
        if (read_value == -1) {
            perror("read a.txt");
            return 1;
        } else if (buf[strlen(buf) - 1] == '\n') {
            count++;
        }
        write(STDOUT_FILENO, buf, 1);
        if (count == 10) {
            write(STDOUT_FILENO, "\n", 1);
            return 1;
        }
    } while (read_value != 0);
    return 0;
}
