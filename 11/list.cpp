#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct {
    int value;
    node_t *next;
} node_t;

class List {
    node_t *head;

   public:
    List() {
        head = NULL;
    }
    /* void init() {
        head = NULL;
    } */
};

int main() {
    List l1;
    return 0;
}
