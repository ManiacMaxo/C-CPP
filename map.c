#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node_t {
    char *key;
    int value;
};
typedef struct node_t node_t;

struct map_t {
    node_t *nodes;
    int size;
    int capacity;
};
typedef struct map_t map_t;

void init_map(map_t *map) {
    map->size = 0;
    map->capacity = 1;
    map->nodes = malloc(sizeof(node_t) * map->capacity);
}

int main() {
    node_t n;

    return 0;
}
