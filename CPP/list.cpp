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
    int is_empty() {
        return head == NULL;
    }
};

int main() {
    List l1;
    cout << l1.is_empty() << endl;
    return 0;
}
