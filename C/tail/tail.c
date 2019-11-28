#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define BUFSIZE 10000
#define LINES 10


void tail(int fd) {
    char buf[BUFSIZE], ch;
    ssize_t read_value, write_value;
    int cnt = 0, idx = 0;

    

    lseek(fd, pos, SEEK_SET);
    do {
        read_value = read(fd, &ch, 1);
        if (read_value == -1) {
            perror("read");
            break;
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
    }while(42);
}

int find_start(int fd, int pos) {
    lseek(fd, pos-1, SEEK_SET);
    char ch = 0;
    int i;
    read(fd, &ch, 1);
    for (int i = 0; i < 10; i++) {
        ch = 0;
        while (ch != '\n') {
            read(fd, &ch, 1);
            pos = fd - 1;
        }
    }
    return pos;
}

void print_header(const char *fName, int i) {
    char *full = ((i > 1) ? "\n==> " : "==> ");
    strcat(strcat(full, fName), " <==\n");
    write(STDOUT_FILENO, full, strlen(full));
}

void test(int fd) {
    char ch;
    read(fd, &ch, 1);
    printf("%c\n", ch);
    lseek(fd, 20, SEEK_SET);
    printf("%d\n", fd);
}

int main(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        char *fName = argv[i];
        int fd = open(fName, O_RDONLY);
        if (fd == -1) {
            perror("open");
            return 1;
        }
        
    }
    
}
