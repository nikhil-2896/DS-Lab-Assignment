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
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    
    void insertAtBeg(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // (b) Insert at end
    void insertAtEnd(int val) {
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

    
    void insertBefore(int key, int val) {
        if (!head) return;
        if (head->data == key) {
            insertAtBeg(val);
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->data != key)
            temp = temp->next;

        if (!temp->next) {
            cout << "Key not found\n";
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void insertAfter(int key, int val) {
        Node* temp = head;
        while (temp && temp->data != key)
            temp = temp->next;

        if (!temp) {
            cout << "Key not found\n";
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    
    void deleteBeg() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    
    void deleteEnd() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        if (!head->next) {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        while (temp->next->next)
            temp = temp->next;

        delete temp->next;
        temp->next = NULL;
    }

    void deleteNode(int key) {
        if (!head) {
            cout << "List is empty\n";
            return;
        }

        if (head->data == key) {
            deleteBeg();
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->data != key)
            temp = temp->next;

        if (!temp->next) {
            cout << "Key not found\n";
            return;
        }

        Node* del = temp->next;
        temp->next = temp->next->next;
        delete del;
    }

    void searchNode(int key) {
        Node* temp = head;
        int pos = 1;

        while (temp) {
            if (temp->data == key) {
                cout << "Node found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node not found\n";
    }

    void display() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int choice, val, key;

    while (true) {
        cout << "\n1. Insert at Beginning\n2. Insert at End\n3. Insert Before\n4. Insert After\n";
        cout << "5. Delete from Beginning\n6. Delete from End\n7. Delete Specific Node\n";
        cout << "8. Search Node\n9. Display List\n10. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                list.insertAtBeg(val);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> val;
                list.insertAtEnd(val);
                break;

            case 3:
                cout << "Insert before which value? ";
                cin >> key;
                cout << "Enter new value: ";
                cin >> val;
                list.insertBefore(key, val);
                break;

            case 4:
                cout << "Insert after which value? ";
                cin >> key;
                cout << "Enter new value: ";
                cin >> val;
                list.insertAfter(key, val);
                break;

            case 5:
                list.deleteBeg();
                break;

            case 6:
                list.deleteEnd();
                break;

            case 7:
                cout << "Enter value to delete: ";
                cin >> key;
                list.deleteNode(key);
                break;

            case 8:
                cout << "Enter value to search: ";
                cin >> key;
                list.searchNode(key);
                break;

            case 9:
                list.display();
                break;

            case 10:
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }
}
