#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int getSizeCLL(Node* head) {
    if (head == NULL) return 0;

    int count = 1;
    Node* temp = head->next;

    while (temp != head) {
        count++;
        temp = temp->next;
    }
    return count;
}
