#include <stdio.h>
#include <string.h>

typedef struct {
    char data[255];
    char source[30];
    char destination[30];
} packet_t;

void sort_ascending(packet_t *packets) {
    packet_t temp;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < i - 1; j++) {
            if (strlen(packets[j].data) > strlen(packets[j + 1].data)) {
                temp = packets[j];
                packets[j] = packets[j + 1];
                packets[j + 1] = temp;
            }
        }
    }
}

int main() {
    packet_t packets[10];
    for (int i = 0; i < 10; i++) {
        printf("Source\tDestination\tContent");
        scanf("%s %s", &packets[i].source, packets[i].destination);
        fgets(packets[i].data, 255, stdin);
    }
}
