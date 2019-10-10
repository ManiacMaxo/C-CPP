#include <stdint.h>
#include <stdio.h>

void *read_image(const char *filepath);

int main(int argc, char **argv) {
    char *ptr = read_image(argv[1]);
    uint32_t w = *(uint32_t *)&ptr[18];
    uint32_t h = *(uint32_t *)&ptr[22];
    printf("BMP image width: %d\nBMP image height: %d\n", w, h);
}
