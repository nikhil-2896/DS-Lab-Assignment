#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};


void insert(Node*& head, int val) {
    Node* n = new Node{val, nullptr};
    if (!head) {
        head = n;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = n;
}


int deleteKey(Node*& head, int key) {
    int count = 0;

    while (head && head->data == key) {
        Node* t = head;
        head = head->next;
        delete t;
        count++;
    }

    Node* curr = head;
    while (curr && curr->next) {
        if (curr->next->data == key) {
            Node* t = curr->next;
            curr->next = curr->next->next;
            delete t;
            count++;
        } else {
            curr = curr->next;
        }
    }

    return count;
}

void print(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    // Given list: 1 2 1 2 1 3 1
    int arr[] = {1, 2, 1, 2, 1, 3, 1};
    for (int x : arr) insert(head, x);

    int key = 1;

    int cnt = deleteKey(head, key);

    cout << "Count: " << cnt << endl;
    cout << "Updated Linked List: ";
    print(head);

    return 0;
}
