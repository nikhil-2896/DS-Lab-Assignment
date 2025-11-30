#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    int findMiddle() {
        if (!head) {
            cout << "List is empty\n";
            return -1;
        }

        Node* slow = head;
        Node* fast = head;

        while (fast && fast->next) {
            slow = slow->next;          
            fast = fast->next->next;    
        }

        return slow->data;  
    }
};

int main() {
    LinkedList list;
    int n, x;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        list.insert(x);
    }

    cout << "Middle element: " << list.findMiddle();

    return 0;
}
