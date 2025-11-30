#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) { data = val; left = right = nullptr; }
};

bool isBST(Node* root, int minVal = INT_MIN, int maxVal = INT_MAX) {
    if (!root) return true;

    if (root->data < minVal || root->data > maxVal)
        return false;

    return isBST(root->left, minVal, root->data - 1) &&
           isBST(root->right, root->data + 1, maxVal);
}


Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;

    
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 2);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 20);

    cout << "In-order Traversal: ";
    inorder(root);
    cout << endl;

    if (isBST(root))
        cout << "The tree is a BST\n";
    else
        cout << "The tree is NOT a BST\n";

    return 0;
}
