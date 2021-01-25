#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char data[255];
    char src[30];
    char dst[30];
} packet_t;

int my_cmp(const packet_t *f, const packet_t *s) {
    return (strlen(f->data) - strlen(s->data));
}

int main() {
    while (42) {
        packet_t *packets = malloc(10 * sizeof(packet_t));
        printf("Source\tDestination\tContent\n");
        for (int i = 0; i < 10; i++) {
            scanf("%s %s", packets[i].src, packets[i].dst);
            fgets(packets[i].data, 255, stdin);
        }

        qsort(packets, 10, sizeof(packet_t), my_cmp);
        printf("sending out packets...\n");
        for (int i = 0; i < 10; i++) {
            printf("From: %s\tTo: %s\tContent: %s", packets[i].src,
                   packets[i].dst, packets[i].data);
        }
        free(packets);
    }
}
