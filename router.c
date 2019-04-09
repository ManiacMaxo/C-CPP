#include <stdio.h>
#include <string.h>

typedef struct {
    char data[255];
    char source[30];
    char destination[30];
} packet_t;

void swap(packet_t *A, packet_t *B) {
    packet_t temp = *A;
    *A = *B;
    *B = temp;
}    

void sort_ascending(packet_t *packets) {
    packet_t temp;
    int swapped = 0;
    for (int i = 0; i < 9; i++) {
        swapped = 0;
        for (int j = 0; j < i - 1; j++) {
            if (strlen(packets[j].data) > strlen(packets[j + 1].data)) {
                swap(packets[j], packets[j+1]);
                swapped = 1;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

int main() {
    packet_t packets[10];
    printf("Source\tDestination\tContent\n");
    for (int i = 0; i < 10; i++) {
        scanf("%s %s", &packets[i].source, &packets[i].destination);
        fgets(packets[i].data, 255, stdin);
    }
    sort_ascending(packets);
    printf("sending out packets...\n");
    for (int i = 0; i < 10; i++) {
        printf("From: %s to: %s\t%s", packets[i].source, packets[i].destination, packets[i].data);
    }
}
