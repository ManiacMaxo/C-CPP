#include <stdio.h>
#include <stdlib.h>

struct stack_t {
    int size;
    int capacity;
    int *data;
};

void init(struct stack_t *s) {
    s->size = 0;
    s->capacity = 2;
    s->data = malloc(s->capacity * sizeof(int));
}

void push(struct stack_t *s, int num) {
    if (s->size == s->capacity) {
        s->capacity *= 2;
        s->data = realloc(s->data, s->capacity * sizeof(int));
    }
    s->data[s->size] = num;
    s->size++;
}

int pop(struct stack_t *s) {
    int temp = s->data[--s->size];
    s->data[s->size] = 0;
    return temp;
}

void destroy(struct stack_t *s) {
    s->size = 0;
    s->capacity = 0;
    free(s->data);
    s->data = NULL;
}

int main() {
    struct stack_t s;
    push(&s, 5);
    printf("%d\n", s.size);
    printf("%d\n", pop(&s));
    printf("%d\n", s.data[0]);
    destroy(&s);
}
