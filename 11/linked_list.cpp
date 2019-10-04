#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct node_t {
    int value;
    struct node_t *next;
};

class full_list : exception {};

class empty_list : exception {};

class value_max : exception {};

class List {
    struct node_t *head;
    int size, max_size, max_value;

   public:
    List() {
        head = NULL;
        size = 1;
        max_size = 10;
        max_value = INT_MAX;
    }

    List(int m_size, int m_value) {
        head = NULL;
        size = 1;
        max_size = m_size;
        max_value = m_value;
    }

    int is_empty() {
        return head == NULL;
    }

    void push(int value) {
        if (size == max_size) {
            throw full_list();
        }

        if (value > max_value) {
            throw value_max();
        }

        struct node_t *new_node = (struct node_t *)malloc(sizeof(struct node_t));
        new_node->value = value;
        new_node->next = NULL;
        if (is_empty()) {
            head = new_node;
            return;
        }
        struct node_t *current_node = head;
        while (current_node->next) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
        size++;
    }

    int pop() {
        if (is_empty()) {
            throw empty_list();
        }
        struct node_t *current_node = head;
        struct node_t *prev_node = NULL;
        while (current_node->next) {
            prev_node = current_node;
            current_node = current_node->next;
        }
        if (prev_node) {
            prev_node->next = NULL;
        } else {
            head = NULL;
        }
        return current_node->value;
    }
};

int main() {
    List l1 = List(10, 1000);

    int i, j = 1;
    try {
        while (42) {
            try {
                i = rand() % 2000 + 1;
                cout << j++ << " : " << i << endl;
                l1.push(i);
            } catch (value_max ex) {
                cout << "Value too large" << endl;
                j--;
            }
        }
    } catch (full_list ex2) {
        cout << "List is full" << endl;
    }
    /* 
    try {
        while (42) {
            int value = l1.pop();
            cout << value << endl;
        }
    } catch (empty_list ex) {
        cout << "List is empty" << endl;
    }
    */

    return 0;
}
