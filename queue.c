#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    node_t *next;
} node_t;

typedef struct {
    node_t *first;
    int size;
} queue_t;

void init_queue(queue_t *queue) {
    queue->size = 0;
    queue->first = NULL;
}

void push(queue_t *queue, node_t *node) {
    node_t *temp = queue->first;
    queue->size++;
    queue->first = node;
    queue->first->next = temp;
}

int main() {
}