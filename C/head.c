#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFSIZE 100000
#define LINES 10

int main() {
    int fd = open("a.txt", O_RDONLY);
    if (fd == -1) {
        perror("open a.txt");
        return 1;
    }

    char buf[BUFSIZE], ch;
    ssize_t read_value;
    int cnt = 0, idx = 0;

    do {
        read_value = read(fd, &ch, 1);
        if (read_value == -1) {
            perror("read");
            return 1;
        } else if (read_value == 0) {  // end of file with no new line
            ch = '\n';                 // just set a new line. the loop will break due to read_value == 0
        }

        buf[idx++] = ch;
        if (ch == '\n') {
            write(STDOUT_FILENO, buf, idx);
            idx = 0;
            if (++cnt == LINES) {
                break;
            }
        } else if (idx == BUFSIZE) {
            write(STDOUT_FILENO, buf, idx);
            idx = 0;
        }
    } while (read_value != 0);

    close(fd);

    return 0;
}
