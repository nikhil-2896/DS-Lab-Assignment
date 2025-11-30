#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;


void createCircular(int arr[], int n) {
    if (n == 0) return;

    head = new Node{arr[0], NULL};
    Node* temp = head;

    for (int i = 1; i < n; i++) {
        temp->next = new Node{arr[i], NULL};
        temp = temp->next;
    }
    temp->next = head; 
}

void display() {
    if (head == NULL) return;

    Node* temp = head;

    
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << head->data << " ";
}

int main() {
    int arr[] = {20, 100, 40, 80, 60};
    int n = sizeof(arr) / sizeof(arr[0]);

    createCircular(arr, n);
    display();

    return 0;
}
