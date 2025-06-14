/*
id: 22010126
name: muni
group: g3
lab: L3
*/
#include <iostream>
#include <string>

using namespace std;

struct Node {
    string name;
    Node* next_pointer; // Pointer to the next Node
    Node* prev_pointer; // Pointer to the previous Node

    // Constructor to initialize Node
    Node(string n) : name(n), next_pointer(nullptr), prev_pointer(nullptr) {}
};

class Linkedlist {
    Node* head; // Pointer to the head of the list
    Node* tail; // Pointer to the tail of the list

public:
    Linkedlist() : head(nullptr), tail(nullptr) {} // Constructor to initialize head and tail

    void insert_node(Node* node) {
        if (head == nullptr) {
            // First node
            head = tail = node;
        } else {
            // Append at the end
            tail->next_pointer = node;
            node->prev_pointer = tail;
            tail = node;
        }
    }

    void display_list() {
        Node* currNode = head;
        while (currNode != nullptr) {
            cout << currNode->name << " ";
            currNode = currNode->next_pointer;
        }
        cout << endl;
    }

    void display_list_reverse() {
        Node* currNode = tail;
        while (currNode != nullptr) {
            cout << currNode->name << " ";
            currNode = currNode->prev_pointer;
        }
        cout << endl;
    }
};

int main() {
    // Create nodes
    Node* node1 = new Node("Ali");
    Node* node2 = new Node("Alice");
    Node* node3 = new Node("Ahmed");

    Linkedlist std_names;

    std_names.insert_node(node1);
    std_names.insert_node(node2);
    std_names.insert_node(node3);

    cout << "Forward traversal: ";
    std_names.display_list(); // Display the list forward

    cout << "Reverse traversal: ";
    std_names.display_list_reverse(); // Display the list backward

    // Clean up memory (optional, but recommended)
    delete node1;
    delete node2;
    delete node3;

    return 0;
}

