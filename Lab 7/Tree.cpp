/*
id: 22010126
name: muni
group: G3
lab: Lab G7*/

#include <iostream>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string n) {
        name = n;
        left = nullptr;
        right = nullptr;
    }
};

class Tree {
public:
    Node* root;

    Tree() {
        root = nullptr;
    }

    void add_root(string name) {
        root = new Node(name);
    }

    Node* find_node(Node* node, string name) {
        if (!node) return nullptr;
        if (node->name == name) return node;

        Node* found = find_node(node->left, name);
        if (found) return found;

        return find_node(node->right, name);
    }

    void add_left(string parent_name, string child_name) {
        Node* parent = find_node(root, parent_name);
        if (parent) {
            parent->left = new Node(child_name);
        }
    }

    void add_right(string parent_name, string child_name) {
        Node* parent = find_node(root, parent_name);
        if (parent) {
            parent->right = new Node(child_name);
        }
    }
};

int main() {
    Tree tree;

    tree.add_root("A");
    tree.add_left("A", "B");
    tree.add_right("A", "C");
    tree.add_left("B", "D");
    tree.add_right("B", "E");
    tree.add_left("C", "F");
    tree.add_right("C", "G");

    cout << "Root: " << tree.root->name << endl;
    cout << "Left child of root: " << tree.root->left->name << endl;
    cout << "Right child of root: " << tree.root->right->name << endl;
    cout << "Left child of B: " << tree.root->left->left->name << endl;
    cout << "Right child of B: " << tree.root->left->right->name << endl;
    cout << "Left child of C: " << tree.root->right->left->name << endl;
    cout << "Right child of C: " << tree.root->right->right->name << endl;

    return 0;
}
