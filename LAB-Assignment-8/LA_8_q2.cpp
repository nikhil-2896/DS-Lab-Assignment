#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) { data = val; left = right = nullptr; }
};

Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

bool searchRecursive(Node* root, int key) {
    if (!root) return false;
    if (root->data == key) return true;
    if (key < root->data) return searchRecursive(root->left, key);
    return searchRecursive(root->right, key);
}

bool searchIterative(Node* root, int key) {
    while (root) {
        if (root->data == key) return true;
        root = (key < root->data) ? root->left : root->right;
    }
    return false;
}

int findMax(Node* root) {
    while (root && root->right) root = root->right;
    return root ? root->data : -1;
}

int findMin(Node* root) {
    while (root && root->left) root = root->left;
    return root ? root->data : -1;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node* inorderSuccessor(Node* root, Node* target) {
    Node* succ = nullptr;
    while (root) {
        if (target->data < root->data) {
            succ = root;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return succ;
}

Node* inorderPredecessor(Node* root, Node* target) {
    Node* pred = nullptr;
    while (root) {
        if (target->data > root->data) {
            pred = root;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return pred;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 25);
    root = insert(root, 35);

    cout << "Search 15 (recursive): " << searchRecursive(root, 15) << endl;
    cout << "Search 40 (iterative): " << searchIterative(root, 40) << endl;

    cout << "Max: " << findMax(root) << ", Min: " << findMin(root) << endl;

    Node* target = root->left; // Node with value 10
    Node* succ = inorderSuccessor(root, target);
    Node* pred = inorderPredecessor(root, target);

    cout << "Inorder Successor of " << target->data << ": " 
         << (succ ? succ->data : -1) << endl;
    cout << "Inorder Predecessor of " << target->data << ": " 
         << (pred ? pred->data : -1) << endl;

    cout << "In-order Traversal: ";
    inorder(root);
}
