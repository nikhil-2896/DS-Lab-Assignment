#include <iostream>
using namespace std;


class DList {
    struct Node {
        int data;
        Node *prev, *next;
        Node(int v) : data(v), prev(NULL), next(NULL) {}
    };
    Node *head;

public:
    DList() { head = NULL; }

    void insertFirst(int v) {
        Node *n = new Node(v);
        if (!head) head = n;
        else {
            n->next = head;
            head->prev = n;
            head = n;
        }
    }

    void insertLast(int v) {
        Node *n = new Node(v);
        if (!head) { head = n; return; }
        Node *t = head;
        while (t->next) t = t->next;
        t->next = n;
        n->prev = t;
    }

    void insertAfter(int key, int v) {
        Node *t = head;
        while (t && t->data != key) t = t->next;
        if (!t) return;
        Node *n = new Node(v);
        n->next = t->next;
        n->prev = t;
        if (t->next) t->next->prev = n;
        t->next = n;
    }

    void insertBefore(int key, int v) {
        if (!head) return;
        if (head->data == key) { insertFirst(v); return; }
        Node *t = head;
        while (t && t->data != key) t = t->next;
        if (!t) return;
        Node *n = new Node(v);
        n->next = t;
        n->prev = t->prev;
        t->prev->next = n;
        t->prev = n;
    }

    void deleteNode(int key) {
        Node *t = head;
        while (t && t->data != key) t = t->next;
        if (!t) return;

        if (t == head) head = head->next;
        if (t->next) t->next->prev = t->prev;
        if (t->prev) t->prev->next = t->next;

        delete t;
    }

    bool search(int key) {
        Node *t = head;
        while (t) {
            if (t->data == key) return true;
            t = t->next;
        }
        return false;
    }

    void display() {
        Node *t = head;
        while (t) {
            cout << t->data << " ";
            t = t->next;
        }
        cout << endl;
    }
};

class CList {
    struct Node {
        int data;
        Node *next;
        Node(int v) : data(v), next(NULL) {}
    };
    Node *head;

public:
    CList() { head = NULL; }

    void insertFirst(int v) {
        Node *n = new Node(v);
        if (!head) {
            head = n;
            n->next = n;
        } else {
            Node *t = head;
            while (t->next != head) t = t->next;
            n->next = head;
            t->next = n;
            head = n;
        }
    }

    void insertLast(int v) {
        Node *n = new Node(v);
        if (!head) {
            head = n; n->next = n; return;
        }
        Node *t = head;
        while (t->next != head) t = t->next;
        t->next = n;
        n->next = head;
    }

    void insertAfter(int key, int v) {
        if (!head) return;
        Node *t = head;
        do {
            if (t->data == key) {
                Node *n = new Node(v);
                n->next = t->next;
                t->next = n;
                return;
            }
            t = t->next;
        } while (t != head);
    }

    void insertBefore(int key, int v) {
        if (!head) return;
        if (head->data == key) { insertFirst(v); return; }
        Node *t = head;
        do {
            if (t->next->data == key) {
                Node *n = new Node(v);
                n->next = t->next;
                t->next = n;
                return;
            }
            t = t->next;
        } while (t != head);
    }

    void deleteNode(int key) {
        if (!head) return;
        Node *t = head, *prev = NULL;

        do {
            if (t->data == key) {
                if (t == head) {
                    Node *last = head;
                    while (last->next != head) last = last->next;
                    head = head->next;
                    last->next = head;
                } else {
                    prev->next = t->next;
                }
                delete t;
                return;
            }
            prev = t;
            t = t->next;
        } while (t != head);
    }

    bool search(int key) {
        if (!head) return false;
        Node *t = head;
        do {
            if (t->data == key) return true;
            t = t->next;
        } while (t != head);
        return false;
    }

    void display() {
        if (!head) return;
        Node *t = head;
        do {
            cout << t->data << " ";
            t = t->next;
        } while (t != head);
        cout << endl;
    }
};

int main() {
    DList d;
    CList c;
    int ch, type, val, key;

    while (true) {
        cout << "\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\nChoice: ";
        cin >> ch;
        if (ch == 5) break;

        cout << "1. Doubly  2. Circular: ";
        cin >> type;

        switch (ch) {
        case 1:
            cout << "Enter value: "; cin >> val;
            cout << "1.First 2.Last 3.After 4.Before: ";
            cin >> key;
            if (type == 1) {
                if (key == 1) d.insertFirst(val);
                else if (key == 2) d.insertLast(val);
                else { cout << "Key after/before: "; cin >> key;
                       if (key == 3) d.insertAfter(key, val);
                       else d.insertBefore(key, val); }
            } else {
                if (key == 1) c.insertFirst(val);
                else if (key == 2) c.insertLast(val);
                else { cout << "Key after/before: "; cin >> key;
                       if (key == 3) c.insertAfter(key, val);
                       else c.insertBefore(key, val); }
            }
            break;

        case 2:
            cout << "Enter value to delete: "; cin >> key;
            if (type == 1) d.deleteNode(key);
            else c.deleteNode(key);
            break;

        case 3:
            cout << "Enter value to search: "; cin >> key;
            cout << ((type == 1 ? d.search(key) : c.search(key)) ? "Found" : "Not Found") << endl;
            break;

        case 4:
            if (type == 1) d.display(); else c.display();
            break;
        }
    }
}
