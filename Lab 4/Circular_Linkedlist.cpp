/*
id: 22010126
name: muni
group: g3
lab: L4
*/

#include <iostream>
#include <string>

using namespace std;

struct Node {
    string name;
    Node* next_pointer; // Pointer to the next Node

    //to initialize Node
    Node(string n) : name(n), next_pointer(nullptr) {}
};

class Linkedlist {
    Node* head; // Pointer to the head of the list

public:
    Linkedlist() : head(nullptr) {} // initialize head

    void insert_node(Node* node) {
        if (head == nullptr) {
            head = node; // If list is empty, set head to the new node
            head -> next_pointer = head;
        } else {
            Node* currNode = head;
            while (currNode->next_pointer != head) {
                currNode = currNode->next_pointer; // Traverse to the end of the list
            }
            currNode->next_pointer = node; // Link the new node
            node -> next_pointer = head; //circular link
        }
    }

    void display_list() {
        if(head == nullptr){ return; }
        
        Node* currNode = head;
        do{
            cout << currNode->name << " -> "; // Print the name of the current node
            currNode = currNode->next_pointer; // Move to the next node
        }while(currNode != head);
        
        cout << head -> name << endl;
        
    }
};

int main() {
    // Create nodes
    Node* node1 = new Node("Ali");
    Node* node2 = new Node("Alice");
    Node* node3 = new Node("Ahmed");
    Node* node4 = new Node("Hamed");

    Linkedlist std_names;

    std_names.insert_node(node1);
    std_names.insert_node(node2);
    std_names.insert_node(node3);
    std_names.insert_node(node4);

    std_names.display_list(); // Display the list


    return 0;
}