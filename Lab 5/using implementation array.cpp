#include <iostream>
#include <string>
using namespace std;

class ArrayStack {
private:
    static const int MAX = 100; // maximum size of the array
    string names[MAX];          // array to store elements
    int top;                    // index of the top element

public:
    ArrayStack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(string name) {
        if (top >= MAX - 1) {
            cout << "Stack overflow! Cannot push '" << name << "'." << endl;
            return;
        }
        top++;
        names[top] = name;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
        } else {
            top--;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
        } else {
            cout << "Top element: " << names[top] << endl;
        }
    }

    void display_stack() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }

        for (int i = top; i >= 0; i--) {
            cout << names[i] << " -> ";
        }
        cout << "NULL" << endl;
    }
};

int main() {
    ArrayStack stack;

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
