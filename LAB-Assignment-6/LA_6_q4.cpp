#include <iostream>
using namespace std;

struct Node {
    char data;
    Node *prev, *next;
};

Node* insertEnd(Node* head, char x) {
    Node* n = new Node{x, NULL, NULL};
    if (!head) return n;
    Node* t = head;
    while (t->next) t = t->next;
    t->next = n;
    n->prev = t;
    return head;
}

bool isPalindrome(Node* head) {
    if (!head || !head->next) return true;

    Node *l = head, *r = head;

    
    while (r->next) r = r->next;

    
    while (l != r && r->next != l) {
        if (l->data != r->data) return false;
        l = l->next;
        r = r->prev;
    }
    return true;
}

int main() {
    Node* head = NULL;

    
    string s = "RADAR";

    for (char c : s) head = insertEnd(head, c);

    if (isPalindrome(head))
        cout << "Palindrome";
    else
        cout << "Not Palindrome";

    return 0;
}
