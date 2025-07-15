/*
id: 22010126
name: muni
group: G4
lab: Lab G6*/

#include <iostream>
using namespace std;

class Queue {
public:
    string names[50];  
    int front = 0;
    int rear = -1;
    int count = 0;

    void enqueue(string value) {
        if (count == 50) {
            cout << "Queue is full" << endl;
            return;
        }
        rear = (rear + 1);  
        names[rear] = value;
        count++;
    }

    void dequeue() {
        if (count == 0) {
            cout << "Queue is empty" << endl;
            return;
        }
        front = (front + 1);  
        count--;
    }

    string peek() {
        if (count == 0) return "nothing in queue";
        return names[front];
    }

    void display() {
        if (count == 0) {
            cout << "notning in queue" << endl;
            return;
        }
        for (int i = 0; i < count; i++) {
            int index = (front + i);
            cout << names[index];
            if (i < count - 1) cout << " -> ";
        }
        cout << " -> NULL" << endl;
    }
};

int main() {
    Queue q;
    
    q.enqueue("Ali");
    q.enqueue("Bob");
    q.enqueue("Caca");
    q.display(); 
    
    cout << "Peek: " << q.peek() << endl;  
    
    q.dequeue();
    q.display(); 
    
    q.dequeue();
    q.dequeue();
    q.display();  
}