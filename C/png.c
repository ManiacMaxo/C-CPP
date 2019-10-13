#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

void *read_image(const char *filepath);

int main(int argc, char **argv) {
    char *result = strstr(argv[1], ".png");
    int pos = result - argv[1];  // get position of ststsr if exists
    if (pos != strlen(argv[1]) - 4) {
        printf("Unable to parse file\n");
        return 0;
    }
    if (read_image(argv[1]) == NULL) {
        printf("Unable to open file\n");
        return 0;
    }
    struct stat st;
    stat(argv[1], &st);

    char *ptr = read_image(argv[1]);
    uint32_t w = *(uint32_t *)&ptr[18];
    uint32_t h = *(uint32_t *)&ptr[22];
    printf("PNG image width: %d\nPNG image height: %d\n", w, h);
    printf("PNG file size: %lld\n", st.st_size);
}
