#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

typedef struct {
    char data;
    unsigned char nextElAdd;
} block;

int main(int argc, char **argv) {
    char *fName = argv[1];
    int i = 0;
    int fd = open(fName, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    block temp;
    do {
        int r_val = read(fd, temp.data, 1);
        read(fd, temp.nextElAdd, 1);
        if (r_val < 0) {
            perror("read");
            return 1;
        }
        int w_val = write(STDOUT_FILENO, temp.data, 1);
        if (w_val < 0) {
            perror("write");
            return 1;
        }
        int l_val = lseek(fd, temp.nextElAdd, SEEK_SET);
        if (l_val < 0) {
            perror("seek");
            return 1;
        }
    } while (temp.nextElAdd != 0);
}
