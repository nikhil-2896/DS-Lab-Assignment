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
    else if (val > root->data) root->right = insert(root->right, val);
    else cout << "Duplicate value not allowed: " << val << endl;
    return root;
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left) current = current->left;
    return current;
}

Node* deleteNode(Node* root, int key) {
    if (!root) return root;

    if (key < root->data) root->left = deleteNode(root->left, key);
    else if (key > root->data) root->right = deleteNode(root->right, key);
    else {
        
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int maxDepth(Node* root) {
    if (!root) return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return 1 + max(leftDepth, rightDepth);
}

int minDepth(Node* root) {
    if (!root) return 0;
    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);


    if (!root->left) return 1 + rightDepth;
    if (!root->right) return 1 + leftDepth;

    return 1 + min(leftDepth, rightDepth);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    int choice, val;

    while (true) {
        cout << "\n1. Insert\n2. Delete\n3. Maximum Depth\n4. Minimum Depth\n5. Display (Inorder)\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                root = insert(root, val);
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> val;
                root = deleteNode(root, val);
                break;

            case 3:
                cout << "Maximum Depth: " << maxDepth(root) << endl;
                break;

            case 4:
                cout << "Minimum Depth: " << minDepth(root) << endl;
                break;

            case 5:
                cout << "In-order Traversal: ";
                inorder(root);
                cout << endl;
                break;

            case 6:
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }
}
