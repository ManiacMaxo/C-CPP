// ------------------------------------------------------------------------
// NAME: Victor Gorchilov
// CLASS: 11a
// NUMBER: 8
// PROBLEM: #6
// FILE NAME: stack.c (unix file name)
// FILE PURPOSE: creating stack
// ------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    size_t size;
    size_t capacity;
    int *elements;
} stack;

void stack_init(stack *s) {
    //------------------------------------------------------------------------
    // FUNCTION: stack_init
    // create a stack
    // PARAMETERS:
    // stack
    //------------------------------------------------------------------------
    s->size = 0;
    s->capacity = 50;
    s->elements = malloc(s->capacity * sizeof(int));
}

void stack_destroy(stack *s) {
    //------------------------------------------------------------------------
    // FUNCTION:
    // destroy stack
    // PARAMETERS:
    // stack to destroy
    //------------------------------------------------------------------------
    s->size = 0;
    s->capacity = 0;
    free(s->elements);
}

int stack_empty(stack *s) {
    return !s->size;
}

void stack_push(stack *s, int num) {
    //------------------------------------------------------------------------
    // FUNCTION: stack_push
    // append a new element to the top of the stack
    // PARAMETERS:
    // stack and element to append
    //------------------------------------------------------------------------
    if (s->size == s->capacity) {
        s->capacity *= 2;
        s->elements = realloc(s->elements, s->capacity * sizeof(int));
    }
    s->elements[s->size++] = num;
}

int stack_top(stack *s) {
    //------------------------------------------------------------------------
    // FUNCTION: stack_top
    // return the top element of the stack
    // PARAMETERS:
    // stack
    //------------------------------------------------------------------------
    if (s->size) {
        return s->elements[s->size - 1];
    }
    return 0;
}

int stack_pop(stack *s) {
    //------------------------------------------------------------------------
    // FUNCTION: stack_pop
    // remove and return top element
    // PARAMETERS:
    // stack to remove element from
    //------------------------------------------------------------------------
    return s->elements[--s->size];
}

int main() {
    stack s;
    stack_init(&s);
    stack_push(&s, 1);
    stack_push(&s, 3);
    stack_push(&s, 5);
    printf("%zu\t%d\n", s.size, stack_pop(&s));
    printf("%zu\t%d\n", s.size, stack_pop(&s));
    printf("%zu\t%d\n", s.size, stack_pop(&s));
    stack_destroy(&s);
}
