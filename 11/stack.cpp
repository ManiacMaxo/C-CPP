#include <iostream>
#include <string>
using namespace std;
const int STACK_SIZE = 10;

class stack_is_full {};
class stack_is_empty {};

class Stack_exeption {
    string message = "";

   public:
    Stack_exeption(string message) {
        this->message = message;
    }

    string what() {
        return message;
    }
};

class Stack {
    int data[STACK_SIZE];
    int top;

   public:
    Stack() {
        top = 0;
    };
    void push(int value) {
        if (is_full) {
            throw stack_is_full();
        }
        data[top++] = value;
    }

    int pop() {
        return data[--top];
        if (is_empty) {
            throw stack_is_empty();
        }
    }

    bool is_empty() {
        return top == 0;
    }

    bool is_full() {
        return top == STACK_SIZE;
    }
};

main() {
    Stack s;
    try {
        for (int i = 0; i < 12; i++) {
            s.push(i);
        }
    } catch (stack_is_full ex) {
        cout << "Stack is full" << endl;
    }
}
