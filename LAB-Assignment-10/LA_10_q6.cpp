#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

bool checkDuplicates(Node* root, unordered_set<int>& s) {
    if (root == NULL) return false;

    
    if (s.find(root->data) != s.end()) {
        return true;
    }

    s.insert(root->data);


    return checkDuplicates(root->left, s) || checkDuplicates(root->right, s);
}

int main() {
    

    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->right->left = new Node(20); 

    unordered_set<int> s;

    if (checkDuplicates(root, s))
        cout << "Duplicates Found";
    else
        cout << "No Duplicates";

    return 0;
}
