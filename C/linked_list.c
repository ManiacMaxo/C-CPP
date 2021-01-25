#include <stdio.h>
#include <stdlib.h>

struct node_t {
    int data;
    struct node_t *next;
};

typedef struct {
    struct node_t *head;
    int size;
} list_t;

void init_list(list_t *list) { list->head = NULL; }

void list_destroy(list_t *list) {
    struct node_t *tmp = list->head;
    while (tmp != NULL) {
        struct node_t *free_node = tmp;
        tmp = tmp->next;
        free(free_node);
    }
    list->head = NULL;
}

int list_size(list_t list) {
    int size = 0;
    struct node_t *node = list.head;
    while (node != NULL) {
        size++;
    }
    return size;
}

void insert(list_t *list, int value) {
    struct node_t *tmp = list->head;

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }

    struct node_t *new_node = {
        value,
        NULL,
    };
}

void empty(list_t *list) {}

int main() {
    list_t list;
    init_list(&list);

    printf("size = %d\n", list_size(list));

    list_destroy(&list);
}
