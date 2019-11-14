#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define BUFSIZE 1024

int main(int argc, char **argv) {
    printf("%s\n", argv[2]);
    for (int i = 1; i < argc; i++) {
        printf("i = %d\n", i);
        char *fName = argv[i];
        int fd = open(fName, O_RDONLY);
        // header
        strcat(fName, " <==\n");
        write(STDOUT_FILENO, "==> ", 4);
        write(STDOUT_FILENO, fName, strlen(fName));
        if (fd == -1) {
            perror("open file");
            continue;
        }

        char buf[BUFSIZE];
        ssize_t read_value;
        int count = 0;

        do {
            char ch = '\0';
            read_value = read(fd, &ch, 1);
            printf("%c", ch);
            if (read_value == -1) {
                perror("read file");
                break;
            } else if (ch == '\n') {  // end conditions
                count++;
                buf[strlen(buf) - 1] = ch;
                buf[strlen(buf) - 1] = '\0';
                write(STDOUT_FILENO, buf, strlen(buf));
                // printf("lines: %d\n", count);
            } else {
                buf[strlen(buf) - 1] = ch;
            }
            if (count == 10) {  // number of lines
                write(STDOUT_FILENO, "\n", 1);
                break;
            }
        } while (read_value != 0);
    }
    return 0;
}
