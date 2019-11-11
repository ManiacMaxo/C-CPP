#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFSIZE 1000

int main(int argc, char **argv) {
    ssize_t write_value, read_value;
    char buf[BUFSIZE];

    int fd = open("a.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    read_value = read(fd, buf, BUFSIZE);
    if (read_value == -1) {
        perror("read a.txt");
        return 1;
    }
    printf("%ld\n", read_value);

    write_value = write(STDOUT_FILENO, buf, read_value);
    if (write_value == -1) {
        perror("write a.txt");
        return 1;
    }

    int close_result = close(fd);
    if (close_result == -1) {
        perror("close a.txt");
        return 1;
    }

    return 0;
}
