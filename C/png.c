#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

void *read_image(const char *filepath);

int main(int argc, char **argv) {
    if (argv[1] == NULL || read_image(argv[1]) == NULL) {  // does the file exist
        printf("Unable to open file\n");
        return 0;
    }
    char *find = strstr(argv[1], ".png");
    int pos = find - argv[1];          // get position of ststsr if exists
    if (pos != strlen(argv[1]) - 4) {  // is the file a png
        printf("Unable to parse file\n");
        return 0;
    }

    struct stat st;
    stat(argv[1], &st);  // size of file in bits

    char *ptr = read_image(argv[1]);
    int w = ntohl(*(uint32_t *)&ptr[16]);
    int h = ntohl(*(uint32_t *)&ptr[20]);
    printf("PNG image width: %d\nPNG image height: %d\n", w, h);
    printf("PNG file size: %lld\n", st.st_size);
}
