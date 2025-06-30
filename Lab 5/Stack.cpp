#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next_ptr;

    Node(string name) {
        this->name = name;
        this->next_ptr = nullptr;
    }
};

class Stack {
public:
    Node* top;

    Stack() {
        top = nullptr;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(string name) {
        Node* new_node = new Node(name);
        new_node->next_ptr = top;
        top = new_node;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
        } else {
            Node* temp = top;
            top = top->next_ptr;
            delete temp; // prevent memory leak
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
        } else {
            cout << "Top element: " << top->name << endl;
        }
    }

    void display_stack() {
        Node* current = top;
        while (current != nullptr) {
            cout << current->name << " -> ";
            current = current->next_ptr;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    Stack stack;

    stack.push("Ali");
    stack.push("Ahmed");
    stack.push("Alicia");

    cout << "Stack: ";
    stack.display_stack();

    stack.pop();

    cout << "After pop: ";
    stack.display_stack();

    stack.peek();

    return 0;
}
